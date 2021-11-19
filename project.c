#include "spimcore.h"




/* ALU */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
  switch (ALUControl)
  {
      case 0b000:
         ALUresult = A + B;
         break;
      case 0b001:
         ALUresult = A - B;
         break;
      case 0b010:
         if (A < B)
            ALUresult = 1;
         else
            ALUresult = 0;
         break;
      case 0b011:
         if (A < B)
            ALUresult = 1;
         else
            ALUresult = 0;
         break;
      case 0b100:
         ALUresult = A & B;
         break;
      case 0b101:
         ALUresult = A | B;
         break;
      case 0b110:
         ALUresult = B << 16;
         break;
      case 0b111:
         ALUresult = !A;
         break;
      case 0b1000:
         ALUresult = A * B;
         break;
      case 0b1001:
         ALUresult = A / B;
         break;
      default:
      //   halt_flag = 1;
  }
   if (ALUresult == 0)
      Zero = 1;
}



/* instruction fetch */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{

}




/* instruction partition */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{

}





/* instruction decode */
int instruction_decode(unsigned op,struct_controls *controls)
{

}



/* Read Register */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
    data1 = Reg[r1];
    data2 = Reg[r2];
}




/* Sign Extend */
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
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{
  static int halt_flag = 0;
   char ALUControl;
   
   switch(ALUOp)
   {
      case 0b000:
         ALUControl = 0b000;   //addition or don't care
         break;
      case 0b001:
         ALUControl = 0b001;  //sub
         break;
      case 0b0010:
         ALUControl = 0b010;   //slt
         break;
      case 0b011:
         ALUresult = 0b011;   //sltu
         break;
      case 0b100:
         ALUControl = 0b100;  //and
         break;
      case 0b101:
         ALUControl = 0b101;  //or
         break;
      case 0b110:
         ALUControl = 0b110;  //shift extend left 16
         break;
      case 0b111:
         //R-type, checking fucnct
         switch(funct)
         {
            case 0b000011:    //mult
               ALUControl = 0b1000;
               break;
            case 0b010011:    //div
               ALUControl = 0b100;
               break;
            case 0b000100:    //add
               ALUControl = 0b000;
               break;
            case 0b010100:    //sub
               ALUControl = 0b001;
               break;
         }
      default:
         halt_flag = 1;
   }

   if (ALUSrc == 0)
      ALU(data1, data2, ALUControl, &ALUresult, &Zero);
   if (ALUSrc == 1)
      ALU(data1, extended_value, ALUControl, &ALUresult, &Zero);
   
      if (halt_flag == 1)
         return 1;
      else
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
    if (RegWrite == "1" && MemtoReg == "1") //Data coming from memory
        Reg[RegDst] = memdata;
    
    if (RegWrite == "1" && MemtoReg == "0") //Data coming from ALU_result
        Reg[RegDst] = ALUresult;
}



/* PC update */
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

