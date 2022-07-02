#include "types.h"
#include "stat.h"
#include "user.h"
 
unsigned short lfsr = 0xACE1u;
unsigned bit;
 
// Devolver un entero pseudoaleatorio
unsigned rand()
{
 bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
 return lfsr =  (lfsr >> 1) | (bit << 15);
}
 
void clearscreen(){
   plotrectangle(0,0,320,200,0);
}

void clearscreenblack(){
   plotrectangle(0,0,320,200,0);
}
 
int
main(int argc, char *argv[])
{
 int randx, randy, randx2, randy2, randx3, randy3, randx4, randy4;
 
 modeswitch(1);
 for(unsigned int i = 0; i < 200; i++){
   randx = rand() % 319;
   randy = rand() % 190;
   randx2 = rand() % 319;
   randy2 = rand() % 190;
   randx3 = rand() % 319;
   randy3 = rand() % 190;
   randx4 = rand() % 319;
   randy4 = rand() % 190;
   sleep(3);
   clearscreen();
   plotrectangle(randx, randy, randx, randy+5, 15);
   plotrectangle(randx2, randy2, randx2, randy2+4, 15);
   plotrectangle(randx3, randy3, randx3, randy3+4, 15);
   plotrectangle(randx4, randy4, randx4, randy4+3, 15);
 }
 clearscreenblack();
 modeswitch(0);
 
 exit();
}
