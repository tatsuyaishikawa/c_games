#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
 int main(void)
{
 FILE *fd_main_frame;
 int fd,x,y;
 char buf[20][21],sotowaku[40][40],main_frame[20][20];
 
 /*1.全ての部品を呼び出す*/
 if((fd_main_frame=fopen("main_frame","r"))==NULL){
  printf("error\n");
  exit(1);
 }
 /*2.外枠を表示*/
 for(y=0;y<40;y++){
  for(x=0;x<40;x++){
   if(y==0 || y==39){
    sotowaku[y][x]='*';
   } 
   else{
    if(x==0 || x==39){
     sotowaku[y][x]='*';
    }
    else{
     sotowaku[y][x]=' ';
    }
   }
  }
 }
 /*3.メインフレームを書き込む*/
	/* フレームの内容をストリームからコピー*/
 memset(main_frame,' ',400);
 for(y=0;y<20;y++){
  for(x=0;x<20;x++){
   /*fread(main_frame,1,1,fd_main_frame);*/
  }
 }
 
 
 for(y=0;y<20;y++){
  for(x=0;x<20;x++){
   /*fread(main_frame,1,1,fd_main_frame);*/
   fscanf(fd_main_frame,"%s[^]",main_frame);
  }
 }
 
 for(y=0;y<20;y++){
  for(x=0;x<20;x++){
   /*fread(main_frame,1,1,fd_main_frame);*/
   printf("%c",main_frame[y][x]);
  }
  printf("\n");
 }
 /*
 for(y=0;y<20;y++){
  for(x=0;x<20;x++){
   fscanf(fd_main_frame,"%d",main_frame[y][x]);
   printf("%d",main_frame[y][x]);
  }
  printf("\n");
 }
 */
 fclose(fd_main_frame);
 exit(1);
 
 for(y=10;y<30;y++){
  for(x=10;x<30;x++){
   sotowaku[y][x]=main_frame[y-10][x-10];
  }
 /*kaigyo*/
 }
 
 /*4.全ての部品を読み込んだ後printfする*/
 /*
 for(y=0;y<40;y++){
  for(x=0;x<40;x++){
   printf("%c",sotowaku[y][x]);
  }
  printf("\n");
 }
 */
 /*ブロックをランダムに呼び出す*/
 fclose(fd_main_frame);
 return 0;
}
