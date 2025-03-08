#ifndef LEXER_H
#define LEXER_H

typedef enum {
    //operators 
    write,
    read,
    add,
    sub,
    mul,
    div,
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
} Token;

#endif