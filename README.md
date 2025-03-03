# Intro

Rhombus is a esoteric programming language inspired by Brainfuck and the [youtube video](https://www.youtube.com/watch?v=QdnxjYj1pS0) that got me into compilers in the first place. The compiler is written in pure C, and the frontend is written in JS. This is the first Compiler I've written outside of class, and the first Parser I've written in general. If you have any questions, feel free to email me at [elliotgrantmiller@gmail.com](mailto:elliotgrantmiller@gmail.com). Programs are written by reading from and writing to a 0-indexed array of 64 8 byte integers using literals and registers. There are 6 general purpose registers, along with an output register (RP) and the instruction pointer (RI). The other registers are denoted R(0-5). 

# Instructions

Rhombus programs are straightline strings with no regard for whitespace. With the exception of the shift left/right operators `<` and `>`, 
every instruction takes in either one or two values (register/literal) as arguments. Square brackets wrap around registers and literal arguments, and a single comma with no whitespace is used to separate arguments for binary operations. In the following examples, the letter **V** is used as a placeholder for an argument that can be either a literal or a register. Arguments that **must** be a literal/register are denoted **L** and **R** respectively. Note that **V**, **L**, and **R** without a trailing register identifier are not valid Rhombus syntax.

## Memory

### Write `!` 

Takes the value stored in the provided register and writes it to the the memory location at TP. 

`![V]`



### Read `^`

Takes the value at TP and writes it to the provided register.

`^[R]`

## Arithmetic 

### Add `+`
Adds arg1 and arg2 and stores the result in arg1, which must be a register.
`+[R,V]`

### Subtract `-`
Subtracts arg2 from arg1 and stores the result in arg1, which must be a register.
`-[R,V]`

### Multiply `*`
Multiplies arg1 and arg2 and stores the result in arg1, which must be a register.
`*[R,V]`

### Divide `/`
Divides arg1 by arg2 and stores the truncated result in arg1, which must be a register.
`/[R,V]`

 Division by 0 is well-defined in Rhombus, the following program would output 0, not a runtime error. 

`![#10]^[R0]/[R0,R1]![R0]^[#RP]`
</br> <sup> Registers in Rhombus are initialized to 0. </sup>


## Control Flow

### Branch `@`
Sets RI to V, jumping execution to instructions[V].<sub> see [Instruction Pointer](#instruction-pointer)</sub>

`@[V]`

### Conditional Branch `?` 
Sets RI if V2 is 1, set RI to V1.

`?[V1,V2]`

### Left Shift `<`
Shifts tape pointer left.
`<`

### Right Shift `>`
Shifts tape pointer left.
`>`

## Values

### General
A value in Rhombus is a 64 bit integer literal, or a register containing a 64 bit integer literal. Literal values are written with a # character followed by any negative or positive integer. Negative integers are written in the same fashion as any typical programming language, such as `#-5`. Registers are written with an <span class="reg"> R</span> character followed by a number 0-6, the character `I` for the instruction pointer, and the character `P` for the output (or print) register. 

### Instruction Pointer
Writing to `RI` will cause the next instruction executed to be instructions[written value].


### Output register
Writing to `RP` pushes that value to an output buffer, which is treated as a string and printed to the console.

### Final value
When program execution is finished, the value in `R0` is considered to be the result of the program.