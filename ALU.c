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