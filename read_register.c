#include <stdio.h>


/*
    Dictionary
   ***************************************
   *    r1 -> source
   *    r2 -> source
   *    Reg -> register array to be read
   *    data1 -> register output
   *    data2 -> register ouput
   ****************************************

*/



int main()
{
    unsigned r1, r2, *Reg, *data1, *data2;
    read_register(r1, r2, *Reg, *data1, *data2);
    return 0;
}


void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
    data1 = Reg[r1];
    data2 = Reg[r2];
}