static int Halt = 0;



int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

   
   //Set parameters for A, B, and ALUControl 


   switch (ALUOp)
   {
      case 0b000000:
         ALU(data1, data2, funct, ALUresult, Zero);
         break;
      case 0b000001:
         //addi
      case 0b000010:
         //TLB
      case 0b000011:
         //ALU will do "set less than unsigned" operation
      case 0b000101:
         //ALU will do "OR" operation
      case 0b000110:
         extended_value<<16;  //ALU shift left extended_value by 16 bits
         break;
      case 0b001000:
         //bltz/gez
      case 0b001001:
         //addiu
      case 0b001010:
         //FlPt
      case 0b010001:
         //Set less than imm
      case 0b011001:
         //sltiu
      case 0b100001:
         //andi
      case 0b100100:
         //lbu
      case 0b101001:
         //ori
      case 0b101100:
         //lhu
      case 0b110000:
         //blez
      case 0b110001:
         //xori
      case 0b111000:
         //bgtz
   }
   
   
   ALU(data1, data2, funct, ALUresult, Zero);

   if (ALUresult == 0)
      Zero = 1;
   
   if (Halt == 1)
      return 1;
   else
      return 0;
}