#include <stdio.h>



int main()
{
    unsigned offset, *extended_value;
    sign_extend(offset, &extended_value);
    return 0;
}


void sign_extend(unsigned offset,unsigned *extended_value)
{

//Figure out how to extend offset. Unless it is already extended.

*extended_value = offset;
}
