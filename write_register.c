#include <stdio.h>


/*
    Dictionary
   ***************************************
   *    r2 -> source
   *    r3 -> destination
   *    Reg -> register array to be read
   *    memdata -> data read from memory
   *    ALUresult -> ALU output
   *    RegWrite -> control to write register
   *    RegDst  ->  destination of register
   *    MemtoReg -> control indicating data from memory
   * 
   * If RegWrite == 1, and MemtoReg == 1, then data is coming from memory
   * If RegWrite == 1, and MemtoReg == 0, then data is coming from ALU_result
   * If RegWrite == 1, place write data into the register specified by RegDst
   ****************************************

*/



int main()
{
    unsigned r2, r3, memdata, ALUresult, *Reg;
    char RegWrite, RegDst, MemtoReg;
    write_register(r2, r3, memdata, ALUresult, RegWrite, RegDst, MemtoReg, *Reg);
    return 0;
}


void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{
    if (RegWrite == "1" && MemtoReg == "1") //Data coming from memory
        Reg[RegDst/4] = memdata;
    
    if (RegWrite == "1" && MemtoReg == "0") //Data coming from ALU_result
        Reg[RegDst/4] = ALUresult;
}