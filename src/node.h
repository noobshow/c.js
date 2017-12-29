#ifndef NODE_H
#define NODE_H

typedef enum   StatementType_enum             StatementType_enum;
typedef enum   SourceElementType_enum         SourceElementType_enum;
typedef enum   ExpressionType_enum            ExpressionType_enum;
typedef enum   AssignmentOperator_enum        AssignmentOperator_enum;
typedef enum   LiteralType_enum               LiteralType_enum;

typedef union  Statement_union                Statement_union;
typedef union  SourceElement_union            SourceElement_union;
typedef union  Expression_union               Expression_union;
typedef union  Literal_union                  Literal_union;

typedef struct Program_node                   Program_node;
typedef struct SourceElements_node            SourceElements_node;
typedef struct SourceElement_node             SourceElement_node;
typedef struct FunctionDeclaration_node       FunctionDeclaration_node;
typedef struct FormalParameterList_node       FormalParameterList_node;
typedef struct Statement_node                 Statement_node;
typedef struct StatementList_node             StatementList_node;
typedef struct Block_node                     Block_node;
typedef struct Identifier_node                Identifier_node;
typedef struct VariableStatement_node         VariableStatement_node;
typedef struct VariableDeclaration_node       VariableDeclaration_node;
typedef struct VariableDeclarationList_node   VariableDeclarationList_node;
typedef struct Initializer_node               Initializer_node;
typedef struct EmptyStatement_node            EmptyStatement_node;
typedef struct ExpressionStatement_node       ExpressionStatement_node;
typedef struct Expression_node                Expression_node;
typedef struct AssignmentExpression_node      AssignmentExpression_node;
typedef struct Literal_node                   Literal_node;
typedef struct NullLiteral_node               NullLiteral_node;
typedef struct BooleanLiteral_node            BooleanLiteral_node;
typedef struct NumberLiteral_node             NumberLiteral_node;
typedef struct StringLiteral_node             StringLiteral_node;

Identifier_node*              createIdentifier(char*);
StatementList_node*           createStatementList(Statement_node*);
Block_node*                   createBlock();
Statement_node*               createStatement(StatementType_enum, void*);
FormalParameterList_node*     createFormalParameterList(Identifier_node*);
FunctionDeclaration_node*     createFunctionDeclaration(Identifier_node*, FormalParameterList_node*, Block_node*);
SourceElement_node*           createSourceElement(SourceElementType_enum, void*);
SourceElements_node*          createSourceElements(SourceElement_node*);
VariableStatement_node*       createVariableStatement();
VariableDeclaration_node*     createVariableDeclaration(Identifier_node*, Initializer_node*);
VariableDeclarationList_node* createVariableDeclarationList(VariableDeclaration_node*);
Initializer_node*             createInitializer(Expression_node*);
Program_node*                 createProgram();
EmptyStatement_node*          createEmptyStatement();
ExpressionStatement_node*     createExpressionStatement(Expression_node*);
Expression_node*              createExpression(ExpressionType_enum, void*);
AssignmentExpression_node*    createAssignmentExpression(Identifier_node* /* TODO needs to be LeftHandSideExpression_node */, AssignmentOperator_enum assignmentOperator, Expression_node*);
Literal_node*                 createLiteral(LiteralType_enum, void*);
NullLiteral_node*             createNullLiteral();
BooleanLiteral_node*          createBooleanLiteral(char);
NumberLiteral_node*           createNumberLiteral(double);
StringLiteral_node*           createStringLiteral(char*);

enum StatementType_enum {
    BLOCK_STATEMENT_TYPE,
    VARIABLE_STATEMENT_TYPE,
    EMPTY_STATEMENT_TYPE,
    EXPRESSION_STATEMENT_TYPE
};

enum SourceElementType_enum {
    STATEMENT_SOURCE_ELEMENT_TYPE,
    FUNCTION_DECLARATION_SOURCE_ELEMENT_TYPE
};

enum ExpressionType_enum {
    THIS_EXPRESSION_TYPE,
    IDENTIFIER_EXPRESSION_TYPE,
    ASSIGNMENT_EXPRESSION_TYPE,
    LITERAL_EXPRESSION_TYPE
};

enum AssignmentOperator_enum {
    EQUALS_ASSIGNMENT_OPERATOR
};

