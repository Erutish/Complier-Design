# Detailed Technical Explanation: Compiler Implementation

## Project Overview

This project implements a comprehensive compiler front-end for a C-like programming language. The implementation follows classical compiler design principles, dividing the compilation process into distinct phases:

1. **Lexical Analysis**: Tokenizing the source code into meaningful lexical units (tokens)
2. **Syntax Analysis**: Parsing the token stream to verify grammatical correctness and build an abstract syntax representation
3. **Semantic Analysis**: Building and maintaining a symbol table to track identifiers and their properties
4. **Error Detection and Reporting**: Identifying and reporting syntax and semantic errors with meaningful messages

The project demonstrates core compiler construction concepts in a practical implementation, focusing particularly on robust symbol management across nested scopes and proper handling of language constructs like variables, arrays, functions, and control structures.

### Key Features

- **Strong Type System**: Support for basic types (int, float, void)
- **Function Handling**: Complete support for function definitions with parameters
- **Array Support**: Declaration and manipulation of array variables
- **Control Structures**: Implementation of if-else, for, and while statements
- **Nested Scopes**: Proper management of variable scope and visibility
- **Detailed Logging**: Comprehensive tracking of compilation steps and symbol information
- **Error Detection**: Identification of common programming errors

### Intended Usage

The compiler can process source files written in the supported language, perform syntactic and semantic analysis, and report any errors found. A typical command to run the compiler would be:

```bash
./compiler input_file.c
```

The compiler produces a log file (`23241131_log.txt`) containing:
- Detailed parsing steps
- Symbol table contents for each scope
- Error messages (if any)
- A summary of total lines processed

## Architecture and Design Philosophy

The compiler implements a traditional front-end architecture following these key design principles:

### 1. Separation of Concerns

Each major component has a well-defined responsibility:

- **Lexical Analyzer (Flex)**: Handles the conversion of character streams to tokens
- **Syntax Analyzer (Bison)**: Processes tokens according to grammar rules
- **Symbol Table**: Manages symbol information across different scopes
- **Error Handler**: Provides meaningful error reporting

### 2. Hierarchical Design

The system employs a hierarchical approach to:

- **Symbol Management**: Symbols are organized in nested scope tables
- **Grammar Rules**: The grammar follows a hierarchical structure from program to expressions
- **Error Handling**: Errors are propagated upward through the parsing tree

### 3. Object-Oriented Approach

Despite being implemented in C++, the design follows object-oriented principles:

- **Encapsulation**: Each class encapsulates related data and functionality
- **Information Hiding**: Internal details are hidden behind well-defined interfaces
- **Single Responsibility**: Each class has a clear, singular purpose

### 4. Extensibility

The architecture is designed to be extensible:

- **Modular Components**: Each component can be enhanced or replaced independently
- **Clear Interfaces**: Well-defined interactions between components
- **Separation of Parsing from Semantics**: Grammatical rules are separated from semantic actions

### 5. Memory Management Strategy

The system employs careful memory management:

- **Dynamic Allocation**: Symbols and scopes are dynamically allocated as needed
- **Proper Cleanup**: Resources are systematically released when no longer needed
- **Ownership Hierarchies**: Scope tables own their symbols, and the symbol table owns its scope tables

### Core Components Interaction

The components interact in the following manner:

1. **Lexer → Parser**: The lexer feeds tokens to the parser
2. **Parser → Symbol Table**: The parser creates and queries symbols
3. **Parser → Error Handler**: The parser reports syntax and semantic errors
4. **Symbol Table → Logger**: The symbol table outputs its state for debugging

This architecture enables a clean separation between the grammatical structure of the language and its semantic meaning, allowing each component to focus on its specific responsibility.

## Core Data Structures

### Symbol Information (`symbol_info.h`)

The `symbol_info` class is the fundamental building block of the symbol table system, serving as a container for all information associated with a program identifier. Each instance represents a single identifier (variable, function, array) and its associated properties.

#### Class Structure and Member Variables

```cpp
class symbol_info {
private:
    // Core identifier information
    string name;         // Identifier name (e.g., "x", "main", "calculateSum")
    string type;         // Token type (e.g., "ID", "CONST_INT", "CONST_FLOAT")
    symbol_info *next;   // Pointer for chaining in hash table collision resolution

    // Semantic information
    string data_type;    // Type of data (e.g., "int", "float", "void")
    
    // Array-related information
    bool is_array;       // Flag to indicate if this is an array
    int array_size;      // Size of array if this is an array
    
    // Function-related information
    bool is_function;    // Flag to indicate if this is a function
    string return_type;  // Return type of the function
    vector<pair<string, string>> parameters; // Parameter types and names [(type, name), ...]
};
```

#### Comprehensive Constructors

The class provides multiple constructors to handle different symbol types:

1. **Default Constructor**:
   ```cpp
   symbol_info() {
       next = NULL;
       is_array = false;
       array_size = 0;
       is_function = false;
   }
   ```
   This initializes a basic symbol with default values. It's rarely used directly but provides a baseline.

2. **Basic Constructor**:
   ```cpp
   symbol_info(string name, string type) {
       this->name = name;
       this->type = type;
       next = NULL;
       is_array = false;
       array_size = 0;
       is_function = false;
   }
   ```
   Used for tokens without additional semantic information, like operators or constants.

3. **Variable Constructor**:
   ```cpp
   symbol_info(string name, string type, string data_type) {
       this->name = name;
       this->type = type;
       this->data_type = data_type;
       next = NULL;
       is_array = false;
       array_size = 0;
       is_function = false;
   }
   ```
   Used for variable declarations, storing both the identifier and its data type.

4. **Array Constructor**:
   ```cpp
   symbol_info(string name, string type, string data_type, int array_size) {
       this->name = name;
       this->type = type;
       this->data_type = data_type;
       this->array_size = array_size;
       this->is_array = true;
       next = NULL;
       is_function = false;
   }
   ```
   Specialized for array declarations, storing the element type and array size.

5. **Function Constructor**:
   ```cpp
   symbol_info(string name, string type, string return_type, vector<pair<string, string>> params) {
       this->name = name;
       this->type = type;
       this->return_type = return_type;
       this->parameters = params;
       this->is_function = true;
       next = NULL;
       is_array = false;
       array_size = 0;
   }
   ```
   For function declarations/definitions, storing the return type and parameter information.

#### Accessor Methods

The class provides a comprehensive set of getter methods to access symbol properties:

```cpp
// Core property access
string getname() { return name; }
string gettype() { return type; }
symbol_info *getnext() { return next; }

// Semantic information access
string get_data_type() { return data_type; }

// Array property access
bool get_is_array() { return is_array; }
int get_array_size() { return array_size; }

// Function property access
bool get_is_function() { return is_function; }
string get_return_type() { return return_type; }
vector<pair<string, string>> get_parameters() { return parameters; }
```

These methods provide controlled, read-only access to symbol properties, preventing accidental modification.

#### Mutator Methods

The class also provides methods to modify symbol properties:

```cpp
// Core property modification
void setname(string name) { this->name = name; }
void settype(string type) { this->type = type; }
void setnext(symbol_info *next) { this->next = next; }

// Semantic information modification
void set_data_type(string data_type) { this->data_type = data_type; }

// Array property modification
void set_array_size(int size) {
    this->array_size = size;
    this->is_array = true;  // Setting array size automatically marks as array
}

// Function property modification
void set_as_function(string return_type, vector<pair<string, string>> params) {
    this->is_function = true;
    this->return_type = return_type;
    this->parameters = params;
}
```

These methods ensure proper encapsulation, providing controlled ways to modify symbol properties while maintaining internal consistency.

#### Memory Management

The class includes a destructor to properly clean up resources:

```cpp
~symbol_info() {
    if (next)
        delete next;  // Recursive deletion for linked symbols
}
```

This destructor is critical for preventing memory leaks, as it ensures that when a symbol is deleted, all symbols chained to it via the `next` pointer are also deleted.

#### Usage Patterns

The `symbol_info` class is used in several key patterns:

1. **Token Representation**: Basic symbols represent lexical tokens
2. **Variable Tracking**: Symbols store variable declarations with type information
3. **Array Management**: Special symbols track array declarations with size information
4. **Function Management**: Function symbols store return types and parameter lists
5. **Symbol Lookup**: Temporary symbols are created for lookup operations

#### Design Rationale

The class uses a hybrid approach that combines:

1. **General Symbol Information**: For all identifiers (name, type)
2. **Specialized Flags**: To differentiate between variables, arrays, and functions
3. **Type-Specific Data**: Additional fields relevant only to certain symbol types

This design allows efficient storage while maintaining flexibility to represent different symbol types without using inheritance, which would complicate the symbol table implementation.

### Scope Table (`scope_table.h`)

The `scope_table` class implements a single lexical scope (such as global scope, function scope, or block scope) using a hash table to efficiently store and retrieve symbols by name.

#### Design Philosophy

The scope table is designed with several key principles in mind:

1. **Fast Symbol Lookup**: Utilizes a hash table structure for O(1) average-case lookup time
2. **Collision Resolution**: Handles hash collisions using chaining with linked lists
3. **Scope Hierarchy**: Maintains parent-child relationships between nested scopes
4. **Memory Ownership**: Takes ownership of symbols inserted into the table 
5. **Detailed Reporting**: Provides comprehensive information about table contents

#### Key Components

```cpp
class scope_table {
private:
    // Structural components
    int bucket_count;                    // Number of hash buckets (fixed at creation)
    int unique_id;                       // Unique identifier for this scope
    scope_table *parent_scope;           // Pointer to the parent scope (or NULL for global scope)
    
    // Data storage
    vector<list<symbol_info *>> table;   // The actual hash table structure
    
    // Hash function
    int hash_function(string name) {     // Internal method to compute hash values
        int s = 0;
        for (char x : name) {
            s += x;
        }
        return s % bucket_count;
    }

public:
    // Constructor, destructor, and methods...
};
```

