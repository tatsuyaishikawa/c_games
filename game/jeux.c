/* ou stocker des donnes score ?*/
/* comment ouvrir le fichier score */
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <fcntl.h>

 #define DATA_FILE "donnees"

 struct internaute{
  int uid;
  char nom[20];
  int score;
  int highscore;
  int(* current_game)(); /* 5m*/
  };

 struct internaute player;

 int get_player_data(void);
 void update_player_data(void);
 void jeu1(void);
 void jeu2(void);
 void jeu3(void);
 void play_game(void);
 void show_highscore(void);
 void enregistrer(void); 
 void inputname(void);

 int main(void)
{
 int choice;
 
 if(get_player_data() ==-1){
  enregistrer();
 }
 /* login処理は割愛します。*/
/*
 printf("ログイン --1  新規ユーザ登録 --2  終了 --3 \n");
 scanf("%d",&chioce);

 switch(chioce){
  case 1:
	 tologin();
  case 2:
	 enregistrer();
  case 3:
	 printf("bye\n");
	 exit(1);
  default:
 }
*/
 while(1){
printf("welcome to game . please input operation \n");
printf("1------(もぐらたたき)\n");
printf("2------(ライフゲーム)\n");
printf("3------(テトリス)\n");
printf("4------(数当てゲーム)\n");
printf("5------show high score\n");
printf("6------bye\n");

 scanf("%d",&choice);
 
 switch(choice){

  case 1:
	 player.current_game=jeu1;
	 break;
  case 2:
	 player.current_game=jeu2;
	 break;
  case 3:
	 player.current_game=jeu3;
	 break;
  case 4:
	 printf("maintenance\n");
	 exit(1);
  case 5:
	 show_highscore();
	 break;
  case 6:printf("bye\n");
	 exit(1);
  default:printf("無効な数字です\n");
	  break;
 }
 play_game();

 }
 return 0;
}

 int get_player_data(void)
{
 int fd,uid,byte_read;
 struct internaute entree;

 uid=getuid();

 fd=open(DATA_FILE,O_RDONLY); 
 
 if(fd==-1){
  printf("error\n");
  return -1;
 }

 byte_read=read(fd,&entree,sizeof(struct internaute));
 
 while(entree.uid != uid && byte_read >0){
   byte_read=read(fd,&entree,sizeof(struct internaute));
 }

 close(fd);
 if(byte_read < sizeof(struct internaute))
   return -1;
 else 
   player=entree;
 
 return 1;
}

 void play_game(void)
{
 int refait;

 do{
  if(player.current_game()!=-1){
   if(player.score > player.highscore){
    player.highscore=player.score;
   }

  printf("あなたのスコアは%d点です。\n",player.highscore); 
  update_player_data();
  
  printf("続けますか？\n");
  scanf("%d",&refait);
  }
 }while(refait);

 return;
}

 void enregistrer(void)
{
 int fd;

 printf("ようこそ\n");
 printf("nom de user \n");
 input_name();

 player.uid=getuid();
 player.score=100;

 fd=open("donnees",O_RDWR);

 write(fd,&player,sizeof(struct internaute));
 close(fd);

 printf("welcome 　%s to our party!\n",player.nom);
 printf("your score is %d \n",player.score);
 
 return;
}

 void input_name(void)
{
 char *point_to_username,input;

 while(input!='\n'){
  scanf("%c",&input);

  point_to_username=(char *)&(player.nom);
  while(input !='\n'){
   *point_to_username=input;
   scanf("%c",&input);
   point_to_username++;
  }
   *point_to_username=0;
 }
 
 return;
}

 void jeu1(void)
{
int i,point=0,select,refait;
char boit[i];

 do{
 i=rand()%10;
 printf("please select number\n");
 scanf("%d",&select);
 if(i==select){
   printf("当たりです。\n");
   point++;
 } else{
   printf("はずれです。\n");
 }
  printf("続けますか？\n");
  printf("--0 以外の数で続行\n");
  scanf("%d",&refait);
 }while(refait);

 player.score=point;
 /* comment terminer le jeu1*/
 update_player_data();
 return; /* batu */
}
 
 void jeu2(void)
{
int i,point=0,select,refait;
char boit[i];

 do{
 i=rand()%26;
 printf("please select number\n");
 scanf("%d",&select);
 if(i==select){
   printf("当たりです。\n");
   point++;
 } else{
   printf("hazure\n");
 }
  printf("続けますか？\n");
  printf("--0 以外の数で続行\n");
  scanf("%d",&refait);
 }while(refait);

 player.score=point;
 /* comment terminer le jeu1*/
 update_player_data();
 return; /* batu */
}

 void jeu3(void)
{
int i,point=0,select,refait;
char boit[i];

 do{
 i=rand()%26;
 printf("please select number\n");
 scanf("%d",&select);
 if(i==select){
   printf("当たりです。\n");
   point++;
 } else{
   printf("hazure\n");
 }
  printf("続けますか？\n");
  printf("--0 以外の数で続行\n");
  scanf("%d",&refait);
 }while(refait);

 player.score=point;
 /* comment terminer le jeu1*/
 update_player_data();
 return; /* batu */
}

 void show_highscore(void)
{
 int input=0,fd;
 char boit[20];

 printf("please select file number 1~3\n");
 scanf("%d",&input);

 if(input<1 || input >3){
   printf("please select valid number \n");
   }   

 fd=open(DATA_FILE,O_RDWR);

 /*
 while(read(boit,20,fd)!=NULL){
     if(player.score){
     }
  }
 */ 
 printf("%d\n",player.score);
 close(fd);
 return 0;
}

 void update_player_data(void) /* fread != read */
{
 int fd;

 fd=open("donnees",O_RDWR);
 write(fd,&(player.score),4);
 write(fd,&(player.nom),100);
 close(fd);
 
 return;
}
