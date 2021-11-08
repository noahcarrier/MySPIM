static int Halt = 0;



int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

   
   //Set parameters for A, B, and ALUControl 


   switch (ALUOp)
   {
      case 0:
         //ALU will do addition or "don't care"
      case 0b1:
         //ALU will do subtraction
      case 0b10:
         //ALU will do "set less than" operation
      case 0b11:
         //ALU will do "set less than unsigned" operation
      case 0b100:
         //ALU will do "AND" operation
      case 0b101:
         //ALU will do "OR" operation
      case 0b110:
         //ALU shift left extended_value by 16 bits
      case 0b111:
         //Instruction is R-type
            //Look at funct
      default:
   }
   
   
   void ALU(data1, data2, ALUControl, ALUresult, Zero);

   if (Halt == 1)
      return 1;
   else
      return 0;
}