enum LiteralType_enum {
    NULL_LITERAL_TYPE,
    BOOLEAN_LITERAL_TYPE,
    NUMBER_LITERAL_TYPE,
    STRING_LITERAL_TYPE
};

union Statement_union {
    void* any;
    Block_node* block;
    VariableStatement_node* variableStatement;
    EmptyStatement_node* emptyStatement;
    ExpressionStatement_node* expressionStatement;
};

union SourceElement_union {
    void* any;
    Statement_node* statement;
    FunctionDeclaration_node* functionDeclaration;
};

union Expression_union {
    void* any;
    Identifier_node* identifier;
    Literal_node* literal;
    AssignmentExpression_node* assignmentExpression;
};

union Literal_union {
    void* any;
    NullLiteral_node* nullLiteral;
    BooleanLiteral_node* booleanLiteral;
    NumberLiteral_node* numberLiteral;
    StringLiteral_node* stringLiteral;
};

struct Identifier_node {
    char* name;
    char* (*toString)(Identifier_node*);
};

struct StatementList_node {
    int count;
    Statement_node** statements;
    void (*append)(struct StatementList_node*, Statement_node*);
    char* (*toString)(struct StatementList_node*);
};

struct Block_node {
    StatementList_node* statementList;
    char* (*toString)(struct Block_node*);
};

struct Statement_node {
    StatementType_enum type;
    Statement_union statementUnion;
    char* (*toString)(struct Statement_node*);
};

struct FormalParameterList_node {
    int count;
    Identifier_node** parameters;
    void (*append)(struct FormalParameterList_node*, Identifier_node*);
    char* (*toString)(struct FormalParameterList_node*);
};

struct FunctionDeclaration_node {
    Identifier_node* identifier;
    FormalParameterList_node* formalParameterList;
    Block_node* block;
    char* (*toString)(struct FunctionDeclaration_node*);
};

struct SourceElement_node {
    SourceElementType_enum type;
    SourceElement_union sourceElementUnion;
    char* (*toString)(struct SourceElement_node*);
};

struct SourceElements_node {
    int count;
    SourceElement_node** elements;
    void (*append)(struct SourceElements_node*, SourceElement_node*);
    char* (*toString)(struct SourceElements_node*);
};

struct Program_node {
    SourceElements_node* sourceElements;
    char* (*toString)(struct Program_node*);
};

struct VariableStatement_node {
    VariableDeclarationList_node* variableDeclarationList;
    char* (*toString)(struct VariableStatement_node*);
};

struct VariableDeclaration_node {
    Identifier_node* identifier;
    Initializer_node* initializer;
    char* (*toString)(struct VariableDeclaration_node*);
};

struct Initializer_node {
    Expression_node* expression;
    char* (*toString)(Initializer_node*);
};

struct VariableDeclarationList_node {
    int count;
    VariableDeclaration_node** variableDeclarations;
    void (*append)(struct VariableDeclarationList_node*, VariableDeclaration_node*);
    char* (*toString)(struct VariableDeclarationList_node*);
};

struct EmptyStatement_node {
    char* (*toString)(struct EmptyStatement_node*);
};

struct ExpressionStatement_node {
    Expression_node* expression;
    char* (*toString)(ExpressionStatement_node*);
};

struct Expression_node {
    ExpressionType_enum type;
    Expression_union expressionUnion;
    char* (*toString)(Expression_node*);
};

struct AssignmentExpression_node {
    Identifier_node* identifier; // TODO needs to be LeftHandSideExpression_node
    AssignmentOperator_enum assignmentOperator;
    Expression_node* expression;
    char* (*toString)(AssignmentExpression_node*);
};

struct Literal_node {
    LiteralType_enum type;
    Literal_union literalUnion;
    char* (*toString)(Literal_node*);
};

struct NullLiteral_node {
    char* (*toString)(NullLiteral_node*);
};

struct BooleanLiteral_node {
    char boolean;
    char* (*toString)(BooleanLiteral_node*);
};

struct NumberLiteral_node {
    double number;
    char* (*toString)(NumberLiteral_node*);
};

struct StringLiteral_node {
    char* string;
    char* (*toString)(StringLiteral_node*);
};

#endif