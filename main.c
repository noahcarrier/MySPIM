/*
MySPIM Project
CDA 3103C - Computer Logic & Organization

Contributors:
Brandon Magloire
Noah Carrier
Evan Agustin Verdu
*/


#include <stdio.h>


//Global Variables for registers (excluding temporary)
int a0, a1, a2, a3;                 //Arguments      *
int s0, s1, s2, s3, s4, s5, s6, s7; //Callees        *
int zero = 0b0;                     //Zero register  *
int v0, v1;                         //Funct results  *
int gp;                             //Global pointer *
int sp;                             //Stack pointer  *
int fp;                             //Frame pointer  *
int ra;                             //Return address *
//*****************************************************


int main()
{
  printf("Hello, World!");
  return 0;
}