#### Core Data Structure

The heart of the `scope_table` is its hash table implementation:

```cpp
vector<list<symbol_info *>> table;
```

This is a vector of linked lists, where:
- The vector size equals `bucket_count` (fixed at scope creation)
- Each vector element is a bucket that may contain multiple symbols
- Each bucket is implemented as a linked list of `symbol_info` pointers
- Symbols that hash to the same value are chained in the corresponding bucket

This design efficiently handles hash collisions while maintaining fast lookup times.

#### Constructors and Initialization

The class provides two constructors:

1. **Default Constructor**:
   ```cpp
   scope_table() {
       bucket_count = 10;
       unique_id = 1;
       table.resize(bucket_count);
       outlog << "New ScopeTable with ID " << unique_id << " created" << endl << endl;
   }
   ```
   
   Creates a scope table with default values, primarily used for the global scope.

2. **Parameterized Constructor**:
   ```cpp
   scope_table(int bucket_count, int unique_id, scope_table *parent_scope) {
       this->bucket_count = bucket_count;
       this->unique_id = unique_id;
       this->parent_scope = parent_scope;
       table.resize(bucket_count);
       outlog << "New ScopeTable with ID " << unique_id << " created" << endl << endl;
   }
   ```
   
   Creates a scope table with specific settings, used for nested scopes.

Both constructors:
- Initialize the internal hash table with the specified bucket count
- Log the creation of the new scope table
- Set up the parent-child relationship (for nested scopes)

#### Destructor and Memory Management

```cpp
~scope_table() {
    outlog << "Scopetable with ID " << unique_id << " removed" << endl << endl;
    for (auto &bucket : table) {
        for (auto symbol : bucket) {
            delete symbol;
        }
        bucket.clear();
    }
    table.clear();
}
```

The destructor performs several critical operations:
1. Logs the removal of the scope table
2. Iterates through each bucket in the hash table
3. Deletes each symbol in every bucket, freeing memory
4. Clears all buckets and the table itself

This ensures proper cleanup of all allocated memory when a scope is exited, preventing memory leaks.

#### Hash Function Implementation

```cpp
int hash_function(string name) {
    int s = 0;
    for (char x : name) {
        s += x;
    }
    return s % bucket_count;
}
```

The hash function:
1. Computes a hash value by summing the ASCII values of all characters in the symbol name
2. Applies the modulo operation to limit the result to a valid bucket index
3. Returns an index in the range [0, bucket_count-1]

While simple, this function provides reasonable distribution for typical identifier names.

#### Symbol Operations

The class provides three key operations for symbol management:

1. **Symbol Lookup**:
   ```cpp
   symbol_info *lookup_in_scope(symbol_info *symbol) {
       int hash_val = hash_function(symbol->getname());

       for (symbol_info *current : table[hash_val]) {
           if (current->getname() == symbol->getname()) {
               return current;
           }
       }
       return NULL;
   }
   ```
   
   This method:
   - Computes the hash value for the symbol name
   - Searches the corresponding bucket for a matching symbol
   - Returns the found symbol or NULL if not found
   - Operates in O(1) average time (O(n) worst case for pathological hash collisions)

2. **Symbol Insertion**:
   ```cpp
   bool insert_in_scope(symbol_info *symbol) {
       if (lookup_in_scope(symbol) != NULL) {
           return false;  // Symbol already exists in this scope
       }

       int hash_value = hash_function(symbol->getname());
       table[hash_value].push_back(symbol);
       return true;
   }
   ```
   
   This method:
   - Checks if the symbol already exists in the current scope
   - If not, computes the hash value for the symbol name
   - Adds the symbol to the end of the corresponding bucket's linked list
   - Returns true on successful insertion, false if the symbol already exists
   - Takes ownership of the symbol pointer (the scope table is now responsible for deleting it)

3. **Symbol Deletion**:
   ```cpp
   bool delete_from_scope(symbol_info *symbol) {
       int hash_val = hash_function(symbol->getname());

       auto &bucket = table[hash_val];
       for (auto it = bucket.begin(); it != bucket.end(); ++it) {
           if ((*it)->getname() == symbol->getname()) {
               bucket.erase(it);
               return true;
           }
       }
       return false;
   }
   ```
   
   This method:
   - Computes the hash value for the symbol name
   - Searches the corresponding bucket for the symbol
   - If found, removes it from the bucket
   - Returns true on successful deletion, false if the symbol wasn't found
   - Note: This doesn't delete the symbol itself, only removes it from the table

#### Scope Navigation

```cpp
scope_table *get_parent_scope() {
    return parent_scope;
}

int get_unique_id() {
    return unique_id;
}
```

These methods provide:
- Access to the parent scope, enabling hierarchical symbol lookup
- Identification of the scope by its unique ID

#### Detailed Display

```cpp
void print_scope_table(ofstream &outlog) {
    outlog << "ScopeTable # " << unique_id << endl;
    for (int i = 0; i < bucket_count; i++) {
        if (!table[i].empty()) {
            outlog << i << " --> " << endl;
            for (auto current : table[i]) {
                outlog << "< " << current->getname() << " : " << current->gettype() << " >" << endl;

                if (current->get_is_function()) {
                    outlog << "Function Definition" << endl;
                    outlog << "Return Type: " << current->get_return_type() << endl;
                    vector<pair<string, string>> params = current->get_parameters();
                    outlog << "Number of Parameters: " << params.size() << endl;
                    outlog << "Parameter Details: ";
                    for (int j = 0; j < params.size(); j++) {
                        outlog << params[j].first << " " << params[j].second;
                        if (j < params.size() - 1)
                            outlog << ", ";
                    }
                    outlog << endl;
                }
                else if (current->get_is_array()) {
                    outlog << "Array" << endl;
                    outlog << "Type: " << current->get_data_type() << endl;
                    outlog << "Size: " << current->get_array_size() << endl;
                }
                else {
                    outlog << "Variable" << endl;
                    outlog << "Type: " << current->get_data_type() << endl;
                }
            }
        }
    }
    outlog << endl;
}
```

This method provides a comprehensive visualization of the scope table:
1. Prints the scope table's identifier
2. Iterates through each non-empty bucket
3. Displays the bucket index and all symbols in that bucket
4. For each symbol, shows:
   - Basic info (name and type)
   - Detailed type-specific information:
     - For functions: return type, parameter count, and parameter details
     - For arrays: element type and array size
     - For variables: data type

This detailed display is invaluable for debugging and understanding the symbol table's state.

#### Usage Patterns

The `scope_table` class is used in several key scenarios:

1. **Global Scope**: The first scope table created represents the global scope
2. **Function Scopes**: New scope tables are created for each function definition
3. **Block Scopes**: Nested blocks (like those in if/else or loop statements) get their own scope tables
4. **Symbol Resolution**: When an identifier is used, it's looked up in the current scope first

#### Design Rationale

The key design decisions in the `scope_table` class include:

1. **Hash Table Structure**: Chosen for its O(1) average lookup time, critical for compiler performance
2. **Linked List Collision Handling**: Simple and memory-efficient for the expected collision rate
3. **Parent-Child Relationships**: Enables nested scopes without complicating symbol lookup
4. **Symbol Ownership**: The scope table takes responsibility for freeing symbol memory
5. **Detailed Logging**: Facilitates debugging and understanding of the compilation process

This design creates a balance between performance, memory efficiency, and debuggability, all crucial aspects of a compiler implementation.

### Symbol Table (`symbol_table.h`)

The `symbol_table` class serves as the central manager for the entire scope hierarchy, providing a high-level interface for symbol operations across all scopes. It acts as a facade over the individual scope tables, hiding the complexity of scope management and providing simple operations for the parser and semantic analyzer.

#### Design Philosophy

The symbol table is designed according to several key principles:

1. **Encapsulation of Scope Management**: Hides the details of scope creation, navigation, and deletion
2. **Hierarchical Symbol Resolution**: Implements the language's scope rules for symbol visibility
3. **Single Point of Control**: Provides a unified interface for all symbol operations
4. **Memory Safety**: Ensures proper cleanup of all scopes and symbols
5. **Observability**: Allows inspection of the symbol table state for debugging

#### Key Components

```cpp
class symbol_table {
private:
    scope_table *current_scope;   // Pointer to the current active scope
    int bucket_count;             // Number of buckets for new scope tables
    int current_scope_id;         // Counter for generating unique scope IDs
    
public:
    // Constructors, destructor, and methods...
};
```

#### Constructor and Initialization

```cpp
symbol_table(int bucket_count) {
    this->bucket_count = bucket_count;
    this->current_scope_id = 1;
    current_scope = new scope_table(bucket_count, current_scope_id, NULL);
}
```

The constructor:
1. Stores the bucket count for future scope tables
2. Initializes the scope ID counter to 1
3. Creates the global (root) scope table with no parent
4. Sets the global scope as the current active scope

This establishes the foundation of the scope hierarchy with a global scope at the root.

#### Destructor and Memory Management

```cpp
~symbol_table() {
    while (current_scope != NULL) {
        scope_table *temp = current_scope;
        current_scope = current_scope->get_parent_scope();
        delete temp;
    }
}
```

The destructor performs a careful cleanup process:
1. Starts from the current scope (wherever the compiler ended)
2. Saves a pointer to the current scope
3. Moves to the parent scope
4. Deletes the saved scope
5. Repeats until all scopes are deleted

This ensures that all scope tables and their contained symbols are properly deleted, preventing memory leaks regardless of where in the scope hierarchy the compiler ends.

#### Scope Management

The class provides two critical methods for managing the scope hierarchy:

