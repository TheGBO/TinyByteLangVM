#pragma once
#include <iostream>
#include "Instructions.hpp"
#define MEM_LENGTH 1024

class VirtualMachine
{
private:
    unsigned char m_Memory[MEM_LENGTH];
public:
    void LoadProgramToMemory(unsigned char* program);
    void RunProgram();
};
