#include <iostream>
#include "Instructions.hpp"
#include "VirtualMachine.hpp"

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

    
    VirtualMachine vm = VirtualMachine();
    vm.LoadProgramToMemory(alphabet);
    vm.RunProgram();
    return 0;
}