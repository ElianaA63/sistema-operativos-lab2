#include "types.h"
#include "stat.h"
#include "user.h"
 
 
void clearscreen(){
   plotrectangle(0,0,320,200,15);
}

void clearscreenblack(){
   plotrectangle(0,0,320,200,0);
}

int
main(void){
 
unsigned int i, j, x;
 
int img2[]={15,15,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,0,0,15,15,
15,0,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,9,0,15,15,
15,15,0,9,9,9,0,14,9,9,9,9,9,9,9,9,9,9,0,15,15,
15,15,15,0,9,9,0,14,14,9,9,9,9,9,9,9,9,9,0,15,15,
15,15,15,15,0,9,0,14,9,9,9,9,9,9,9,9,9,9,9,0,15,
15,15,15,0,9,9,9,9,9,9,9,9,15,15,15,9,9,9,9,0,15,
15,15,0,9,9,9,9,9,9,9,9,15,15,15,15,15,9,9,9,0,15,
15,0,9,9,9,9,9,9,9,9,9,15,15,15,15,0,9,15,0,15,15,
0,0,0,0,0,0,9,9,9,9,9,15,15,15,15,0,9,15,0,15,15,
15,15,15,15,0,9,9,9,9,9,9,9,15,15,15,0,15,0,0,0,15,
15,15,15,0,9,9,9,9,9,14,14,14,15,15,15,15,14,14,0,15,
15,15,0,9,9,9,9,9,9,14,14,14,14,14,14,14,14,14,0,15,15,
15,0,0,0,0,0,0,0,0,0,14,14,14,14,14,14,14,0,15,15,15,
15,15,15,15,15,15,15,15,0,14,0,0,0,0,0,0,0,0,15,15,15,
15,15,15,15,15,15,15,0,14,0,0,9,14,14,14,0,0,0,0,15,15,
15,15,15,15,15,15,0,14,0,15,15,0,14,14,14,0,15,15,0,15,15,
15,15,15,15,15,15,0,0,15,15,15,15,0,14,14,0,15,15,0,15,15,
15,15,15,15,15,15,15,0,15,15,15,15,0,0,14,0,15,0,15,15,15,
15,15,15,15,15,15,15,15,0,15,15,0,0,9,0,0,0,0,15,15,15,
15,15,15,15,15,15,15,15,15,0,0,9,0,0,0,15,15,15,15,15,15,
15,15,15,15,15,15,15,15,15,0,0,9,0,12,12,0,0,15,15,15,15,
15,15,15,15,15,15,15,15,0,0,12,12,0,0,12,12,15,0,0,15,15,
15,15,15,15,15,15,15,15,0,12,12,12,15,12,0,0,12,12,12,0,15,
15,15,15,15,15,15,15,15,0,12,12,0,12,12,12,12,0,12,12,12,0,
15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
modeswitch(1);
 
clearscreen();
 
x = 0;
for(j=0;j<200; j+=8){
    for(i=0; i<168; i+=8){
       plotrectangle(i,j,i+8,j+8,img2[x]);
       x++;
    }
}
sleep(300);
clearscreenblack();
modeswitch(0);
exit();
 
}
