#include <stdio.h>



int main()
{
   int value;
   unsigned ALUresult, unsigned data2, char MemWrite, char MemRead, unsigned *memdata, unsigned *Mem;
   int = rw_memory(ALUresult, data2, MemWrite, MemRead, &memdata, &mem);
   return 0;
}


int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{
  if (MemWrite == 1)
    {
     *Mem = data2;
    }

  else if (MemRead == 1) 
    {
     ALUresult = data2;
    }
   
  else if (MemRead != 1 && MemWrite != 1)
    {
    return 1;
    }
    
  
  
}
