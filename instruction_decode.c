/* instruction decode */
/* 15 Points */

int instruction_decode(unsigned op, struct_controls *controls)
{
     //Halts unused opcode if needed
     int haltFlag = 0;
     
    switch (op)
    {
    case 0x0:
        *controls = (struct_controls){ 1, 0, 0, 0, 0, 7, 0, 0, 1 };
        break;
    case 0x8:
        *controls = (struct_controls){ 0, 0, 0, 0, 0, 0, 0, 1, 1 };
        break;
    case 0x23:
        *controls = (struct_controls){ 0, 0, 0, 1, 1, 0, 0, 1, 1 };
        break;
    case 0x2b:
        *controls = (struct_controls){ 0, 0, 0, 0, 0, 0, 1, 1, 0 };
        break;
    case 0xf:
        *controls = (struct_controls){ 0, 0, 0, 0, 0, 6, 0, 1, 1 };
        break;
    case 0x4:
        *controls = (struct_controls){ 2, 0, 1, 0, 2, 1, 0, 2, 0 };
        break;
    case 0xa:
        *controls = (struct_controls){ 0, 0, 0, 0, 0, 2, 0, 1, 1 };
        break;
    case 0xb:
        *controls = (struct_controls){ 0, 0, 0, 0, 0, 3, 0, 1, 1 };
        break;
    case 0x2:
        *controls = (struct_controls){ 2, 1, 2, 0, 2, 0, 0, 2, 0 };
        break;
        
    default:
        return 1;
    }
    return 0;
}



