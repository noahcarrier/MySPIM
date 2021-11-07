#include <stdio.h>


/*
    Dictionary
   ***************************************
   *    r2 -> 
   *    r3 -> 
   *    Reg -> register array to be read
   *    memdata -> array of some values
   *    ALUresult -> 
   *    RegWrite ->
   *    RegDst  ->
   *    MemtoReg ->
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
    
}