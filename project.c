#include "spimcore.h"


/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{

}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{

}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{

}



/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{

}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
    data1 = Reg[r1];
    data2 = Reg[r2];
}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{
    
int sign_bit;
    
    sign_bit = (offset >> 15);
    
    if (sign_bit == 1)
    {
         offset = 0xFFFF0000 + offset;   
        *extended_value = offset;
    }
    
    else if (sign_bit == 0)
    {

         offset = 0x00000000 + offset;
        *extended_value = offset;
    } 
    
}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{
  unsigned address = ALUresult >> 2;
   
  if (MemWrite == 1)
    {
    if (ALUresult % 4 == 0)
      {
       Mem[address] = data2;
      }
    else
       {
       return 1;
       }
    }

   
  if (MemRead == 1) 
    {
    if (ALUresult % 4 == 0)
      {
       *memdata = Mem[address];
      }
     else
        {
        return 1;
        }
    }
   
 return 0;   
}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{
    if (RegWrite == "1" && MemtoReg == "1") //Data coming from memory
        Reg[RegDst] = memdata;
    
    if (RegWrite == "1" && MemtoReg == "0") //Data coming from ALU_result
        Reg[RegDst] = ALUresult;
}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{
  *PC = *PC + 4;
  
  if (Jump == 1)
  {
     *PC = (jsec << 2);
  }
  
  
  if (Branch == 1 && Zero == 1)
  {
     *PC = (extended_value << 2);
  }
    
}

