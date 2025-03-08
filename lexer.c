#include "util.h";
#include "lexer.h"
#include <stdio.h>

Token* tokens;
int tokens_len;
char* prog;
int prog_len;
int prog_pos;

int lex(char* source_prog, Token* tokens) {
    
    if (sizeof(source_prog) == 0) {
        return 0;
    }

    prog_len = sizeof(source_prog) / sizeof(prog[0]);
    tokens_len = sizeof(Token) * prog_len;
    //create an array of tokens that is the size of the sourceprog in characters
    tokens = (Token*)malloc(tokens_len);
}

// get the char we're that prog is pointing at and increment prog
char get_char() {
    //make sure that we're not at EOF, if we are exit
    if (prog_pos >= prog_len) {
        error("trying to access outside of the program limits.");
    }
    //access the char prog is pointing to and increment prog and the value we use to track program position
    char c = *prog;
    prog++;
    prog_pos++;
    return c;
}

Token add_token(char c) {
    switch(c) {
        //single character tokens
        case '!': return write;
        case '^': return read;
        case '+': return add;
        case '-': return sub;
        case '*': return mul;
        case '/': return div;
        case '@': return br;
        case '?': return cbr;
        case '<': return lshift;
        case '>': return rshift;
        case ',': return comma;
        case '[': return lbracket;
        case ']': return rbracket;
        //return a reg with the next character
        case 'R': return eval_reg(get_char());
    }
}