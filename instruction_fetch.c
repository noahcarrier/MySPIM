int instruction_fetch(unsigned PC, unsigned *Mem, unsigned *instruction)
{
    if (PC % 4 == 0)
        *instruction = Mem[PC >> 2];
    else
        return 1;
    return 0;
}

