#include "spimcore.h"




/* ALU */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
  switch (ALUControl)
  {
      case 1: //add
         *ALUresult = A + B;
         break;
      case 2: //sub
         *ALUresult = A - B;
         break;
      case 3: //slt
         if ((signed)A < (signed)B)
            *ALUresult = 1;
         else
            *ALUresult = 0;
         break;
      case 4:   //sltu 
         if (A < B)
            *ALUresult = 1;
         else
            *ALUresult = 0;
         break;   
      case 5: //and
         *ALUresult = A & B;
         break;
      case 6: //or
         *ALUresult = A | B;
         break;

 
         break;

     
      
  }
   if (ALUresult == 0)
      *Zero = 1;
   else
      *Zero = 0;

}



/* instruction fetch */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{
   if (PC > 65535 | PC & 0x3)
      return 1;
   *instruction = Mem[PC >> 2];
   return 0;
}




/* instruction partition */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
   *op = (instruction >> 26) & 0x0000003f; 

    *r1 = (instruction >> 21) & 0x0000001f;

    *r2 = (instruction >> 16) & 0x0000001f;

    *r3 = (instruction >> 11) & 0x0000001f;

    *funct = instruction & 0x0000003f;

    *offset = instruction & 0X0000ffff;

    *jsec = instruction & 0x03ffffff;
}





/* instruction decode */
int instruction_decode(unsigned op,struct_controls *controls)
{
   //Halts unused opcode if needed
     int haltFlag = 0;
     
    switch (op)
    {
      case 0x0:
         *controls = (struct_controls){ 1, 0, 0, 0, 0, 7, 0, 0, 1 };
         break;
      case 0x8:
         *controls = (struct_controls){ 0, 0, 0, 0, 0, 0, 0, 1, 1 };
         break;
      case 0x23:
         *controls = (struct_controls){ 0, 0, 0, 1, 1, 0, 0, 1, 1 };
         break;
      case 0x2b:
         *controls = (struct_controls){ 0, 0, 0, 0, 0, 0, 1, 1, 0 };
         break;
      case 0xf:
         *controls = (struct_controls){ 0, 0, 0, 0, 0, 6, 0, 1, 1 };
         break;
      case 0x4:
         *controls = (struct_controls){ 2, 0, 1, 0, 2, 1, 0, 2, 0 };
         break;
      case 0xa:
         *controls = (struct_controls){ 0, 0, 0, 0, 0, 2, 0, 1, 1 };
         break;
      case 0xb:
         *controls = (struct_controls){ 0, 0, 0, 0, 0, 3, 0, 1, 1 };
         break;
      case 0x2:
         *controls = (struct_controls){ 2, 1, 2, 0, 2, 0, 0, 2, 0 };
         break;
         
      default:
         return 1;
    }
    return 0;
}



/* Read Register */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
   *data1 = Reg[r1];
   *data2 = Reg[r2];
}




/* Sign Extend */
void sign_extend(unsigned offset,unsigned *extended_value)
{
    
  int sign_bit;
    
  sign_bit = (offset >> 15);
    
  if (sign_bit == 1)
  {
    offset = 0xFFFF0000 | offset;   
    *extended_value = offset;
  }
    
  else if (sign_bit == 0)
  {

    offset = 0x0000ffff & offset;
    *extended_value = offset;
  } 
    
}



/* ALU operations */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

   
   switch (ALUOp)
   {
      case 0b001000:  //addi
         ALUOp = 1;
         break;
      case 0b001001:   //addiu
         ALUOp = 1;
         break;
      case 0b001010:   //slti
         ALUOp = 3;
         break;
      case 0b001011:  //sltiu
         ALUOp = 4;
         break;
      case 0b001100: //andi
         ALUOp = 5;
         break;
      case 0b001101: //ori
         ALUOp = 6;
         break;
         
      case 0b000000: //r-type
         switch(funct)
         {         
            case 0b100000: //add
               ALUOp = 1;
               break;
         
            case 0b100010: //sub
               ALUOp = 2;
               break;
   
            case 0b100100: //and
               ALUOp = 5;
               break;

            case 0b100101: //or
               ALUOp = 6;
               break;
         }
         break;
      default:
         return 1;
   }
   


   
   if (ALUSrc == 1)
      ALU(data1, extended_value, ALUOp, ALUresult, Zero);
   else if (ALUSrc == 0)
      ALU(data1, data2, funct, ALUresult, Zero);
   

   
   return 0;
}



/* Read / Write Memory */
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
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{
   if (RegWrite == 1 && MemtoReg == 1 && RegDst == 1) //Data coming from memory
      Reg[r3] = memdata;
   if (RegWrite == 1 && MemtoReg == 1 && RegDst != 1)
      Reg[r2] = memdata;
   if (RegWrite == 1 && MemtoReg == 0 && RegDst == 1) //Data coming from ALU_result
      Reg[r3] = ALUresult;
   if (RegWrite == 1 && MemtoReg == 0 && RegDst != 1)
      Reg[r2] = ALUresult;
}



/* PC update */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{
  *PC = *PC + 4;
  
  if (Jump == 1)
  {
     *PC = (*PC & 0xf0000000)| (jsec << 2);
  }
  
  
  if (Branch == 1 && Zero == 1)
  {
    *PC += (extended_value << 2);
  }
    
}

