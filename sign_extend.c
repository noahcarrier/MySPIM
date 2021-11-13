#include <stdio.h>



int main()
{
    unsigned offset, *extended_value;
    sign_extend(offset, &extended_value);
    return 0;
}


void sign_extend(unsigned offset,unsigned *extended_value)
{
    
    int sign_bit;
    
    sign_bit = (offset << 31);
    
    if (sign_bit == 1)
    {
         offset = 0xFFFF0000 + offset;    
    }
    
    else if (sign_bit == 0)
    {

         offset = 0x00000000 + offset;
    } 
    
*extended_value = offset;
}
