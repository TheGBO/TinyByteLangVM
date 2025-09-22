#include "VirtualMachine.hpp"

void VirtualMachine::LoadProgramToMemory(unsigned char *program)
{
    for (size_t i = 0; i < MEM_LENGTH; i++) {
        m_Memory[i] = program[i];
    }
}

void VirtualMachine::RunProgram()
{
    size_t pc = 0;
    while (pc < MEM_LENGTH) {
        unsigned char instr = m_Memory[pc++];
        
        switch(instr) {
            case SET: {
                //first parameter
                unsigned char addr = m_Memory[pc++];
                //second parameter
                unsigned char val = m_Memory[pc++];
                m_Memory[addr] = val;
                break;
            }
            case JMP: {
                unsigned char target = m_Memory[pc++];
                pc = target;  // Jump to absolute address
                break;
            }
            case COUT: {
                unsigned char addr = m_Memory[pc++];
                std::cout << static_cast<char>(m_Memory[addr]);  // Jump to absolute address
                break;
            }
            case MOVE: {
                unsigned char addrA = m_Memory[pc++];
                unsigned char addrB = m_Memory[pc++];
                m_Memory[addrA] = m_Memory[addrB];
                break;
            }
            case INC: {
                unsigned char addr = m_Memory[pc++];
                m_Memory[addr]++;
                break;
            }
            case DEC: {
                unsigned char addr = m_Memory[pc++];
                m_Memory[addr]--;
                break;
            }
            case HALT: {
                return;
            }
            case JIE: {
                unsigned char target = m_Memory[pc++];
                unsigned char opAddr = m_Memory[pc++];
                unsigned char val = m_Memory[pc++];
                if(m_Memory[opAddr] == val){
                    pc = target;
                }
                break;
            }
            case JINE: {
                unsigned char target = m_Memory[pc++];
                unsigned char opAddr = m_Memory[pc++];
                unsigned char val = m_Memory[pc++];
                if(m_Memory[opAddr] != val){
                    pc = target;
                }
                break;
            }
        }
    }
}