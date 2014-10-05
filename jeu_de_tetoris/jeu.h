
 #define FILENAME "main_frame.txt"

 int jeu(void)
{
 int fd,i,j;
 char buf[20][21],sotowaku[40][40];

 /*1.全ての部品を呼び出す*/
 
 /*画面を作成*/
 /*
 while(read(buf,strlen(buf),fd)!=-1){
  for(j=0;j<21;j++){
    for(i=0;i<20;i++){
     printf("%s",buf[j][i]); 
    }
   printf("\n");
  }
 }
 */

 for(y=0;y<40;y++){
  for(x=0;x<40;x++){
   if(y==0 || y==39){
    sotowaku[y][x]='*';
   }
   else{
    if(x==0 || x==39){
     sotowaku[y][x]='*';
   }
  }
  printf("\n");
 }
 /*メインフレームを作成*/
 
 /*ブロックをランダムに呼び出す*/
 

 return 0;
}
