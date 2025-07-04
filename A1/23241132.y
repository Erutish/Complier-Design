%{
#include "symbol_info.h"
#define YYSTYPE symbol_info*

int yyparse(void);
int yylex(void);
void yyerror(char *);

extern FILE *yyin;
extern int lines;
std::ofstream outlog;

%}

%token IF ELSE FOR WHILE DO INT CHAR FLOAT DOUBLE VOID RETURN DEFAULT CONTINUE GOTO PRINTLN
%token CONST_INT CONST_FLOAT ID ADDOP MULOP INCOP RELOP ASSIGNOP LOGICOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA COLON SEMICOLON

%nonassoc THEN
%nonassoc ELSE

%%

start : program
    {
        outlog << "At line no: " << lines << " start : program " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    ;

program : program unit
    {
        outlog << "At line no: " << lines << " program : program unit " << endl << endl;
        outlog << $1->getname() + "\n" + $2->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + "\n" + $2->getname(), "program");
    }
    | unit
    {
        outlog << "At line no: " << lines << " program : unit " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    ;

unit : var_declaration
    {
        outlog << "At line no: " << lines << " unit : var_declaration " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | func_definition
    {
        outlog << "At line no: " << lines << " unit : func_definition " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    ;

func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
    {
        outlog << "At line no: " << lines << " func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement " << endl << endl;
        outlog << $1->getname() << " " << $2->getname() << "(" << $4->getname() << ")\n" << $6->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + " " + $2->getname() + "(" + $4->getname() + ")\n" + $6->getname(), "func_def");
    }
    | type_specifier ID LPAREN RPAREN compound_statement
    {
        outlog << "At line no: " << lines << " func_definition : type_specifier ID LPAREN RPAREN compound_statement " << endl << endl;
        outlog << $1->getname() << " " << $2->getname() << "()\n" << $5->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + " " + $2->getname() + "()\n" + $5->getname(), "func_def");
    }
    ;

parameter_list : parameter_list COMMA type_specifier ID
    {
        outlog << "At line no: " << lines << " parameter_list : parameter_list COMMA type_specifier ID " << endl << endl;
        outlog << $1->getname() << "," << $3->getname() << " " << $4->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + "," + $3->getname() + " " + $4->getname(), "param_list");
    }
    | parameter_list COMMA type_specifier
    {
        outlog << "At line no: " << lines << " parameter_list : parameter_list COMMA type_specifier " << endl << endl;
        outlog << $1->getname() << "," << $3->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + "," + $3->getname(), "param_list");
    }
    | type_specifier ID
    {
        outlog << "At line no: " << lines << " parameter_list : type_specifier ID " << endl << endl;
        outlog << $1->getname() << " " << $2->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + " " + $2->getname(), "param_list");
    }
    | type_specifier
    {
        outlog << "At line no: " << lines << " parameter_list : type_specifier " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    ;

compound_statement : LCURL statements RCURL
    {
        outlog << "At line no: " << lines << " compound_statement : LCURL statements RCURL " << endl << endl;
        outlog << "{\n" << $2->getname() << "\n}" << endl << endl;
        $$ = new symbol_info("{\n" + $2->getname() + "\n}", "compound_stmt");
    }
    | LCURL RCURL
    {
        outlog << "At line no: " << lines << " compound_statement : LCURL RCURL " << endl << endl;
        outlog << "{}" << endl << endl;
        $$ = new symbol_info("{}", "compound_stmt");
    }
    ;

var_declaration : type_specifier declaration_list SEMICOLON
    {
        outlog << "At line no: " << lines << " var_declaration : type_specifier declaration_list SEMICOLON " << endl << endl;
        outlog << $1->getname() << " " << $2->getname() << ";" << endl << endl;
        $$ = new symbol_info($1->getname() + " " + $2->getname() + ";", "var_decl");
    }
    ;

type_specifier : INT
    {
        outlog << "At line no: " << lines << " type_specifier : INT " << endl << endl;
        outlog << "int" << endl << endl;
        $$ = new symbol_info("int", "type");
    }
    | FLOAT
    {
        outlog << "At line no: " << lines << " type_specifier : FLOAT " << endl << endl;
        outlog << "float" << endl << endl;
        $$ = new symbol_info("float", "type");
    }
    | VOID
    {
        outlog << "At line no: " << lines << " type_specifier : VOID " << endl << endl;
        outlog << "void" << endl << endl;
        $$ = new symbol_info("void", "type");
    }
    ;

declaration_list : declaration_list COMMA ID
    {
        outlog << "At line no: " << lines << " declaration_list : declaration_list COMMA ID " << endl << endl;
        outlog << $1->getname() << "," << $3->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + "," + $3->getname(), "decl_list");
    }
    | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
    {
        outlog << "At line no: " << lines << " declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD " << endl << endl;
        outlog << $1->getname() << "," << $3->getname() << "[" << $5->getname() << "]" << endl << endl;
        $$ = new symbol_info($1->getname() + "," + $3->getname() + "[" + $5->getname() + "]", "decl_list");
    }
    | ID
    {
        outlog << "At line no: " << lines << " declaration_list : ID " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | ID LTHIRD CONST_INT RTHIRD
    {
        outlog << "At line no: " << lines << " declaration_list : ID LTHIRD CONST_INT RTHIRD " << endl << endl;
        outlog << $1->getname() << "[" << $3->getname() << "]" << endl << endl;
        $$ = new symbol_info($1->getname() + "[" + $3->getname() + "]", "decl_list");
    }
    ;

statements : statement
    {
        outlog << "At line no: " << lines << " statements : statement " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | statements statement
    {
        outlog << "At line no: " << lines << " statements : statements statement " << endl << endl;
        outlog << $1->getname() << "\n" << $2->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + "\n" + $2->getname(), "statements");
    }
    ;

statement : var_declaration
    {
        outlog << "At line no: " << lines << " statement : var_declaration " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | expression_statement
    {
        outlog << "At line no: " << lines << " statement : expression_statement " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | compound_statement
    {
        outlog << "At line no: " << lines << " statement : compound_statement " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement
    {
        outlog << "At line no: " << lines << " statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement " << endl << endl;
        outlog << "for(" << $3->getname() << " " << $4->getname() << " " << $5->getname() << ")\n" << $7->getname() << endl << endl;
        $$ = new symbol_info("for(" + $3->getname() + " " + $4->getname() + " " + $5->getname() + ")\n" + $7->getname(), "stmt");
    }
    | IF LPAREN expression RPAREN statement %prec THEN
    {
        outlog << "At line no: " << lines << " statement : IF LPAREN expression RPAREN statement " << endl << endl;
        outlog << "if(" << $3->getname() << ")\n" << $5->getname() << endl << endl;
        $$ = new symbol_info("if(" + $3->getname() + ")\n" + $5->getname(), "stmt");
    }
    | IF LPAREN expression RPAREN statement ELSE statement
    {
        outlog << "At line no: " << lines << " statement : IF LPAREN expression RPAREN statement ELSE statement " << endl << endl;
        outlog << "if(" << $3->getname() << ")\n" << $5->getname() << "\nelse\n" << $7->getname() << endl << endl;
        $$ = new symbol_info("if(" + $3->getname() + ")\n" + $5->getname() + "\nelse\n" + $7->getname(), "stmt");
    }
    | WHILE LPAREN expression RPAREN statement
    {
        outlog << "At line no: " << lines << " statement : WHILE LPAREN expression RPAREN statement " << endl << endl;
        outlog << "while(" << $3->getname() << ")\n" << $5->getname() << endl << endl;
        $$ = new symbol_info("while(" + $3->getname() + ")\n" + $5->getname(), "stmt");
    }
    | PRINTLN LPAREN ID RPAREN SEMICOLON
    {
        outlog << "At line no: " << lines << " statement : PRINTLN LPAREN ID RPAREN SEMICOLON " << endl << endl;
        outlog << "printf(" << $3->getname() << ");" << endl << endl;
        $$ = new symbol_info("printf(" + $3->getname() + ");", "stmt");
    }
    | RETURN expression SEMICOLON
    {
        outlog << "At line no: " << lines << " statement : RETURN expression SEMICOLON " << endl << endl;
        outlog << "return " << $2->getname() << ";" << endl << endl;
        $$ = new symbol_info("return " + $2->getname() + ";", "stmt");
    }
    ;

expression_statement : SEMICOLON
    {
        outlog << "At line no: " << lines << " expression_statement : SEMICOLON " << endl << endl;
        outlog << ";" << endl << endl;
        $$ = new symbol_info(";", "expr_stmt");
    }
    | expression SEMICOLON
    {
        outlog << "At line no: " << lines << " expression_statement : expression SEMICOLON " << endl << endl;
        outlog << $1->getname() << ";" << endl << endl;
        $$ = new symbol_info($1->getname() + ";", "expr_stmt");
    }
    ;

variable : ID
    {
        outlog << "At line no: " << lines << " variable : ID " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | ID LTHIRD expression RTHIRD
    {
        outlog << "At line no: " << lines << " variable : ID LTHIRD expression RTHIRD " << endl << endl;
        outlog << $1->getname() << "[" << $3->getname() << "]" << endl << endl;
        $$ = new symbol_info($1->getname() + "[" + $3->getname() + "]", "variable");
    }
    ;

expression : logic_expression
    {
        outlog << "At line no: " << lines << " expression : logic_expression " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | variable ASSIGNOP logic_expression
    {
        outlog << "At line no: " << lines << " expression : variable ASSIGNOP logic_expression " << endl << endl;
        outlog << $1->getname() << "=" << $3->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + "=" + $3->getname(), "expr");
    }
    ;

logic_expression : rel_expression
    {
        outlog << "At line no: " << lines << " logic_expression : rel_expression " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | rel_expression LOGICOP rel_expression
    {
        outlog << "At line no: " << lines << " logic_expression : rel_expression LOGICOP rel_expression " << endl << endl;
        outlog << $1->getname() << $2->getname() << $3->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + $2->getname() + $3->getname(), "logic_expr");
    }
    ;

rel_expression : simple_expression
    {
        outlog << "At line no: " << lines << " rel_expression : simple_expression " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | simple_expression RELOP simple_expression
    {
        outlog << "At line no: " << lines << " rel_expression : simple_expression RELOP simple_expression " << endl << endl;
        outlog << $1->getname() << $2->getname() << $3->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + $2->getname() + $3->getname(), "rel_expr");
    }
    ;

simple_expression : term
    {
        outlog << "At line no: " << lines << " simple_expression : term " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | simple_expression ADDOP term
    {
        outlog << "At line no: " << lines << " simple_expression : simple_expression ADDOP term " << endl << endl;
        outlog << $1->getname() << $2->getname() << $3->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + $2->getname() + $3->getname(), "simple_expr");
    }
    ;

term : unary_expression
    {
        outlog << "At line no: " << lines << " term : unary_expression " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | term MULOP unary_expression
    {
        outlog << "At line no: " << lines << " term : term MULOP unary_expression " << endl << endl;
        outlog << $1->getname() << $2->getname() << $3->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + $2->getname() + $3->getname(), "term");
    }
    ;

unary_expression : ADDOP unary_expression
    {
        outlog << "At line no: " << lines << " unary_expression : ADDOP unary_expression " << endl << endl;
        outlog << $1->getname() << $2->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + $2->getname(), "unary_expr");
    }
    | NOT unary_expression
    {
        outlog << "At line no: " << lines << " unary_expression : NOT unary_expression " << endl << endl;
        outlog << "!" << $2->getname() << endl << endl;
        $$ = new symbol_info("!" + $2->getname(), "unary_expr");
    }
    | factor
    {
        outlog << "At line no: " << lines << " unary_expression : factor " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    ;

factor : variable
    {
        outlog << "At line no: " << lines << " factor : variable " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | ID LPAREN argument_list RPAREN
    {
        outlog << "At line no: " << lines << " factor : ID LPAREN argument_list RPAREN " << endl << endl;
        outlog << $1->getname() << "(" << $3->getname() << ")" << endl << endl;
        $$ = new symbol_info($1->getname() + "(" + $3->getname() + ")", "factor");
    }
    | LPAREN expression RPAREN
    {
        outlog << "At line no: " << lines << " factor : LPAREN expression RPAREN " << endl << endl;
        outlog << "(" << $2->getname() << ")" << endl << endl;
        $$ = new symbol_info("(" + $2->getname() + ")", "factor");
    }
    | CONST_INT
    {
        outlog << "At line no: " << lines << " factor : CONST_INT " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | CONST_FLOAT
    {
        outlog << "At line no: " << lines << " factor : CONST_FLOAT " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    | variable INCOP
    {
        outlog << "At line no: " << lines << " factor : variable INCOP " << endl << endl;
        outlog << $1->getname() << $2->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + $2->getname(), "factor");
    }
    ;

argument_list : arguments
    {
        outlog << "At line no: " << lines << " argument_list : arguments " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    ;

arguments : arguments COMMA logic_expression
    {
        outlog << "At line no: " << lines << " arguments : arguments COMMA logic_expression " << endl << endl;
        outlog << $1->getname() << "," << $3->getname() << endl << endl;
        $$ = new symbol_info($1->getname() + "," + $3->getname(), "args");
    }
    | logic_expression
    {
        outlog << "At line no: " << lines << " arguments : logic_expression " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = $1;
    }
    ;

%%

void yyerror(char *s) {
    outlog << "Error at line " << lines << ": " << s << "\n\n";
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Please provide an input file\n";
        return 1;
    }
    yyin = fopen(argv[1], "r");
    outlog.open("23241132_log.txt", ios::trunc);
    
    if (yyin == NULL) {
        cout << "Couldn't open file" << endl;
        return 1;
    }
    
    yyparse();
    
    outlog << "Total lines: " << lines << endl;
    outlog.close();
    fclose(yyin);
    
    return 0;
}