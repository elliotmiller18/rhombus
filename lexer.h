#ifndef LEXER_H
#define LEXER_H

#include "token.h"

//takes a source program and a token array, modifies the array in place and returns the length of the array
int lex(char* source_prog, Token* tokens);

#endif