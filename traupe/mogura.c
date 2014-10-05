 #include <stdio.h>
 #include <string.h>
 #include <signal.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <setjmp.h>
 #include "userdata.c"
  
 #define DATAFILE "datafile.c"

/* p1,p2,p3 pointers keeps main functions( moguratataki(),ichi(),tataku() */
 void *moguratataki(void);
 void meilleur(void);
 void *shokika(void);
 void *ichi(void);
 /*int tataku(void); */
 void *tatake(void);
 void getplayerdata(void);
 void enregistrer(void);
 void exce(void);

 int hako[3][4];
 int x,y,i=0;
 int input1,input2;
 int count=0;
 jmp_buf val; /* si l'erreur surgit,appeler une fonction  exce()*/

 struct mogura tataki[100];


 int main(void)
{
 int input=0,p1;

 while(1){
 printf("welcome to mogura tataki ! please input number of procedure\n");
 printf("1--- start game   2--- view high score  3--- quit \n");
 scanf("%d",&input);
 
 switch(input){
  case 1:
         moguratataki();
         break;
  case 2:
         meilleur();
         break;
         /* goback to  start screen */
  case 3:
         printf("thanks for playing game\n");
         exit(1);
  case 4:
         getplayerdata();
         break;
  default:
         printf("please enter valid number \n");
         break;
         /* retray until you enter 1~3 */
  }
 }
 return 0; 
}

 void *moguratataki(void)  /* モグラの表示　*/
{
 unsigned long int p2,p3,p4;

 signal(SIGINT,(void *)tatake);
  shokika(); /* 1  initialisation */
 while(count<10){
  sleep(1);
  setjmp(val);
  longjmp(val,2);
 /* pthread(&p3,NULL,ichi,(void *)NULL);*//* 2 position of mogura */ /* tataku() とmoguratattaki()と同時並行*/
 /* tataku(); 3 hit mogura  ,  表示と同時並行で進める　モグラをたたlllく/i*/
 
  for(y=0;y<3;y++){
   for(x=0;x<4;x++){
    printf("%d",hako[y][x]);
   }
   printf("\n");
  }
  tatake(); 
  if(hako[input1][input2]==1){
   printf("atari\n");
   tataki.score++;
   }
  shokika();
  count++;
  }
 
 enregistrer();
 printf("thanks for playing game \n");
 return;
}

 void meilleur(void)
{
 int input,j=0;

 printf("please input the id of user\n");
 scanf("%d",&input);

 printf("%d 's the high score is %d\n",tataki.id,tataki.score);
 return;
}


 void *shokika(void)
{

 for(y=0;y<3;y++){
  for(x=0;x<4;x++){
   hako[y][x]=0;
   }
  }
 return;
}

 void *ichi(void)
{
/*getuid()l;*/
/*int *p2=malloc(300);*/
hako[y][x]=0; /* previous mogura kesu */
x=rand()%4;
y=rand()%3;

hako[y][x]=1;
/*free(p2);*/
return;
}

/* int tataku(void)
{
 getuid();
 int *p3=malloc(300);
 signal(SIGTSTP,signal_handler);
 
 while(1){
  }
 free(p3);
 return 0;
}*/

void *tatake(void)
{
 printf("mogurawotatake\n");
 scanf("%d",&input1); scanf("%d",&input2); 
 return; 
}

void getplayerdata(void)
{
  int fd,nagasa,uid;
  struct mogura entry; 
  fd=open("/mnt/sdb1/home/S13016/traupe/file.data",O_RDONLY);
    
  nagasa=read(fd,&entry,sizeof(struct mogura));
  
  while(entry.id != uid && nagasa>0){
    nagasa=read(fd,&entry,sizeof(struct mogura));
    }

  close(fd);
  
  tataki=entry;
  return;
}

 void enregistrer(void)
{
 int toroku=0;
 /*printf("you got %d points!\n",tataki[i].score);*/
 printf("do you register your score?\n");
 printf("1-- yes 2-- no \n");
 scanf("%d",&toroku);

 switch(toroku){

   case 1:
/* write the data of current user */
 while(&tataki[i]!=NULL){
   write(DATAFILE,&tataki[i],4);
   write(DATAFILE,":",2);
   }
 write(DATAFILE,";",2);
 printf("register finish\n");
 
   case 2: 
   /* go back to start menu */
   default:
     printf("invalid value.please reenter\n");
     /* go back to scanf */
   }

 return;
}
