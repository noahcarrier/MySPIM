void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
   switch (ALUControl)
   {
      case 0b000000:
         ALUresult = A<<B;
         break;
      case 0b000001:
         break;
      case 0b000010:
         break;
      case 0b000011:
         ALUresult = A * B;
         break;
      case 0b000100:
         ALUresult = A + B;
         break;
      case 0b001001:
         break;
      case 0b001010:
         break;
      case 0b001011:
         ALUresult = A * B;
         break;
      case 0b001100:
         ALUresult = A + B;
         break;
      case 0b010000:
         ALUresult = A >> B;
         break;
      case 0b010010:
         break;
      case 0b010011:
         ALUresult = A / B;
         break;
      case 0b010100:
         ALUresult = A - B;
         break;
      case 0b010101:
         if (A < B)
            ALUresult = 1;
         else
            ALUresult = 0;
         break;
      case 0b011000:
         break;
      case 0b011010:
         break;
      case 0b011011:
         ALUresult = A / B;
         break;
      case 0b011100:
         ALUresult = A - B;
         break;
      case 0b011101:
         if (A < B)
            ALUresult = 1;
         else
            ALUresult = 0;
         break;
      case 0b100000:
         break;
      case 0b100001:
         break;
      case 0b100100:
         ALUresult = A & B;
         break;
      case 0b101001:
         break;
      case 0b101100:
         ALUresult = A | B;
         break;
      case 0b110100:
         ALUresult = A ^ B;
      case 0b111000:
         break;
      case 0b111100:
         ALUresult = !(A | B);
         break;
   }
}