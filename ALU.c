void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
    switch (ALUControl)
   {
      case 0:
         // Z = A + B
      case 0b1:
         // Z = A - B
      case 0b10:
         // if A < B, Z = 1, otherwise, Z = 0
      case 0b11:
         // if A < B, Z = 1, otherwise Z = 0 (A and B unsigned)
      case 0b100:
         // Z = A AND B
      case 0b101:
         // Z = A OR B
      case 0b110:
         // Z = Shift B left by 16 bits
      case 0b111:
         // Z = NOT A
      default:
   }
}