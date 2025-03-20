#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    //operators 
    write,
    read,
    add,
    sub,
    mul,
    divide,
    br,
    cbr,
    lshift,
    rshift,

    //values
    lit, 
    reg0,
    reg1,
    reg2,
    reg3,
    reg4,
    reg5,
    regI,
    regP,

    //other
    comma,
    lbracket,
    rbracket,
    
    //error
    unrecognized
} TokenType;

typedef struct 
{
    TokenType type;
    int literal;
} Token;

Token token_init(TokenType type) {
    return (Token){ .type = type, .literal = 0 };
}

Token lit_init(TokenType type, int literal) {
    return (Token){ .type = type, .literal = literal };
}

#endif
