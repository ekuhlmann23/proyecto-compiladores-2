grammar Intermediate;

/*
 * Lexer
 */
INT: 'int';
MAIN: 'main';
RETURN: 'return';
OPAREN: '(';
CPAREN: ')';
OBRACE: '{';
CBRACE: '}';
SEMICOLON: ';';
ID: [a-zA-Z_][a-zA-Z0-9_-]*; // variable names
NUM: [0-9]+;
WS : [ \t\r\n]+ -> skip; // skip spaces, tabs, newlines

/*
 * Grammar
 */
program: main EOF;
main:
    INT MAIN OPAREN CPAREN OBRACE (statements+=statement)* RETURN '0' SEMICOLON CBRACE;
declaration: INT id=ID SEMICOLON;
assignment: id=ID '=' expr=expression SEMICOLON;
statement:
    // control
    assignment
    | declaration
    ;
binary_operator: '+'
    | '-'
    | '&'
    | '|'
    ;
unary_operator: '!'
    ;

value: variable
    | constant
    ;

variable: ID;
constant: NUM;

expression: op1=value
    | op1=value binary_operator op2=value
    | unary_operator op1=value
    ;
