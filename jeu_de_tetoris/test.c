#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

 void left(void);
 void right(void);

 int x,y,county=0,numero_bloc=0;
 char sotowaku[23][23];

 int main(void)
{

 signal(SIGINT,(void*)left);
 signal(SIGTSTP,(void*)right);

 for(y=0;y<10;y++){ 
  for(x=0;x<10;x++){
   if(y==0 || y==9){
    sotowaku[y][x]='*';
   }
   else{
    if(x==0 || x==9){
     sotowaku[y][x]='*';
    }
    else{
     sotowaku[y][x]=' ';
    }
   }
  }
 }
 
 while(1){
 /* hako */
 for(y=4;y<6;y++){
      for(x=4;x<6;x++){
            sotowaku[y][x]='*';
           }
          }

 /* hyoji */
 for(y=0;y<23;y++){
   for(x=0;x<23;x++){
    printf("%c",sotowaku[y][x]);
   }
   printf("\n");
  }
  sleep(1);
 }
 return 0;
}

 void left(void)
{
 for(){ 
 }
 return;
}

 void right(void)
{

}
