#include "util.h";
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

Token* tokens;
int tokens_len;
char* prog;
int prog_len;
int prog_pos;

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

Token eval_lit() {
    char* digits = malloc(sizeof(char)*MAXIMUM_DIGITS);
    //need to look at next character
    ++prog;
    int neg = 0;
    // if the next character after the # tag is a -, we have a negative number
    if (*prog == '-') {
        neg = 1;
        ++prog;
    }
    for(int i = 0; i < MAXIMUM_DIGITS; i++) {
        if(isdigit(*prog)) {
            *digits = *prog;
            digits++;
            prog++;
        } else {
            prog++;
            return lit_init(lit, atoi(digits));
        }
    }
    //if this for loop ends, that means we're using a number that's too large (it kept seeing digits after 20)
    error("Literal argument too large");
}

Token add_token(char c) {
    switch(c) {
        //single character tokens
        case '!': return token_init(write);
        case '^': return token_init(read);
        case '+': return token_init(add);
        case '-': return token_init(sub);
        case '*': return token_init(mul);
        case '/': return token_init(div);
        case '@': return token_init(br);
        case '?': return token_init(cbr);
        case '<': return token_init(lshift);
        case '>': return token_init(rshift);
        case ',': return token_init(comma);
        case '[': return token_init(lbracket);
        case ']': return token_init(rbracket);
        //return a reg using the next character (also increments the pointer)
        case 'R': return token_init(eval_reg(get_char()));
        case '#': return eval_lit();
    }
}

int lex(char* source_prog, Token* tokens) {
    
    if (sizeof(source_prog) == 0) {
        return 0;
    }

    prog_len = sizeof(source_prog) / sizeof(prog[0]);
    tokens_len = sizeof(Token) * prog_len;
    //create an array of tokens that is the size of the sourceprog in characters
    tokens = (Token*)malloc(tokens_len);
    // we never write to prog in here
    prog = source_prog;
    while(prog_pos < prog_len) {
        *tokens = add_token(get_char());
        tokens++;
    }
}