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

