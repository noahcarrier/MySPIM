#include <stdio.h>


/*
    Dictionary
   ***************************************
   *    r1 -> target
   *    r2 -> reading value
   *    Reg -> register array to be read
   *    data1 -> array of some values
   *    data2 -> array of some values
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
    for (int index = 0; index < 32; index++)
    {
        if (Reg[index] == data1[r1])
        {
            data2[r2] = Reg[index];
        }
    }
}