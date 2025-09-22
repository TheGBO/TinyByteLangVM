#include <iostream>
#define MEM_LENGTH 1024

// Data section
unsigned char memory[MEM_LENGTH];

#define HALT 0x00
#define SET 0x01 // set (ADDR, Literal)
#define MOVE 0x02 // move(ADDR_A, ADDR_B) from AddrB to AddrA
#define JMP 0x04 // jmp to addr
#define INC 0x05 // inc(addr) increment value of address addr
#define DEC 0x06 // dec(addr) decrement value of address addr
#define JIE 0x07 // jie(destADDR, opADDR, literal) jump to destADDR if the value of opADDR is equals literal
#define JINE 0x08 // jine(destADDR, opADDR, literal) jump to destADDR if the value of opADDR is not equal literal
#define COUT 0X0B // cout (ADDR)

// Instruction section

void LoadProgramToMemory(unsigned char* program)
{
    for (size_t i = 0; i < MEM_LENGTH; i++) {
        memory[i] = program[i];
    }
}

void RunProgram()
{
    //program counter
    size_t pc = 0;
    while (pc < MEM_LENGTH) {
        unsigned char instr = memory[pc++];
        
        switch(instr) {
            case SET: {
                //first parameter
                unsigned char addr = memory[pc++];
                //second parameter
                unsigned char val = memory[pc++];
                memory[addr] = val;
                break;
            }
            case JMP: {
                unsigned char target = memory[pc++];
                pc = target;  // Jump to absolute address
                break;
            }
            case COUT: {
                unsigned char addr = memory[pc++];
                std::cout << static_cast<char>(memory[addr]);  // Jump to absolute address
                break;
            }
            case MOVE: {
                unsigned char addrA = memory[pc++];
                unsigned char addrB = memory[pc++];
                memory[addrA] = memory[addrB];
                break;
            }
            case INC: {
                unsigned char addr = memory[pc++];
                memory[addr]++;
                break;
            }
            case DEC: {
                unsigned char addr = memory[pc++];
                memory[addr]--;
                break;
            }
            case HALT: {
                return;
            }
            case JIE: {
                unsigned char target = memory[pc++];
                unsigned char opAddr = memory[pc++];
                unsigned char val = memory[pc++];
                if(memory[opAddr] == val){
                    pc = target;
                }
                break;
            }
            case JINE: {
                unsigned char target = memory[pc++];
                unsigned char opAddr = memory[pc++];
                unsigned char val = memory[pc++];
                if(memory[opAddr] != val){
                    pc = target;
                }
                break;
            }
        }
    }
}

int main()
{
    unsigned char helloProg[MEM_LENGTH]
    {
        SET, 0XFF, 'H',
        COUT, 0xFF,
        SET, 0xFF, 'e',
        COUT, 0xFF,
        SET, 0xFF, 'l',
        COUT, 0xFF, 
        COUT, 0xFF,
        SET, 0xFF, 'o',
        COUT, 0xFF,
        SET, 0xFF, '.',
        COUT, 0xFF,
        SET, 0xFF, '\n',
        COUT, 0xFF,
        HALT  
    };

    unsigned char alphabet[MEM_LENGTH]
    {
        SET, 0xFF, 'A',
        COUT, 0xFF,
        INC, 0xFF,
        JINE, 0x01, 0xFF, 'Z'+1,
        SET, 0xFF, '\n',
        COUT, 0xFF,
        HALT
    };
    LoadProgramToMemory(alphabet);
    RunProgram();
    LoadProgramToMemory(helloProg);
    RunProgram();
    return 0;
}