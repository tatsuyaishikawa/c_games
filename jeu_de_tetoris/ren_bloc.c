#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h> 

 void choice_bloc(char sotowaku[][23]);
 void down_bloc(char sotowaku[][23]);
 void left(void);
 void right(void);

 int kazu=0;
 int x,y,county=0,numero_bloc=0;
 char sotowaku[23][23];

 int main(void)
{
 int x,y,county=0,numero_bloc;
 char sotowaku[23][23],bloc[2][2];

  /*2.外枠を表示*/
 for(y=0;y<23;y++){
  for(x=0;x<23;x++){
   if(y==0 || y==22){
    sotowaku[y][x]='*';
   }
   else{
    if(x==0 || x==22){
     sotowaku[y][x]='*';
    }
    else{
     sotowaku[y][x]=' ';
    }
   }
  }
 }

 
 /*まとめて表示*/
 while(1){
  choice_bloc(sotowaku);
 }
 return 0;
}

 void choice_bloc(char sotowaku[][23])
{
 numero_bloc=rand()%1;
 
 switch(numero_bloc){
  case 0:
	 /*apparition ,nouveau carre*/
          for(y=1+county;y<3+county;y++){
           for(x=11;x<13;x++){
           /* ここはブロック配列をコピーしなくても、ランダムに出されるブロックの
番号によってこちらでfor文の格納刑を変更すればよい*/
            sotowaku[y][x]='*';
           }
          }
	 break;
 case 1:
        /* long bar */
         for(y=10+county;y<14+county;y++){
          for(x=11;x<12;x++){
           sotowaku[y][x]='*';
          }
         }
	 break;
  default:  break;
 }
 
 for(y=0;y<23;y++){
  for(x=0;x<23;x++){
   printf("%c",sotowaku[y][x]);
  }
  printf("\n");
 }

 down_bloc(sotowaku);
 county=0;
 return; 
}

 void down_bloc(char sotowaku[][23])
{
 int out_count=0;

 /* ブロックを左に移動*/
 signal(SIGINT,(void *)left);
 /* ブロックを右に移動*/
 signal(SIGTSTP,(void *)right);

 switch(numero_bloc){
  case 0:
	 while(county<5){
  /*前のブロックを消す*/
  for(y=1+county-1;y<2+county;y++){
   for(x=11;x<13;x++){
    sotowaku[y][x]=' ';
   }
  }
  /* 消した後、ブロックを再度表示*/
  /*現在落下中のブロックの座標は、10(ブロック　最初の位置)+county          最後にcountyをインクリメントしているので＋１する必要はない  yは次の表示部で一度初期化されるのでそのまま使えない*/
          for(y=1+county;y<3+county;y++){
           for(x=11;x<13;x++){
            sotowaku[y][x]='*';
	  }
	 }

  /*画面、およびブロックを表示する*/
  for(y=0;y<23;y++){
   for(x=0;x<23;x++){
    printf("%c",sotowaku[y][x]);
   }
   printf("\n");
  }

  /*ゲームおーば０判定*/
  /*行をずらしていく*/
  for(x=1;x<22;x++){
   out_count=0; 
   /*一行ずつ確認,一つの行に10以上 * があればゲームおーば０*/ 
   for(y=1;y<22;y++){
    if(sotowaku[y][x]=='*'){ 
     out_count++;
    }
   }
   if(out_count==6){
    printf("gameover\n");
    exit(1);
   }
  }
  county++;
  sleep(1);
  printf("coordonnees actuelles y %d \n\n\n\n\n",10+county);
  /*もしy+1の座標に*が既に入っているならブロック同士が接触したと判断*/
  /* 処理を中断し、再度新しいブロックが登場*/
  /* x座標、テスト中は１１で固定する*/
   printf("%d\n\n\n\n\n\n\n\n\n\n\n",2+county);
  if(sotowaku[2+county][11]=='*'){
   printf("10\n\n\n\n\n\n\n\n");
   /* 再度呼び出す際に新しいブロックの位置が初期化されるように注意*/
   county=0;
   /*ゲームオーバーチェック*/
   choice_bloc(sotowaku);
  }
 }
	break;
  case 1:
	 while(county<10){
  /*前のブロックを消す*/
  for(y=10+county-1;y<11+county-1;y++){
   for(x=11;x<12;x++){
    sotowaku[y][x]=' ';
   }
  }

  for(y=0;y<23;y++){
   for(x=0;x<23;x++){
    printf("%c",sotowaku[y][x]);
   }
   printf("\n");
  }

  county++;
  sleep(1);
  }
	break;
  default:break;
 }

 return;
}

 /* x-1 */
 void left(void)
{
 int y;
 printf("%d\n",x);
 /* 移動した跡を消す*/
 for(y=1+county-1;y<2+county;y++){
  for(x=11-1;x<13-1;x++){
   sotowaku[y][x]=' ';
  }
 }

 /*移動後のデータを表示する*/
 for(y=1+county;y<3+county;y++){
  for(x=11;x<13;x++){
   sotowaku[y][x]='*';
  }
 }
}

 /* x+1 */
 void right(void)
{
 int y;
 printf("%d\n",x);
 return;
 /* 移動した跡を消す*/
 for(y=1+county-1;y<2+county;y++){
  for(x=11-1;x<13-1;x++){
   sotowaku[y][x]=' ';
  }
 }

 /*移動後のデータを表示する*/
 for(y=1+county;y<3+county;y++){
  for(x=11;x<13;x++){
   sotowaku[y][x]='*';
  }
 }
 return;
}
