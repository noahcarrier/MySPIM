


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

void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero);