1. **Enter Scope**:
   ```cpp
   void enter_scope() {
       current_scope_id++;
       scope_table *new_scope = new scope_table(bucket_count, current_scope_id, current_scope);
       current_scope = new_scope;
   }
   ```
   
   This method:
   - Increments the scope ID counter to ensure uniqueness
   - Creates a new scope table with the current scope as its parent
   - Makes the new scope the current active scope
   - This establishes a parent-child relationship in the scope hierarchy

2. **Exit Scope**:
   ```cpp
   void exit_scope() {
       if (current_scope == NULL)
           return;

       scope_table *parent = current_scope->get_parent_scope();
       delete current_scope;
       current_scope = parent;
   }
   ```
   
   This method:
   - Gets the parent of the current scope
   - Deletes the current scope (and all symbols it contains)
   - Makes the parent scope the new current scope
   - Safely handles the case where there is no current scope
   - Prevents accidental deletion of the global scope when it's the only one left

These methods work together to manage the compiler's movement through nested lexical scopes as it parses the program.

#### Symbol Operations

The symbol table provides several key operations for symbol management:

1. **Symbol Insertion**:
   ```cpp
   bool insert(symbol_info *symbol) {
       if (current_scope == NULL)
           return false;
       return current_scope->insert_in_scope(symbol);
   }
   ```
   
   This method:
   - Delegates to the current scope's insert method
   - Inserts the symbol only in the current (innermost) scope
   - Returns true on successful insertion, false otherwise
   - Handles the edge case where there is no current scope

2. **Symbol Lookup (Global)**:
   ```cpp
   symbol_info *lookup(symbol_info *symbol) {
       scope_table *temp = current_scope;
       while (temp != NULL) {
           symbol_info *found = temp->lookup_in_scope(symbol);
           if (found != NULL) {
               return found;
           }
           temp = temp->get_parent_scope();
       }
       return NULL;
   }
   ```
   
   This method:
   - Starts the search in the current (innermost) scope
   - If the symbol is not found, moves to the parent scope
   - Continues searching up the scope hierarchy until the symbol is found or the global scope is reached
   - Returns the found symbol or NULL if not found in any scope
   - This implements the language's scope rules, where inner scopes can access symbols from outer scopes

3. **Symbol Lookup (Current Scope)**:
   ```cpp
   symbol_info *lookup_current_scope(symbol_info *symbol) {
       if (current_scope == NULL)
           return NULL;
       return current_scope->lookup_in_scope(symbol);
   }
   ```
   
   This method:
   - Searches only in the current scope, ignoring parent scopes
   - Useful for checking redeclarations within the same scope
   - Returns the found symbol or NULL if not in the current scope

#### State Inspection

The class provides methods to inspect the symbol table's state:

1. **Print Current Scope**:
   ```cpp
   void print_current_scope() {
       if (current_scope != NULL) {
           outlog << endl
                  << "################################" << endl
                  << endl;

           // Print all scopes from current to root
           scope_table *temp = current_scope;
           while (temp != NULL) {
               temp->print_scope_table(outlog);
               temp = temp->get_parent_scope();
           }

           outlog << "################################" << endl
                  << endl;
       }
   }
   ```
   
   This method:
   - Prints detailed information about the current scope hierarchy
   - Starts from the current scope and moves up to the global scope
   - Uses visual delimiters for clarity in the log

2. **Print All Scopes**:
   ```cpp
   void print_all_scopes(ofstream &outlog) {
       outlog << "Symbol Table" << endl
              << endl;
       outlog << "################################" << endl
              << endl;

       scope_table *temp = current_scope;
       while (temp != NULL) {
           temp->print_scope_table(outlog);
           temp = temp->get_parent_scope();
       }

       outlog << "################################" << endl;
   }
   ```
   
   This method:
   - Similar to print_current_scope, but with a different header
   - Primarily used at the end of compilation to show the final symbol table state

#### Helper Methods

```cpp
int get_current_scope_id() {
    return current_scope_id;
}

bool is_global_scope() {
    return current_scope != NULL && current_scope->get_parent_scope() == NULL;
}
```

These methods provide:
- Access to the current scope ID counter
- A way to check if the current scope is the global scope (has no parent)

#### Usage Patterns

The `symbol_table` class is used in several key patterns:

1. **Compilation Initialization**: Created at the start of compilation to establish the global scope
2. **Block Entry/Exit**: Used to create and destroy scopes as the parser enters and exits blocks
3. **Declaration Processing**: Used to insert symbols as declarations are parsed
4. **Identifier Resolution**: Used to look up symbols when identifiers are referenced
5. **Scope Analysis**: Used to check whether the current context is global or local

#### Implementation Notes

The implementation includes several noteworthy aspects:

1. **Delegation Pattern**: The symbol table delegates most operations to the appropriate scope table
2. **Exception Safety**: All methods handle edge cases (like NULL pointers) safely
3. **Memory Ownership**: The symbol table takes ownership of all scopes and is responsible for their cleanup
4. **Hierarchical Navigation**: Methods like lookup implement the correct scope resolution rules
5. **Detailed Logging**: Comprehensive output helps with debugging and understanding the compilation process

#### Design Rationale

The key design decisions in the `symbol_table` class include:

1. **Facade Pattern**: Provides a simple interface over the complexity of scope management
2. **Hierarchical Structure**: Reflects the nested nature of lexical scopes in the language
3. **Current Scope Tracking**: Maintains a pointer to the current scope for efficient operations
4. **Scope ID Generation**: Ensures each scope has a unique identifier for debugging
5. **Comprehensive Memory Management**: Prevents memory leaks through careful resource tracking

This design creates a clean, intuitive interface for the parser to interact with the symbol table, hiding the implementation details of scope management and symbol resolution.

## Parser Implementation (`23241131.y`)

The parser, implemented using Bison (a parser generator), is the core component that drives the compilation process. It defines the language grammar, performs syntactic analysis, and executes semantic actions to build and query the symbol table.

### Overall Structure

The Bison file (`23241131.y`) follows a standard structure:

1. **C++ Code Section**: Enclosed in `%{ ... %}`, contains includes, globals, and helper functions
2. **Bison Declarations**: Token definitions, precedence rules, and type declarations
3. **Grammar Rules**: The formal grammar with embedded semantic actions
4. **Additional C++ Code**: The main function and supporting routines

### Header Section and Global Variables

```cpp
%{
#include "symbol_table.h"
#include <cstring>

#define YYSTYPE symbol_info*

extern FILE *yyin;
int yyparse(void);
int yylex(void);
extern YYSTYPE yylval;

// Symbol table instance
symbol_table *table;

// Global variables for semantic analysis
string current_type;
string current_func_name;
string current_func_return_type;
vector<pair<string, string>> current_func_params;

// Helper flags
bool is_function_definition = false;
bool error_found = false;

int lines = 1;
ofstream outlog;

// Error reporting function
void yyerror(const char *s) {
    outlog << "Error at line " << lines << ": " << s << endl << endl;
    error_found = true;
}

// Helper functions for semantic checking
bool is_function_declared(string name) {
    symbol_info* temp = new symbol_info(name, "ID");
    symbol_info* found = table->lookup(temp);
    delete temp;
    return found != NULL && found->get_is_function();
}

bool is_variable_declared_current_scope(string name) {
    symbol_info* temp = new symbol_info(name, "ID");
    symbol_info* found = table->lookup_current_scope(temp);
    delete temp;
    return found != NULL;
}
%}
```

This section:
1. Includes necessary headers
2. Defines the semantic value type (`YYSTYPE`) as a pointer to `symbol_info`
3. Declares external functions from the lexer
4. Initializes global variables:
   - The symbol table pointer
   - Variables for tracking current context (type, function info)
   - Flag variables for tracking parser state
   - Line counter and output stream
5. Implements key helper functions:
   - `yyerror`: Reports syntax errors with line numbers
   - `is_function_declared`: Checks if a function exists in any scope
   - `is_variable_declared_current_scope`: Checks if a variable exists in the current scope

### Token and Type Declarations

```cpp
%token IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE VOID RETURN SWITCH CASE DEFAULT CONTINUE PRINTLN
%token ADDOP MULOP INCOP DECOP RELOP ASSIGNOP LOGICOP NOT
%token LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON
%token CONST_INT CONST_FLOAT ID

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
```

This section:
1. Declares all tokens used in the grammar:
   - Keywords (IF, ELSE, FOR, etc.)
   - Operators (ADDOP, MULOP, etc.)
   - Punctuation (LPAREN, RPAREN, etc.)
   - Constants and identifiers (CONST_INT, CONST_FLOAT, ID)
2. Specifies precedence rules to resolve the "dangling else" ambiguity:
   - ELSE has higher precedence than LOWER_THAN_ELSE
   - This ensures that an ELSE binds to the nearest IF

### Grammar Rules Overview

The grammar rules define the syntax of the language and specify the semantic actions to be executed when each rule is recognized. The grammar follows a top-down structure, starting from the program level and breaking down into smaller components.

#### Program Structure

```
start : program
    {
        outlog << "At line no: " << lines << " start : program " << endl << endl;
        table->print_all_scopes(outlog);
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
        $$ = new symbol_info($1->getname(), "program");
    }
    ;

unit : var_declaration
     {
        outlog << "At line no: " << lines << " unit : var_declaration " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = new symbol_info($1->getname(), "unit");
     }
     | func_definition
     {
        outlog << "At line no: " << lines << " unit : func_definition " << endl << endl;
        outlog << $1->getname() << endl << endl;
        $$ = new symbol_info($1->getname(), "unit");
     }
     ;
```

These rules define the top-level structure:
1. A program starts with the `start` non-terminal
2. A program consists of one or more `unit`s
3. A unit can be either a variable declaration or a function definition
4. Each rule has an associated semantic action that:
   - Logs the rule recognition
   - Combines the names of sub-components
   - Creates a new symbol_info to represent the combined entity

#### Variable Declarations

