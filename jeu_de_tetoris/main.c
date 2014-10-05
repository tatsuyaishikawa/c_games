 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include "jeu.h"
 
 int jeu(void);

 int main(void)
{
 int cont=0,locker=0,choix=0;
 
 /* login session */
 /*
 do{
  if(login()!=1 && locker<3){
   printf("votre id ou votre mot de pass n'est pas correcte\n");
  }
  if(login()!=1 && locker==3){
   printf("vous avez saisi des mauvaises donnees plus de 3 fois.votre compte sera desormais bloque\n");
   exit(1);
  }
  locker++;
 }while(login()!=1 && locker<3);
 */
 /*login reussi. le jeu va commencer */
 do{
  /*printf("bienvenu %s (id: %d)! choisissez des options!\n");*/
 /* --1 jouer au jeu de tir  --2 enregistrer un nouveau utilisateur
  --3 supprimer un utilisateur --4 afficher la liste des scores*/ 
  scanf("%d",&choix);
  switch(choix){
   case 1:jeu();
	  break;
   /*case 2:ajouter();
	  break;
   case 3:supprimer();
	  break;
   case 4:score();
	  break;*/
   default:
	  printf("saisissez le nombre valide\n");
	  break; 
  }
 
  printf("vous voulez continuer ? \n");
  printf("--0 quitter le jeu --1 continuer \n");
  scanf("%d",&cont);
 }while(cont);

 /*logout, fin de session*/
 /*free(sessio);*/
 printf("fin de jeu \n");
 return 0;
}
