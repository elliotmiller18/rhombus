#ifndef UTIL_H
#define UTIL_H

#include "values.h"
#include "lexer.h"
#include "util.h"

Token num_to_reg(int tag) {
    switch(tag) {
        case 0: return reg0;
        case 1: return reg1;
        case 2: return reg2;
        case 3: return reg3;
        case 4: return reg4;
        case 5: return reg5;
        default: error("register tag out of bounds.");
    }
}

Token eval_reg(char c) {
    //return a register for every recognized identifier
    switch(c) {
        case 'I': return regI;
        case 'P': return regP;
        default:
            //48 is 0, 49 is 1, so on
            int converted = ((int)c)-48;
            if (converted < 0 || converted >= NUM_REGISTERS) {
                error("invalid register tag.");
            }
            return num_to_reg(converted);
    }
}

#endif