```
var_declaration : type_specifier declaration_list SEMICOLON
         {
            outlog << "At line no: " << lines << " var_declaration : type_specifier declaration_list SEMICOLON " << endl << endl;
            outlog << $1->getname() << " " << $2->getname() << ";" << endl << endl;
            
            $$ = new symbol_info($1->getname() + " " + $2->getname() + ";", "var_dec");
            
            // Store the current type for use in declaration_list
            current_type = $1->getname();
            
            if(current_type == "void") {
                yyerror("Variable type cannot be void");
            }
         }
         ;

type_specifier : INT
        {
            outlog << "At line no: " << lines << " type_specifier : INT " << endl << endl;
            outlog << "int" << endl << endl;
            
            $$ = new symbol_info("int", "type");
            current_type = "int";
        }
        | FLOAT
        {
            outlog << "At line no: " << lines << " type_specifier : FLOAT " << endl << endl;
            outlog << "float" << endl << endl;
            
            $$ = new symbol_info("float", "type");
            current_type = "float";
        }
        | VOID
        {
            outlog << "At line no: " << lines << " type_specifier : VOID " << endl << endl;
            outlog << "void" << endl << endl;
            
            $$ = new symbol_info("void", "type");
            current_type = "void";
        }
        ;
```

These rules handle variable types and declarations:
1. A variable declaration consists of a type specifier, a list of declarations, and a semicolon
2. Type specifiers include INT, FLOAT, and VOID
3. The semantic actions:
   - Store the current type for use in subsequent declarations
   - Check that variables aren't declared with type VOID
   - Build a combined representation of the declaration

#### Declaration List

```
declaration_list : declaration_list COMMA ID
          {
            outlog << "At line no: " << lines << " declaration_list : declaration_list COMMA ID " << endl << endl;
            outlog << $1->getname() + "," << $3->getname() << endl << endl;
            $$ = new symbol_info($1->getname() + "," + $3->getname(), "decl_list");

            // check if variable already declared in current scope
            if(is_variable_declared_current_scope($3->getname())) {
                
                $$ = new symbol_info($1->getname() + "," + $3->getname(), "decl_list");
            } else {
                // Create and insert new variable
                symbol_info* new_var = new symbol_info($3->getname(), "ID", current_type);
                table->insert(new_var);
                $$ = new symbol_info($1->getname() + "," + $3->getname(), "decl_list");
            }
          }
          | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD //array after some declaration
          {
            outlog << "At line no: " << lines << " declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD " << endl << endl;
            outlog << $1->getname() + "," << $3->getname() << "[" << $5->getname() << "]" << endl << endl;
            $$ = new symbol_info($1->getname() + "," + $3->getname() + "[" + $5->getname() + "]", "decl_list");

            // Check if array already declared in current scope
            if(is_variable_declared_current_scope($3->getname())) {
                // Silently ignore multiple declarations
                $$ = new symbol_info($1->getname() + "," + $3->getname() + "[" + $5->getname() + "]", "decl_list");
            } else {
                // Create and insert new array
                int size = stoi($5->getname());
                symbol_info* new_array = new symbol_info($3->getname(), "ID", current_type, size);
                table->insert(new_array);
                $$ = new symbol_info($1->getname() + "," + $3->getname() + "[" + $5->getname() + "]", "decl_list");
            }
          }
          |ID
          {
            outlog << "At line no: " << lines << " declaration_list : ID " << endl << endl;
            outlog << $1->getname() << endl << endl;
            $$ = new symbol_info($1->getname(), "decl_list");

            // Check if variable already declared in current scope
            if(is_variable_declared_current_scope($1->getname())) {
                // Silently ignore multiple declarations
                $$ = new symbol_info($1->getname(), "decl_list");
            } else {
                // Create and insert new variable
                symbol_info* new_var = new symbol_info($1->getname(), "ID", current_type);
                table->insert(new_var);
                $$ = new symbol_info($1->getname(), "decl_list");
            }
          }
          | ID LTHIRD CONST_INT RTHIRD //array
          {
            outlog << "At line no: " << lines << " declaration_list : ID LTHIRD CONST_INT RTHIRD " << endl << endl;
            outlog << $1->getname() << "[" << $3->getname() << "]" << endl << endl;
            $$ = new symbol_info($1->getname() + "[" + $3->getname() + "]", "decl_list");

            // Check if array already declared in current scope
            if(is_variable_declared_current_scope($1->getname())) {
                // Silently ignore multiple declarations
                $$ = new symbol_info($1->getname() + "[" + $3->getname() + "]", "decl_list");
            } else {
                // Create and insert new array
                int size = stoi($3->getname());
                symbol_info* new_array = new symbol_info($1->getname(), "ID", current_type, size);
                table->insert(new_array);
                $$ = new symbol_info($1->getname() + "[" + $3->getname() + "]", "decl_list");
            }
          }
          ;
```

These rules handle the declaration of variables and arrays:
1. A declaration list can be a single identifier, multiple comma-separated identifiers, or arrays
2. Arrays are declared with a size specified by a constant integer
3. The semantic actions:
   - Check if the variable/array is already declared in the current scope
   - Create appropriate symbol_info objects (regular variable or array)
   - Insert the symbols into the current scope
   - Build a string representation of the declaration list

#### Function Definitions

```
func_definition : type_specifier ID LPAREN parameter_list RPAREN {
            // Create and insert function symbol before compound statement
            if(!is_function_declared($2->getname())) {
                vector<pair<string, string>> params = current_func_params;
                symbol_info* func = new symbol_info($2->getname(), "ID", $1->getname());
                func->set_as_function($1->getname(), params);
                table->insert(func);
            }
        } compound_statement
        {   
            outlog << "At line no: " << lines << " func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement " << endl << endl;
            outlog << $1->getname() << " " << $2->getname() << "(" + $4->getname() + ")\n" << $7->getname() << endl << endl;
            
            $$ = new symbol_info($1->getname() + " " + $2->getname() + "(" + $4->getname() + ")\n" + $7->getname(), "func_def");   
            
            // Clear function parameters for next function
            current_func_params.clear();
        }
        | type_specifier ID LPAREN RPAREN {
            // Create and insert function symbol before compound statement
            if(!is_function_declared($2->getname())) {
                vector<pair<string, string>> params;
                symbol_info* func = new symbol_info($2->getname(), "ID", $1->getname());
                func->set_as_function($1->getname(), params);
                table->insert(func);
            }
            
        } compound_statement
        {
            outlog << "At line no: " << lines << " func_definition : type_specifier ID LPAREN RPAREN compound_statement " << endl << endl;
            outlog << $1->getname() << " " << $2->getname() << "()\n" << $6->getname() << endl << endl;
            
            $$ = new symbol_info($1->getname() + " " + $2->getname() + "()\n" + $6->getname(), "func_def");   
        }
        ;
```

These rules handle function definitions:
1. A function definition consists of a return type, identifier, parameter list, and compound statement
2. Functions can have parameters or an empty parameter list
3. The semantic actions:
   - Create a function symbol with the appropriate return type and parameters
   - Insert the function into the symbol table BEFORE processing the compound statement
   - This allows for recursive function calls within the function body
   - After processing the function, clear the parameter list for the next function

#### Parameter Lists

```
parameter_list : parameter_list COMMA type_specifier ID
        {
            outlog << "At line no: " << lines << " parameter_list : parameter_list COMMA type_specifier ID " << endl << endl;
            outlog << $1->getname() << "," << $3->getname() << " " << $4->getname() << endl << endl;
                    
            $$ = new symbol_info($1->getname() + "," + $3->getname() + " " + $4->getname(), "param_list");
            
            // Store parameter info
            pair<string, string> param($3->getname(), $4->getname());
            current_func_params.push_back(param);
        }
        | parameter_list COMMA type_specifier
        {
            outlog << "At line no: " << lines << " parameter_list : parameter_list COMMA type_specifier " << endl << endl;
            outlog << $1->getname() << "," << $3->getname() << endl << endl;
            
            $$ = new symbol_info($1->getname() + "," + $3->getname(), "param_list");
            
            // Store parameter info
            pair<string, string> param($3->getname(), "");
            current_func_params.push_back(param);
        }
        | type_specifier ID
        {
            outlog << "At line no: " << lines << " parameter_list : type_specifier ID " << endl << endl;
            outlog << $1->getname() << " " << $2->getname() << endl << endl;
            
            $$ = new symbol_info($1->getname() + " " + $2->getname(), "param_list");
            
            // Store parameter info
            pair<string, string> param($1->getname(), $2->getname());
            current_func_params.push_back(param);
        }
        | type_specifier
        {
            outlog << "At line no: " << lines << " parameter_list : type_specifier " << endl << endl;
            outlog << $1->getname() << endl << endl;
            
            $$ = new symbol_info($1->getname(), "param_list");
            
            // Store parameter info
            pair<string, string> param($1->getname(), "");
            current_func_params.push_back(param);
        }
        ;
```

These rules handle function parameters:
1. Parameters consist of a type specifier and optionally an identifier
2. Multiple parameters are separated by commas
3. The semantic actions:
   - Store each parameter as a pair of (type, name) in the `current_func_params` vector
   - This information is used when creating the function symbol
   - Parameters without names (e.g., in function prototypes) store empty name strings

#### Compound Statements and Scope Management

```
compound_statement : LCURL {
        // Enter a new scope
        table->enter_scope();
        
        // If we're in a function definition, add parameters to current scope
        if(!current_func_params.empty()) {
            for(auto param : current_func_params) {
                if(!param.second.empty()) {
                    symbol_info* param_symbol = new symbol_info(param.second, "ID", param.first);
                    table->insert(param_symbol);
                }
            }
        }
    } statements RCURL
    { 
        outlog << "At line no: " << lines << " compound_statement : LCURL statements RCURL " << endl << endl;
        outlog << "{\n" + $3->getname() + "\n}" << endl << endl;
        
        // Print current scope before exiting
        table->print_current_scope();
        
        // Exit the current scope
        table->exit_scope();
        
        $$ = new symbol_info("{\n" + $3->getname() + "\n}", "comp_stmnt");
    }
    | LCURL {
        // Enter a new scope
        table->enter_scope();
    } RCURL
    { 
        outlog << "At line no: " << lines << " compound_statement : LCURL RCURL " << endl << endl;
        outlog << "{\n}" << endl << endl;
        
        // Print current scope before exiting
        table->print_current_scope();
        
        // Exit the current scope
        table->exit_scope();
        
        $$ = new symbol_info("{\n}", "comp_stmnt");
    }
    ;
```

