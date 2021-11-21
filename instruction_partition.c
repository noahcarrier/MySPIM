void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1, unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
   
    
    *op = (instruction >> 26) & 0xfc000000;
    //
    *r1 = (instruction >> 21) & 0x03e00000;
    //
    *r2 = (instruction >> 16) & 0x001f0000;
    //
    *r3 = (instruction >> 11) & 0x0000f800;
    
    //
    *funct = instruction & 0x0000003F;
    *offset = instruction & 0x0000FFFF;
    *jsec = instruction & 0x03FFFFFF;
}
