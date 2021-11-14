#include <stdio.h>


int main() 
{
   unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC;
   void PC_update(jsec, extended_value, Branch, Jump, Zero, &PC);
   return 0;
}


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