These rules handle compound statements (blocks) and scope management:
1. A compound statement is a block of code enclosed in curly braces
2. The block may contain statements or be empty
3. The semantic actions:
   - Enter a new scope when a block begins
   - If inside a function definition, add parameters to the new scope
   - Process the statements within the block
   - Print the scope contents for debugging
   - Exit the scope when the block ends
   - This ensures proper scoping of variables and parameters

#### Statements and Expressions

The grammar includes comprehensive rules for various statements and expressions:

1. **Statements**: Variable declarations, expressions, compound statements, control flow
2. **Expressions**: Arithmetic, logical, relational, assignment operations
3. **Variables**: Identifiers, array accesses
4. **Function Calls**: With and without arguments

Each rule has associated semantic actions that:
- Log the rule recognition
- Build string representations of the code
- Perform semantic checks where appropriate
- Create appropriate symbol_info objects

### Main Function

```cpp
int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Please input file name" << endl;
        return 0;
    }
    yyin = fopen(argv[1], "r");
    outlog.open("23241131_log.txt", ios::trunc);
    
    if(yyin == NULL) {
        cout << "Couldn't open file" << endl;
        return 0;
    }

    table = new symbol_table(10);  
    
    yyparse();
    
    delete table;
    
    outlog << endl << "Total lines: " << lines << endl;
    outlog.close();
    fclose(yyin);
    
    return 0;
}
```

The main function orchestrates the compilation process:
1. Validates command-line arguments and opens the input file
2. Opens the output log file
3. Creates the symbol table with a bucket size of 10
4. Calls `yyparse()` to start the parsing process
5. Cleans up resources when parsing completes:
   - Deletes the symbol table
   - Writes the total lines processed
   - Closes input and output files

This function serves as the entry point for the compiler, setting up the environment and initiating the compilation process.

### Key Parsing Mechanisms

The parser employs several key mechanisms:

1. **Bottom-Up Parsing**: Bison generates a bottom-up parser that recognizes patterns from the input
2. **Semantic Values**: Each grammar symbol has an associated semantic value (a symbol_info pointer)
3. **Semantic Actions**: Code blocks in curly braces execute when a rule is recognized
4. **Symbol Table Integration**: The parser interacts with the symbol table to track identifiers
5. **Error Handling**: The `yyerror` function reports syntax and semantic errors

### Design Patterns in the Parser

Several design patterns are evident in the parser implementation:

1. **Builder Pattern**: Constructing complex objects (symbol_info) piece by piece
2. **Observer Pattern**: Logging state changes and rule recognitions
3. **Strategy Pattern**: Different semantic actions for different grammar rules
4. **Factory Pattern**: Creating different types of symbols based on context

### Implementation Challenges and Solutions

The parser addresses several common challenges in compiler design:

1. **Dangling Else Problem**: Resolved using precedence declarations
2. **Scope Management**: Handled through enter_scope and exit_scope calls
3. **Symbol Resolution**: Implemented via hierarchical symbol lookup
4. **Memory Management**: Careful allocation and deletion of symbol_info objects
5. **Error Reporting**: Comprehensive error messages with line numbers

### Parser-Symbol Table Integration

The parser and symbol table work together closely:
1. The parser creates symbol_info objects
2. The symbol table stores and retrieves these objects
3. The parser queries the symbol table for semantic checks
4. The symbol table reports its state for debugging

This integration ensures that syntactic and semantic analysis work hand-in-hand to verify the correctness of the input program.

## Technical Deep Dive

### Hash Table Implementation

The compiler's symbol table uses a hash table for efficient symbol storage and retrieval. This section examines the implementation details and design considerations.

#### Data Structure

```cpp
vector<list<symbol_info *>> table;
```

This hybrid data structure combines:
1. A vector of fixed size (`bucket_count`)
2. Lists at each vector position to handle collisions

This approach offers several advantages:
- O(1) average-case lookup time
- Dynamic memory management for symbols
- Efficient handling of hash collisions
- Space efficiency for sparse symbol distributions

#### Hash Function Analysis

```cpp
int hash_function(string name) {
    int s = 0;
    for (char x : name) {
        s += x;
    }
    return s % bucket_count;
}
```

This hash function:
1. Sums the ASCII values of each character in the symbol name
2. Applies modulo to fit within the bucket count range

While simple, this approach:
- Provides reasonable distribution for typical identifiers
- Avoids expensive computations
- Works well with the expected small to medium symbol count
- Is easy to understand and maintain

For compiler symbol tables, this simple hash function is often sufficient because:
- The number of symbols per scope is typically small
- Perfect hash distribution is not critical for performance
- List-based collision handling mitigates poor distribution

#### Collision Resolution Strategy

The scope table uses **separate chaining** for collision resolution:
- Symbols that hash to the same bucket are stored in a linked list
- New symbols are added to the end of the appropriate list
- Lookup requires linear search through the list for matching names

This approach:
- Handles unlimited collisions gracefully
- Maintains constant-time insertion
- Trades some lookup performance for simplicity
- Works well when collision lists remain relatively short

#### Time Complexity Analysis

| Operation | Average Case | Worst Case |
|-----------|--------------|------------|
| Insertion | O(1)         | O(1)       |
| Lookup    | O(1)         | O(n)       |
| Deletion  | O(1)         | O(n)       |

The worst-case scenarios occur when:
- Many symbols hash to the same bucket
- The bucket count is too small relative to the number of symbols
- The hash function produces poor distribution

In practice, with a reasonable bucket count and typical programs, the average case predominates.

### Scope Hierarchy

The compiler implements lexical scoping through a hierarchical structure of scope tables. This section examines the scope management approach in detail.

#### Tree Structure

Scopes form a tree-like structure:

```
Global Scope (ID: 1)
├── Function1 Scope (ID: 2)
│   ├── Block1 Scope (ID: 4)
│   └── Block2 Scope (ID: 5)
└── Function2 Scope (ID: 3)
    └── Block3 Scope (ID: 6)
```

This hierarchy is implemented through parent pointers:

```cpp
scope_table *parent_scope;
```

Each scope table (except the global scope) has a pointer to its parent, enabling:
- Navigation up the scope hierarchy
- Hierarchical symbol lookup
- Proper cleanup when exiting scopes

#### Scope Entry and Exit

The compiler carefully manages scope transitions:

1. **Scope Entry** (when entering a new block):
   ```cpp
   void enter_scope() {
       current_scope_id++;
       scope_table *new_scope = new scope_table(bucket_count, current_scope_id, current_scope);
       current_scope = new_scope;
   }
   ```
   - Creates a new scope table
   - Sets the current scope as the parent
   - Makes the new scope the current scope

2. **Scope Exit** (when leaving a block):
   ```cpp
   void exit_scope() {
       if (current_scope == NULL)
           return;
       scope_table *parent = current_scope->get_parent_scope();
       delete current_scope;
       current_scope = parent;
   }
   ```
   - Retrieves the parent of the current scope
   - Deletes the current scope
   - Makes the parent the new current scope

This approach ensures:
- Each scope is properly nested within its parent
- Scopes are correctly entered and exited as blocks are processed
- Memory is properly managed (no leaks or dangling pointers)

#### Variable Visibility and Shadowing

The scope hierarchy implements the language's visibility rules:

1. **Symbol Lookup**:
   ```cpp
   symbol_info *lookup(symbol_info *symbol) {
       scope_table *temp = current_scope;
       while (temp != NULL) {
           symbol_info *found = temp->lookup_in_scope(symbol);
           if (found != NULL) {
               return found;
           }
           temp = temp->get_parent_scope();
       }
       return NULL;
   }
   ```
   
   This implements the standard scoping rule:
   - First check the innermost (current) scope
   - If not found, check the parent scope
   - Continue up to the global scope
   - Return NULL if not found anywhere

2. **Variable Shadowing**: When a variable in an inner scope has the same name as one in an outer scope:
   - The inner variable "shadows" the outer one
   - References to the name use the innermost declaration
   - The outer variable becomes inaccessible in the inner scope

This behavior is automatically implemented by the lookup algorithm, which returns the first match it finds, starting from the innermost scope.

#### Scope Identification and Debugging

Each scope has a unique identifier:
```cpp
int unique_id;
```

This ID:
- Is assigned sequentially (1, 2, 3, ...)
- Allows unambiguous identification of scopes in logs
- Helps track scope creation and deletion during debugging
- Provides context for error messages and symbol table dumps

### Symbol Representation

The compiler uses a flexible symbol representation system to handle different kinds of program entities. This section details how various language constructs are represented internally.

#### 1. Variables

A simple variable is represented as:
```
symbol_info {
    name: "x"
    type: "ID"
    data_type: "int"
    is_array: false
    is_function: false
}
```

This representation:
- Stores the variable name ("x")
- Indicates it's an identifier (type "ID")
- Records its data type ("int")
- Marks it as a non-array, non-function

Variables are inserted into the symbol table during declaration processing:
```cpp
symbol_info* new_var = new symbol_info($1->getname(), "ID", current_type);
table->insert(new_var);
```

#### 2. Arrays

An array is represented as:
```
symbol_info {
    name: "arr"
    type: "ID"
    data_type: "int"
    is_array: true
    array_size: 10
    is_function: false
}
```

This representation:
- Stores the array name ("arr")
- Indicates it's an identifier (type "ID")
- Records its element type ("int")
- Marks it as an array
- Stores the array size (10)

