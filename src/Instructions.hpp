//instructions.hpp
#pragma once
#define HALT 0x00
#define SET 0x01 // set (ADDR, Literal)
#define MOVE 0x02 // move(ADDR_A, ADDR_B) from AddrB to AddrA
#define JMP 0x04 // jmp to addr
#define INC 0x05 // inc(addr) increment value of address addr
#define DEC 0x06 // dec(addr) decrement value of address addr
#define JIE 0x07 // jie(destADDR, opADDR, literal) jump to destADDR if the value of opADDR is equals literal
#define JINE 0x08 // jine(destADDR, opADDR, literal) jump to destADDR if the value of opADDR is not equal literal
#define COUT 0X0B // cout (ADDR)