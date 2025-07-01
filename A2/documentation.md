# Compiler Implementation Documentation

## Overview
This codebase implements a compiler front-end that includes lexical analysis, syntax analysis, and symbol table management. The implementation is written in C++ and uses Flex/Bison for parsing.

## Core Components

### 1. Symbol Table Management
The symbol table implementation consists of three main classes:

#### `symbol_info` Class (`symbol_info.h`)
- **Purpose**: Represents individual symbols in the symbol table
- **Key Features**:
  - Stores symbol name and type
  - Supports different kinds of symbols:
    - Variables
    - Arrays (with size information)
    - Functions (with return type and parameters)
  - Maintains linked list structure for symbol chaining

#### `scope_table` Class (`scope_table.h`)
- **Purpose**: Manages symbols within a single scope
- **Key Features**:
  - Hash table implementation for symbol storage
  - Supports operations:
    - Symbol insertion
    - Symbol lookup
    - Symbol deletion
  - Maintains parent-child scope relationships
  - Hash function for symbol distribution
  - Pretty printing of scope contents

#### `symbol_table` Class (`symbol_table.h`)
- **Purpose**: Manages the hierarchy of scope tables
- **Key Features**:
  - Maintains current scope and scope hierarchy
  - Supports scope operations:
    - Enter new scope
    - Exit current scope
  - Global symbol lookup across all scopes
  - Current scope symbol lookup
  - Scope printing functionality

### 2. Parser Implementation (`23241131.y`)
The parser is implemented using Bison and handles:

#### Grammar Rules
- Variable declarations
- Function definitions
- Expressions
- Control statements
- Array operations
- Function calls

#### Key Features
- Type checking
- Symbol table management during parsing
- Error reporting
- Scope management
- Function parameter handling

## Implementation Details

### Symbol Table Operations

1. **Symbol Insertion**
   - Checks for symbol existence in current scope
   - Handles different symbol types (variables, arrays, functions)
   - Maintains scope integrity

2. **Scope Management**
   - Creates new scopes for compound statements
   - Manages function parameter scopes
   - Handles nested block scopes

3. **Symbol Lookup**
   - Current scope lookup
   - Global scope lookup
   - Hierarchical scope traversal

### Error Handling
- Syntax error reporting
- Type mismatch detection
- Symbol redeclaration checks
- Undefined symbol usage detection

### Memory Management
- Proper cleanup of symbol tables
- Scope table deletion
- Symbol information cleanup

## Usage

### Symbol Table Creation
```cpp
symbol_table* table = new symbol_table(bucket_size);
```

### Symbol Management
```cpp
// Insert a symbol
symbol_info* symbol = new symbol_info(name, type);
table->insert(symbol);

// Lookup a symbol
symbol_info* found = table->lookup(symbol);

// Enter a new scope
table->enter_scope();

// Exit current scope
table->exit_scope();
```

## File Structure

1. `symbol_info.h`
   - Symbol information class definition
   - Symbol attributes and operations

2. `scope_table.h`
   - Scope table implementation
   - Hash table operations
   - Scope management functions

3. `symbol_table.h`
   - Symbol table hierarchy management
   - Scope operations
   - Symbol lookup and insertion

4. `23241131.y`
   - Bison parser implementation
   - Grammar rules
   - Semantic actions

## Notes

1. **Hash Function**
   - Simple but effective hash implementation
   - Modulo-based distribution
   - Suitable for identifier-based symbols

2. **Scope Management**
   - Hierarchical scope structure
   - Proper parent-child relationships
   - Automatic scope cleanup

3. **Memory Considerations**
   - Proper deletion of symbols
   - Scope table cleanup
   - Prevention of memory leaks

## Best Practices

1. **Symbol Table Usage**
   - Always check for symbol existence before insertion
   - Maintain proper scope hierarchy
   - Clean up resources properly

2. **Error Handling**
   - Implement comprehensive error checking
   - Provide meaningful error messages
   - Track line numbers for error reporting

3. **Code Organization**
   - Maintain clear separation of concerns
   - Use proper encapsulation
   - Follow consistent naming conventions 