Arrays are inserted during declaration processing:
```cpp
int size = stoi($3->getname());
symbol_info* new_array = new symbol_info($1->getname(), "ID", current_type, size);
table->insert(new_array);
```

#### 3. Functions

A function is represented as:
```
symbol_info {
    name: "calculate"
    type: "ID"
    is_function: true
    return_type: "int"
    parameters: [("int", "a"), ("float", "b")]
}
```

This representation:
- Stores the function name ("calculate")
- Indicates it's an identifier (type "ID")
- Marks it as a function
- Records its return type ("int")
- Stores its parameters as pairs of (type, name)

Functions are inserted before processing their bodies:
```cpp
vector<pair<string, string>> params = current_func_params;
symbol_info* func = new symbol_info($2->getname(), "ID", $1->getname());
func->set_as_function($1->getname(), params);
table->insert(func);
```

#### 4. Constants and Operators

Constants and operators are represented simply:
```
symbol_info {
    name: "42"
    type: "CONST_INT"
}

symbol_info {
    name: "+"
    type: "ADDOP"
}
```

These representations:
- Store the literal value or operator symbol
- Indicate the token type
- Don't include additional semantic information

#### 5. Compound Constructs

For complex language constructs like expressions and statements, symbol_info objects store string representations:

```
symbol_info {
    name: "x + y * 2"
    type: "expr"
}

symbol_info {
    name: "if(x>0)\ny=1;\nelse\ny=0;"
    type: "stmnt"
}
```

These representations:
- Store the complete textual form of the construct
- Indicate its grammatical category
- Are built bottom-up during parsing

### Memory Management

The compiler implements a systematic approach to memory management, preventing leaks and ensuring proper resource cleanup. This section explains the memory management strategy in detail.

#### Allocation Patterns

Memory is allocated in several key scenarios:

1. **Symbol Creation**:
   ```cpp
   symbol_info* new_var = new symbol_info(name, type, data_type);
   ```
   Creates a new symbol dynamically.

2. **Scope Creation**:
   ```cpp
   scope_table* new_scope = new scope_table(bucket_count, id, parent);
   ```
   Creates a new scope table dynamically.

3. **Temporary Symbols**:
   ```cpp
   symbol_info* temp = new symbol_info(name, "ID");
   // Use temp for lookup
   delete temp;
   ```
   Creates and explicitly deletes temporary symbols.

#### Ownership Hierarchy

The compiler uses a clear ownership hierarchy:

1. **Scope Tables Own Symbols**: When a symbol is inserted into a scope table, the table takes ownership and is responsible for deleting it.

2. **Symbol Table Owns Scope Tables**: The symbol table is responsible for deleting all scope tables.

3. **Parser Owns Temporary Symbols**: The parser is responsible for deleting any symbols it creates that aren't inserted into the symbol table.

This hierarchy ensures that each object has a clear owner responsible for its cleanup.

#### Cleanup Mechanisms

Cleanup happens at several levels:

1. **Symbol Cleanup**: In the scope_table destructor:
   ```cpp
   ~scope_table() {
       for (auto &bucket : table) {
           for (auto symbol : bucket) {
               delete symbol;
           }
           bucket.clear();
       }
       table.clear();
   }
   ```
   Deletes all symbols in the scope table.

2. **Scope Cleanup**: In the symbol_table destructor:
   ```cpp
   ~symbol_table() {
       while (current_scope != NULL) {
           scope_table *temp = current_scope;
           current_scope = current_scope->get_parent_scope();
           delete temp;
       }
   }
   ```
   Deletes all scope tables, starting from the current scope and moving up to the global scope.

3. **Temporary Object Cleanup**: Explicit deletion after use:
   ```cpp
   symbol_info* temp = new symbol_info(name, "ID");
   // Use temp
   delete temp;
   ```

#### Memory Safety Challenges

The implementation addresses several memory safety challenges:

1. **Linked List Deletion**: The symbol_info destructor handles linked symbols:
   ```cpp
   ~symbol_info() {
       if (next)
           delete next;
   }
   ```
   This ensures that when a symbol is deleted, all chained symbols are also deleted.

2. **Orphaned Scopes**: The symbol_table tracks the current scope, ensuring no scopes are orphaned:
   ```cpp
   void exit_scope() {
       scope_table *parent = current_scope->get_parent_scope();
       delete current_scope;
       current_scope = parent;
   }
   ```

3. **Scope Hierarchy Cleanup**: The symbol_table destructor properly cleans up the entire scope hierarchy, regardless of where in the hierarchy the compiler ends:
   ```cpp
   ~symbol_table() {
       while (current_scope != NULL) {
           scope_table *temp = current_scope;
           current_scope = current_scope->get_parent_scope();
           delete temp;
       }
   }
   ```

#### Potential Memory Issues

Despite careful implementation, potential memory issues to be aware of include:

1. **Parser-Generated Symbols**: Symbols created during parsing but not inserted into the symbol table could leak if not explicitly deleted.

2. **Exception Safety**: The code doesn't use RAII or smart pointers, so an exception could potentially cause memory leaks.

3. **Deep Copy vs. Shallow Copy**: The implementation doesn't explicitly define copy constructors or assignment operators, which could lead to issues if symbols are copied.

### Implementation of Language Features

The compiler implements various language features through the interaction of the parser and symbol table. This section explains how key language features are realized.

#### 1. Variable Declaration and Usage

Variable declaration involves:
1. Recognizing the grammar pattern `type_specifier declaration_list SEMICOLON`
2. Extracting the type from `type_specifier`
3. Processing each identifier in `declaration_list`
4. Creating a symbol_info for each variable
5. Inserting each symbol into the current scope

Variable usage involves:
1. Creating a temporary symbol_info with the variable name
2. Looking up the symbol in the scope hierarchy
3. Verifying the symbol exists and is a variable
4. Using the symbol's information for type checking, etc.

#### 2. Function Definition and Calls

Function definition involves:
1. Recognizing `type_specifier ID LPAREN parameter_list RPAREN compound_statement`
2. Collecting parameter information
3. Creating a function symbol
4. Inserting the function into the current scope
5. Creating a new scope for the function body
6. Adding parameters to the function scope
7. Processing the function body
8. Exiting the function scope

Function calls involve:
1. Recognizing `ID LPAREN argument_list RPAREN`
2. Looking up the function symbol
3. Verifying it exists and is a function
4. Checking that argument types match parameter types
5. Building a representation of the function call

#### 3. Arrays

Array declaration involves:
1. Recognizing `ID LTHIRD CONST_INT RTHIRD`
2. Extracting the array size
3. Creating an array symbol with size information
4. Inserting the array into the current scope

Array usage involves:
1. Recognizing `ID LTHIRD expression RTHIRD`
2. Looking up the array symbol
3. Verifying it exists and is an array
4. Checking that the index expression is of integer type
5. Building a representation of the array access

#### 4. Control Structures

Control structures (if-else, for, while) involve:
1. Recognizing the appropriate grammar patterns
2. Processing condition expressions
3. Creating new scopes for the body statements
4. Processing the body statements
5. Exiting the scopes

The "dangling else" problem is solved through precedence declarations:
```
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
```
This ensures that an else clause is associated with the nearest if statement.

### Logging and Debugging

The compiler includes comprehensive logging to facilitate debugging and understanding of the compilation process.

#### 1. Grammar Rule Recognition

Each grammar rule includes logging:
```cpp
outlog << "At line no: " << lines << " declaration_list : ID " << endl << endl;
outlog << $1->getname() << endl << endl;
```
This logs:
- The line number
- The grammar rule recognized
- The text being processed

#### 2. Symbol Table Dumps

The symbol table is dumped at key points:
```cpp
table->print_current_scope();
```
This shows:
- The current scope hierarchy
- All symbols in each scope
- Detailed information about each symbol

#### 3. Error Reporting

Errors are reported with context:
```cpp
void yyerror(const char *s) {
    outlog << "Error at line " << lines << ": " << s << endl << endl;
    error_found = true;
}
```
This includes:
- The line number
- The error message
- Setting a flag to indicate an error was found

These logging mechanisms create a detailed record of the compilation process, aiding in debugging and understanding the compiler's behavior.

## Code Walkthrough Examples

To better understand how the compiler processes different language constructs, let's trace through several examples in detail, following the exact execution path through the code.

### Variable Declaration Walkthrough

Let's analyze how the compiler processes a simple variable declaration like `int x;`:

#### 1. Lexical Analysis

The lexer identifies three tokens:
- `INT`: The keyword "int"
- `ID`: The identifier "x"
- `SEMICOLON`: The semicolon character

#### 2. Parsing

The parser recognizes these tokens and applies the following grammar rules:

1. First, it matches `INT` to the `type_specifier` rule:
   ```
   type_specifier : INT
   {
       outlog << "At line no: " << lines << " type_specifier : INT " << endl << endl;
       outlog << "int" << endl << endl;
       
       $$ = new symbol_info("int", "type");
       current_type = "int";
   }
   ```
   This:
   - Creates a symbol_info with name "int" and type "type"
   - Sets the global `current_type` to "int"
   - Logs the rule recognition

2. Next, it matches `ID` to the `declaration_list` rule:
   ```
   declaration_list : ID
   {
       outlog << "At line no: " << lines << " declaration_list : ID " << endl << endl;
       outlog << $1->getname() << endl << endl;
       $$ = new symbol_info($1->getname(), "decl_list");

       // Check if variable already declared in current scope
       if(is_variable_declared_current_scope($1->getname())) {
           // Silently ignore multiple declarations
           $$ = new symbol_info($1->getname(), "decl_list");
       } else {
           // Create and insert new variable
           symbol_info* new_var = new symbol_info($1->getname(), "ID", current_type);
           table->insert(new_var);
           $$ = new symbol_info($1->getname(), "decl_list");
       }
   }
   ```
   This:
   - Checks if "x" is already declared in the current scope
   - If not, creates a new symbol_info for "x" with type "ID" and data_type "int"
   - Inserts the symbol into the current scope
   - Creates a symbol_info with name "x" and type "decl_list" for the parser
   - Logs the rule recognition

