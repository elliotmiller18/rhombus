<style>
    .reg { color: #CD6C5C;}
    .lit { color: #5FE792;}
    .inst { color: #5F8EE7;}
    .val { color: #E0DC75;}
    .snippet {
        background-color: #121824;
        color: white;
        padding: 10px;
        display: inline-block; /* Shrinks to fit content */
        border-radius: 5px; /* Optional rounded corners */
        letter-spacing: 2px
    }
</style>
# Intro

Rhombus is a useless esoteric programming language inspired by brainfuck and the [youtube video](https://www.youtube.com/watch?v=QdnxjYj1pS0) that got me into compilers in the first place. The compiler is written in pure C, and the frontend is written in JS. This is the first Compiler I've written outside of class, and the first Parser I've written in general. If you have any questions, feel free to email me at [elliotgrantmiller@gmail.com](mailto:elliotgrantmiller@gmail.com). Programs are written by reading from and writing to a 0-indexed array of 64 8 byte integers using literals and registers. There are 6 general purpose registers, along with an output register (RP) and the instruction pointer (RI). The other registers are denoted R(0-5). 

# Instructions

Rhombus programs are straightline strings with no regard for whitespace. With the exception of the shift left/right operators `<` and `>`, 
every instruction takes in either one or two values (register/literal) as arguments. Square brackets wrap around registers and literal arguments, and a single comma with no whitespace is used to separate arguments for binary operations. In the following examples, the underscore character _ is a wildcard character that denotes some register or literal, and the letter **V** is used as a placeholder for an argument that can be either a register or a literal. Note that V is not actual Rhombus syntax and using it will produce a compile time error.

## Memory

### Write `!` 

Takes the value stored in the provided register and writes it to the the memory location at TP. 

<div class="snippet">
    <span class="inst">!</span>[<span class="val">V_</span>]
</div>

### Read `^`

Takes the value at TP and writes it to the provided register.

<div class="snippet">
    <span class="inst">^</span>[<span class="reg">R_</span>]
</div>

## Arithmetic 

### Add `+`
Adds arg1 and arg2 and stores the result in arg1, which must be a register.
<div class="snippet">
    <span class="inst">+</span>[<span class="reg">R_</span>,<span class="val">V_</span>]
</div>

### Subtract `-`
Subtracts arg2 from arg1 and stores the result in arg1, which must be a register.
<div class="snippet">
    <span class="inst">-</span>[<span class="reg">R_</span>,<span class="val">V_</span>]
</div>

### Multiply `*`
Multiplies arg1 and arg2 and stores the result in arg1, which must be a register.
<div class="snippet">
    <span class="inst">*</span>[<span class="reg">R_</span>,<span class="val">V_</span>]
</div>

### Divide `/`
Divides arg1 by arg2 and stores the truncated result in arg1, which must be a register.
<div class="snippet">
    <span class="inst">/</span>[<span class="reg">R_</span>,<span class="val">V_</span>]
</div>

 Division by 0 is well-defined in Rhombus, the following program would output 0, not a runtime error. <div class="snippet"><span class="inst">!</span>[<span class="lit">#10</span>]<span class="inst">^</span>[<span class="reg">R0</span>]<span class="inst">/</span>[<span class="reg">R0</span>,<span class="lit">#10</span>]<span class="inst">!</span>[<span class="reg">R0</span>]<span class="inst">^</span>[<span class="reg">#RP</span>]</div>

## Control Flow

### Branch `@`
Sets <span class="reg">RI</span> to arg1, jumping execution to the character at position arg1.

<div class="snippet">
    <span class="inst">@</span>[<span class="val">V_</span>]
</div>

### Conditional Branch `?` 
Sets <span class="reg">RI</span> to arg1 if arg2 is not 0.
<div class="snippet">
    <span class="inst">?</span>[<span class="val">V_</span>,<span class="val">V_</span>]
</div>

### Left Shift `<`
Shifts tape pointer left.
<div class="snippet">
    <span class="inst"><</span>
</div>

### Right Shift `>`
Shifts tape pointer left.
<div class="snippet">
    <span class="inst">></span>
</div>

## Values

### General
A <span class="val"> value </span> in Rhombus is a 64 bit integer literal, or a register containing a 64 bit integer literal. Literal values are written with a <span class="lit"> # </span> character followed by any negative or positive integer. Negative integers are written in the same fashion as any typical programming language, for example, <span class="lit">#-5</span>. Registers are written with an <span class="reg"> R</span> character followed by a number 0-6, the character I for the instruction pointer, and the character P for the output (or print) register. 

### Instruction Pointer
Writing to <span class="reg">RI</span> will cause the next instruction executed to be instructions[written value].
would result in executing the fifth instruction (0-indexing), or printing <span class="reg">R0</span>. 

### Output register
Writing to <span class="reg">RP</span> pushes that value to an output buffer, which is treated as a string and printed to the console.

### Final value
When program execution is finished, the value in <span class="reg">R0</span> is considered to be the result of the program.