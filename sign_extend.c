#include <stdio.h>



int main()
{
    unsigned offset, *extended_value;
    sign_extend(offset, &extended_value);
    return 0;
}


void sign_extend(unsigned offset,unsigned *extended_value)
{
    
   int first;

    first = offset;
    
    while (first >= 10) // Finds the first number of offset
    {
        first = first / 10;
    }    
    
    if (first == 1)
    {
         //Negative value
         //add 2 bit strings (1111 1111 1111 1111 0000 0000 0000 0000 and offset)
        
        
    }
    else if (first == 0)
    {
          //Positive value
         //add 2 bit strings (0000 0000 0000 0000 0000 0000 0000 0000 and offset)
    } 
    

      

*extended_value = offset;
}