3. Finally, it matches `type_specifier declaration_list SEMICOLON` to the `var_declaration` rule:
   ```
   var_declaration : type_specifier declaration_list SEMICOLON
   {
       outlog << "At line no: " << lines << " var_declaration : type_specifier declaration_list SEMICOLON " << endl << endl;
       outlog << $1->getname() << " " << $2->getname() << ";" << endl << endl;
       
       $$ = new symbol_info($1->getname() + " " + $2->getname() + ";", "var_dec");
       
       // Store the current type for use in declaration_list
       current_type = $1->getname();
       
       if(current_type == "void") {
           yyerror("Variable type cannot be void");
       }
   }
   ```
   This:
   - Combines the type_specifier and declaration_list to form "int x;"
   - Creates a symbol_info with name "int x;" and type "var_dec"
   - Checks that the type isn't "void" (which would be an error)
   - Logs the rule recognition

#### 3. Symbol Table State

After processing this declaration, the symbol table contains:
- A symbol_info for "x" with:
  - name: "x"
  - type: "ID"
  - data_type: "int"
  - is_array: false
  - is_function: false

This symbol is stored in the current scope's hash table, in the bucket corresponding to the hash value of "x".

### Array Declaration Walkthrough

Now let's trace the processing of an array declaration like `int arr[10];`:

#### 1. Lexical Analysis

The lexer identifies six tokens:
- `INT`: The keyword "int"
- `ID`: The identifier "arr"
- `LTHIRD`: The left bracket "["
- `CONST_INT`: The constant "10"
- `RTHIRD`: The right bracket "]"
- `SEMICOLON`: The semicolon character

#### 2. Parsing

The parser applies the following rules:

1. It matches `INT` to the `type_specifier` rule, as before.

2. It matches `ID LTHIRD CONST_INT RTHIRD` to a different branch of the `declaration_list` rule:
   ```
   declaration_list : ID LTHIRD CONST_INT RTHIRD
   {
       outlog << "At line no: " << lines << " declaration_list : ID LTHIRD CONST_INT RTHIRD " << endl << endl;
       outlog << $1->getname() << "[" << $3->getname() << "]" << endl << endl;
       $$ = new symbol_info($1->getname() + "[" + $3->getname() + "]", "decl_list");

       // Check if array already declared in current scope
       if(is_variable_declared_current_scope($1->getname())) {
           // Silently ignore multiple declarations
           $$ = new symbol_info($1->getname() + "[" + $3->getname() + "]", "decl_list");
       } else {
           // Create and insert new array
           int size = stoi($3->getname());
           symbol_info* new_array = new symbol_info($1->getname(), "ID", current_type, size);
           table->insert(new_array);
           $$ = new symbol_info($1->getname() + "[" + $3->getname() + "]", "decl_list");
       }
   }
   ```
   This:
   - Checks if "arr" is already declared in the current scope
   - If not, converts the size "10" from string to integer
   - Creates a new array symbol with name "arr", type "ID", data_type "int", and size 10
   - Inserts the array symbol into the current scope
   - Creates a symbol_info with name "arr[10]" and type "decl_list" for the parser
   - Logs the rule recognition

3. Finally, it matches `type_specifier declaration_list SEMICOLON` to the `var_declaration` rule as before.

#### 3. Symbol Table State

After processing this declaration, the symbol table contains:
- A symbol_info for "arr" with:
  - name: "arr"
  - type: "ID"
  - data_type: "int"
  - is_array: true
  - array_size: 10
  - is_function: false

This array symbol allows the compiler to verify correct usage of the array in subsequent code.

### Function Definition Walkthrough

Let's analyze the processing of a function definition like `int max(int a, int b) { return a > b ? a : b; }`:

#### 1. Lexical Analysis

The lexer identifies many tokens, including:
- Type specifiers (`INT`)
- Identifiers (`max`, `a`, `b`)
- Punctuation (`(`, `)`, `{`, `}`, `,`, `;`)
- Keywords (`return`)

#### 2. Parsing

The parser applies many rules, but let's focus on the key steps:

1. It processes the return type (`INT`) and function name (`max`).

2. It processes the parameter list:
   ```
   parameter_list : type_specifier ID
   {
       // For first parameter "int a"
       pair<string, string> param($1->getname(), $2->getname());
       current_func_params.push_back(param);
   }
   ```
   ```
   parameter_list : parameter_list COMMA type_specifier ID
   {
       // For second parameter "int b"
       pair<string, string> param($3->getname(), $4->getname());
       current_func_params.push_back(param);
   }
   ```
   This builds `current_func_params` with [("int", "a"), ("int", "b")].

3. It creates and inserts the function symbol:
   ```
   func_definition : type_specifier ID LPAREN parameter_list RPAREN {
       // Create and insert function symbol before compound statement
       if(!is_function_declared($2->getname())) {
           vector<pair<string, string>> params = current_func_params;
           symbol_info* func = new symbol_info($2->getname(), "ID", $1->getname());
           func->set_as_function($1->getname(), params);
           table->insert(func);
       }
   } compound_statement
   {   
       outlog << "At line no: " << lines << " func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement " << endl << endl;
       outlog << $1->getname() << " " << $2->getname() << "(" + $4->getname() + ")\n" << $7->getname() << endl << endl;
       
       $$ = new symbol_info($1->getname() + " " + $2->getname() + "(" + $4->getname() + ")\n" + $7->getname(), "func_def");   
       
       // Clear function parameters for next function
       current_func_params.clear();
   }
   ```
   This:
   - Creates a function symbol for "max" with return type "int" and the parameter list
   - Inserts the function into the current scope
   - Creates a new scope for the function body
   - Adds parameters to the function scope

4. Before processing the function body, it enters a new scope and adds the parameters:
   ```
   compound_statement : LCURL {
       // Enter a new scope
       table->enter_scope();
       
       // If we're in a function definition, add parameters to current scope
       if(!current_func_params.empty()) {
           for(auto param : current_func_params) {
               if(!param.second.empty()) {
                   symbol_info* param_symbol = new symbol_info(param.second, "ID", param.first);
                   table->insert(param_symbol);
               }
           }
       }
   } statements RCURL
   { 
       // Print current scope before exiting
       table->print_current_scope();
       
       // Exit the current scope
       table->exit_scope();
       
       $$ = new symbol_info("{\n" + $3->getname() + "\n}", "comp_stmnt");
   }
   ```
   This:
   - Creates a new scope for the function body
   - Adds parameters to the new scope
   - Processes the body statements
   - Exits the function scope

5. Finally, it creates a complete representation of the function definition:
   ```
   } compound_statement
   {   
       outlog << "At line no: " << lines << " func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement " << endl << endl;
       outlog << $1->getname() << " " << $2->getname() << "(" + $4->getname() + ")\n" << $7->getname() << endl << endl;
       
       $$ = new symbol_info($1->getname() + " " + $2->getname() + "(" + $4->getname() + ")\n" + $7->getname(), "func_def");   
       
       // Clear function parameters for next function
       current_func_params.clear();
   }
   ```
   This:
   - Combines all components into a complete function definition
   - Clears the parameter list for the next function

#### 3. Symbol Table State

After processing this function definition, the symbol table contains:
- In the outer scope:
  - A function symbol for "max" with:
    - name: "max"
    - type: "ID"
    - return_type: "int"
    - is_function: true
    - parameters: [("int", "a"), ("int", "b")]

The function body scope has been deleted, but during its existence it contained:
- A variable symbol for "a" with data_type "int"
- A variable symbol for "b" with data_type "int"

### Control Structure Walkthrough

Let's trace the processing of an if-else statement like `if (x > 0) { y = 1; } else { y = 0; }`:

#### 1. Lexical Analysis

The lexer identifies tokens including:
- Keywords (`IF`, `ELSE`)
- Punctuation (`(`, `)`, `{`, `}`, `;`)
- Identifiers (`x`, `y`)
- Constants (`0`, `1`)
- Operators (`>`, `=`)

#### 2. Parsing

The parser applies the following key rules:

1. It processes the condition expression `x > 0`:
   - Looks up the symbol for "x"
   - Verifies it's a valid variable
   - Builds a representation of the relational expression

2. It processes the "then" block `{ y = 1; }`:
   - Enters a new scope
   - Processes the assignment statement
   - Exits the scope

3. It processes the "else" block `{ y = 0; }`:
   - Enters a new scope
   - Processes the assignment statement
   - Exits the scope

4. It combines everything into a complete if-else statement:
   ```
   IF LPAREN expression RPAREN statement ELSE statement
   {
       outlog << "At line no: " << lines << " statement : IF LPAREN expression RPAREN statement ELSE statement " << endl << endl;
       outlog << "if(" << $3->getname() << ")\n" << $5->getname() << "\nelse\n" << $7->getname() << endl << endl;
       
       $$ = new symbol_info("if(" + $3->getname() + ")\n" + $5->getname() + "\nelse\n" + $7->getname(), "stmnt");
   }
   ```
   This creates a string representation of the entire if-else statement.

#### 3. Scope Management

During processing of this statement:
1. Two temporary scopes are created (for the "then" and "else" blocks)
2. Each scope may contain its own local variables
3. Both scopes are deleted after processing
4. The symbol table returns to the original scope

This demonstrates how the compiler manages nested scopes in control structures.

### Function Call Walkthrough

Finally, let's trace the processing of a function call like `max(x, y)`:

#### 1. Lexical Analysis

The lexer identifies tokens:
- `ID`: The identifier "max"
- `LPAREN`: The left parenthesis
- `ID`: The identifier "x"
- `COMMA`: The comma character
- `ID`: The identifier "y"
- `RPAREN`: The right parenthesis

