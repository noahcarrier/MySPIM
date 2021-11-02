/*
MySPIM Project
CDA 3103C - Computer Logic & Organization

Contributors:
Brandon Magloire
Noah Carrier
Evan Agustin Verdu
*/


#include <stdio.h>


//Global Variables for registers (excluding temporary)
int a0, a1, a2, a3;                 //Arguments      *
int s0, s1, s2, s3, s4, s5, s6, s7; //Callees        *
int zero = 0b0;                     //Zero register  *
int v0, v1;                         //Funct results  *
int gp;                             //Global pointer *
int sp;                             //Stack pointer  *
int fp;                             //Frame pointer  *
int ra;                             //Return address *
//*****************************************************

typedef struct
{
  char RegDst;
  char Jump;
  char Branch;
  char MemRead;
  char MemtoReg;
  char ALUOp;
  char MemWrite;
  char ALUSrc;
  char RegWrite;
}struct_controls;







//Initalizing functions
void printReg();             //Print all register contents
void printMem();             //Print all memory contents
void step();                 //Step forward 1 instruction
void contUntilHalt();        //Continue all instructions until halt
void checkHalt();            //Check if program has halted
int instruction_fetch(unsigned PC, unsigned *Mem, unsigned *instruction);
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1, unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec);
int instruction_decode(unsigned op, struct_controls *controls);
void read_register(unsigned r1, unsigned r2, unsigned *Reg, unsigned *data1, unsigned *data2);
void sign_extend(unsigned offset, unsigned *extended_value);
int ALU_operations(unsigned data1, unsigned data2, unsigned extended_value, unsigned funct, char ALUOp, char ALUSrc, unsigned *ALUresult, char *Zero);
int rw_memory(unsigned ALUresult, unsigned data2, char MemWrite, char MemRead, unsigned *memdata, unsigned *Mem);
void write_register(unsigned r2, unsigned r3, unsigned memdata, unsigned ALUresult, char RegWrite, char RegDst, char MemtoReg, unsigned *Reg);
void PC_update(unsigned jsec, unsigned extended_value, char Branch, char Jump, char Zero, unsigned *PC);
//*************************


//MAIN FUNCTION
int main()
{
  printf("Hello, World!");
  return 0;
}