#### 2. Parsing

The parser applies these key rules:

1. It processes the arguments `x, y`:
   ```
   arguments : logic_expression
   {
       // For argument "x"
   }
   ```
   ```
   arguments : arguments COMMA logic_expression
   {
       // For argument "y"
       outlog << "At line no: " << lines << " arguments : arguments COMMA logic_expression " << endl << endl;
       outlog << $1->getname() << "," << $3->getname() << endl << endl;
               
       $$ = new symbol_info($1->getname() + "," + $3->getname(), "arg");
   }
   ```
   This builds a representation of the argument list "x,y".

2. It processes the complete function call:
   ```
   factor : ID LPAREN argument_list RPAREN
   {
       outlog << "At line no: " << lines << " factor : ID LPAREN argument_list RPAREN " << endl << endl;
       outlog << $1->getname() << "(" << $3->getname() << ")" << endl << endl;

       $$ = new symbol_info($1->getname() + "(" + $3->getname() + ")", "fctr");
   }
   ```
   This:
   - Creates a symbol_info with name "max(x,y)" and type "fctr"
   - Logs the rule recognition

3. For a complete semantic analysis, the compiler would also:
   - Look up the function symbol for "max"
   - Verify it exists and is a function
   - Check that argument types match parameter types
   - Determine the return type of the call

#### 3. Key Steps

The key steps in processing a function call are:
1. Identifying the function name
2. Processing each argument expression
3. Building a representation of the complete call
4. Verifying the call is valid (correct function name and compatible arguments)

This walkthrough shows how the compiler processes various language constructs by applying grammar rules, managing the symbol table, and building representations of code elements.

## Advanced Compiler Concepts

The compiler implementation demonstrates several advanced concepts in compiler design, which deserve additional attention.

### Recursive Descent Parsing

While Bison generates a bottom-up LALR(1) parser, the grammar itself follows a recursive descent structure, where each non-terminal corresponds to a specific language construct:

- `program` → `unit` → `var_declaration`/`func_definition`
- `expression` → `logic_expression` → `rel_expression` → `simple_expression` → `term` → `unary_expression` → `factor`

This hierarchical structure:
1. Mirrors the natural structure of programming languages
2. Makes the grammar easier to understand and maintain
3. Enables clear semantic actions at each level
4. Allows for precise error reporting

### Attribute Grammars

The compiler uses an attribute grammar approach, where:
1. Each grammar symbol has attributes (the fields of symbol_info)
2. Semantic actions compute attribute values
3. Information flows up and down the parse tree

For example, in variable declarations:
- Type information flows down from type_specifier to declaration_list
- Name information flows up from ID to declaration_list
- Combined information is used to create and insert symbols

### Symbol Table Design Tradeoffs

The symbol table implementation involves several design tradeoffs:

1. **Hash Table vs. Tree**: Using a hash table provides O(1) average lookup, but lacks the ordered traversal of a tree-based structure.

2. **Scope Hierarchy Design**: Using parent pointers creates a simple navigation model but makes it harder to support certain advanced features like forward declarations.

3. **Memory Management**: Manual memory management is more complex but potentially more efficient than using smart pointers or garbage collection.

4. **Symbol Representation**: Using a single class with flags for different symbol types is simpler than a class hierarchy but less extensible.

These tradeoffs reflect a balance between simplicity, performance, and functionality.

### Incremental vs. Batch Processing

The compiler uses a batch processing model:
1. The entire source file is processed in one pass
2. The complete symbol table is built during parsing
3. All errors are collected and reported at the end

An alternative would be incremental processing, where:
1. The compiler processes code as it's written
2. The symbol table is updated incrementally
3. Errors are reported immediately

The batch approach is simpler to implement but less interactive.

### Error Recovery and Reporting

The compiler's error handling is basic:
1. Errors are reported with line numbers
2. A global error flag is set
3. No sophisticated error recovery is implemented

More advanced compilers implement error recovery techniques:
1. **Panic Mode**: Skip ahead to a synchronization point after an error
2. **Phrase-Level Recovery**: Replace or insert tokens to correct simple errors
3. **Error Productions**: Include common errors directly in the grammar
4. **Context-Based Correction**: Suggest fixes based on context

These techniques allow a compiler to continue processing after errors, potentially finding more issues in a single pass.

## Limitations and Future Enhancements

While the compiler implementation is functional and demonstrates core concepts, it has several limitations that could be addressed in future enhancements.

### 1. Type Checking and Type Safety

The current implementation has basic type tracking but lacks comprehensive type checking:

**Current Limitations**:
- No verification that operands of arithmetic operations have compatible types
- No checking for type compatibility in assignments
- No verification that array indices are integers
- No type checking for function arguments

**Potential Enhancements**:
- Implement a type system with type compatibility rules
- Add type checking for all operations and assignments
- Support implicit type conversions where appropriate
- Add explicit type casting operators

### 2. Error Recovery

The current error handling is minimal:

**Current Limitations**:
- Parser stops at the first syntax error
- No recovery mechanisms to continue parsing
- Limited semantic error detection

**Potential Enhancements**:
- Implement error recovery to continue parsing after errors
- Add more detailed error messages with context
- Provide suggestions for fixing common errors
- Implement multiple error reporting in a single pass

### 3. Code Generation

The compiler is currently a front-end only:

**Current Limitations**:
- No intermediate code generation
- No target code generation
- No optimization

**Potential Enhancements**:
- Add an intermediate representation (like three-address code)
- Implement basic optimizations (constant folding, dead code elimination)
- Generate assembly or machine code for a target platform
- Add a runtime system for executing the compiled code

### 4. Language Features

The language supported is fairly basic:

**Current Limitations**:
- Limited data types (int, float, void)
- No structs or classes
- No pointers or references
- Limited control structures

**Potential Enhancements**:
- Add support for more data types (char, string, boolean)
- Implement user-defined types (structs, classes)
- Add pointers and dynamic memory allocation
- Support more control structures (switch, do-while)

### 5. Symbol Table Enhancements

The symbol table could be enhanced:

**Current Limitations**:
- No support for forward declarations
- Limited semantic information stored
- No distinction between declaration and definition

**Potential Enhancements**:
- Add support for forward declarations and separate compilation
- Store more semantic information (const-ness, visibility, etc.)
- Distinguish between declaration and definition
- Implement more efficient symbol table algorithms

### 6. Optimization

No optimization is currently performed:

**Potential Enhancements**:
- Implement common subexpression elimination
- Add constant folding and propagation
- Perform dead code elimination
- Implement loop optimizations
- Add function inlining

### 7. Better Memory Management

Memory management could be improved:

**Current Limitations**:
- Manual memory management prone to leaks
- No exception safety

**Potential Enhancements**:
- Use smart pointers for automatic memory management
- Implement RAII principles
- Add exception safety
- Use move semantics for better performance

## Conclusion

This compiler implementation demonstrates fundamental concepts in compiler design, from lexical analysis through parsing to symbol table management. It provides a solid foundation for understanding how compilers work. Let's summarize the key takeaways and learning points.

### Key Components and Their Roles

The compiler consists of several integral components:

1. **Lexical Analyzer (Implied)**: Breaks the source code into tokens, the basic units of syntax.

2. **Parser (23241131.y)**: Analyzes the grammatical structure of the code and builds representations of program constructs.

3. **Symbol Table (symbol_table.h)**: Manages information about identifiers across multiple scopes.

4. **Scope Table (scope_table.h)**: Implements individual scopes using hash tables for efficient symbol lookup.

5. **Symbol Information (symbol_info.h)**: Represents the properties of individual symbols in the program.

These components work together to analyze the source code, track program entities, and detect errors.

### Design Principles Demonstrated

The implementation illustrates several important design principles:

1. **Separation of Concerns**: Each component has a specific, well-defined responsibility.

2. **Layered Architecture**: The system is organized in layers, with higher layers building on lower ones.

3. **Information Hiding**: Implementation details are encapsulated within classes.

4. **Single Responsibility**: Each class and function has a clear, singular purpose.

5. **Clear Interfaces**: Components interact through well-defined interfaces.

These principles make the code more maintainable, understandable, and extensible.

### Educational Value

This compiler serves as an excellent educational tool for several reasons:

1. **Concrete Implementation**: It provides a working example of theoretical compiler concepts.

2. **Manageable Complexity**: It's complex enough to be realistic but simple enough to understand.

3. **Clear Structure**: The modular design makes it easy to trace the compilation process.

4. **Comprehensive Logging**: Detailed logs help visualize what happens during compilation.

5. **Foundation for Extensions**: It provides a base for implementing more advanced features.

Students and developers can learn by studying the code, tracing its execution, and extending its functionality.

### Practical Applications

While primarily educational, the concepts demonstrated have practical applications:

1. **Domain-Specific Languages**: The techniques can be applied to create custom languages for specific domains.

2. **Code Analysis Tools**: The symbol table and parsing approaches can be used in static analysis tools.

3. **Interpreter Development**: Many concepts transfer directly to interpreter implementation.

4. **Language Processing**: The techniques apply to any language processing tool, not just compilers.

Understanding these concepts is valuable for any developer working with language tools or complex code analysis.

### Final Thoughts

This compiler implementation successfully demonstrates the core concepts of compiler design, from lexical analysis through parsing to symbol table management. It provides a solid foundation for understanding how compilers work. The careful balance between simplicity and functionality makes it an excellent learning tool, showing the essential components and techniques without overwhelming complexity. By studying this implementation, one can gain a deeper understanding of both the theoretical and practical aspects of compiler design.

The modular structure and clear documentation make it accessible for study and extension, providing opportunities for hands-on learning and experimentation with more advanced compiler features. This makes it not just a demonstration of compiler principles, but a springboard for further exploration in language implementation and processing.