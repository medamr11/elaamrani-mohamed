#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int id;
    char titre[50],aut[50],dscrp[50],nom[50],cat[50],dsp[10];
    float prix;
}livre;

void lire_fichier_livres(livre *a, int *n) {
    FILE *fichier;
    fichier=fopen("livres.txt", "r");

    if (fichier==NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        perror("Erreur");
        return;
    }
	*n = 0;
	while (fscanf(fichier, "Livre %d :\nLe titre : %s\nL'auteur : %s\nLa description : %s\nLe nom d'utilisateur : %s\nLa categorie : %s\nLa disponibilite : %s\nL'ID : %d\nLe prix : %f\n\n",
                  &a[*n].id, a[*n].titre, a[*n].aut, a[*n].dscrp, a[*n].nom, a[*n].cat, a[*n].dsp, &a[*n].id, &a[*n].prix) == 9) {
        (*n)++;
    }

    fclose(fichier);
    printf("Les donnees ont ete chargees depuis le fichier.\n");
}

void sauvegarder(livre *a, int N) {
    FILE *fichier;
    fichier=fopen("livres.txt", "w");
	if (fichier==NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i=0; i<N; i++) {
        fprintf(fichier, "Livre %d :\n", (a+i)->id);
        fprintf(fichier, "Le titre : %s\n", (a+i)->titre);
        fprintf(fichier, "L'auteur : %s\n", (a+i)->aut);
        fprintf(fichier, "La description : %s\n", (a+i)->dscrp);
        fprintf(fichier, "Le nom d'utilisateur : %s\n", (a+i)->nom);
        fprintf(fichier, "La categorie : %s\n", (a+i)->cat);
        fprintf(fichier, "La disponibilite : %s\n", (a+i)->dsp);
        fprintf(fichier, "L'ID : %d\n", (a+i)->id);
        fprintf(fichier, "Le prix : %.2f\n\n", (a+i)->prix);
    }

    fclose(fichier);
    printf("Les informations ont ete sauvegardees dans le fichier.\n");
}

int counter=1;

void ajt (livre *a, int n) {
   (a+n)->id=counter;
   counter++;
   printf("Entrez le prix de votre livre\n");
   scanf("%f",&(a+n)->prix);
   printf("Entrez le titre de votre livre\n");
   scanf("%s",(a+n)->titre);
   printf("Entrez l'auteur de votre livre\n");
   scanf("%s",(a+n)->aut);
   printf("Entrez la description de votre livre\n");
   scanf("%s",(a+n)->dscrp);
   printf("Entrez le nom d'utilisateur\n");
   scanf("%s",(a+n)->nom);
   printf("Entrez la categorie de votre livre\n");
   scanf("%s",(a+n)->cat);
   printf("Entrez la disponibilte\n");
   scanf("%s",(a+n)->dsp);
   }
   
void ajouter(livre *a, int N) {
    ajt(a, N);
	FILE *fichier;
    fichier=fopen("livres.txt", "a");

    if (fichier==NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    fprintf(fichier, "Livre %d :\n", (a+N)->id);
    fprintf(fichier, "Le titre : %s\n", (a+N)->titre);
    fprintf(fichier, "L'auteur : %s\n", (a+N)->aut);
    fprintf(fichier, "La description : %s\n", (a+N)->dscrp);
    fprintf(fichier, "Le nom d'utilisateur : %s\n", (a+N)->nom);
    fprintf(fichier, "La categorie : %s\n", (a+N)->cat);
    fprintf(fichier, "La disponibilite : %s\n", (a+N)->dsp);
    fprintf(fichier, "L'ID : %d\n", (a+N)->id);
    fprintf(fichier, "Le prix : %.2f\n\n", (a+N)->prix);
    fclose(fichier);
    printf("Les informations ont ete sauvegardees dans le fichier.\n");
}

void supprimer(livre *a, int N) {
   int ID,j,k=0;
 lol :  printf("Entrez l'ID du livre a supprimer\n");
   scanf("%d",&ID);
   for (int i=0; i<N; i++) {
    if (ID==(a+i)->id) {
        j=i;
        k++;
        for (int d=N-1; d>j; d--) {
            *(a+d-1)=*(a+d);
        }
    }
  }
  if (k==0) {
  	printf("Ce ID n'existe pas!\n");
  	goto lol;
  }
  a=(livre*)realloc(a,(N-k)*sizeof(livre));
  sauvegarder(a, N-k);
}

void modifier(livre *a, int N) {
    char ttr[50];
    int k = 0;

   blabla: printf("Entrez le titre du livre à modifier :\n");
    scanf("%s", ttr);

    for (int i=0; i<N; i++) {
        if (strcmp((a+i)->titre, ttr)==0) {
            k++;
            printf("Livre trouve. Entrez les nouvelles informations :\n");

            printf("Entrez le nouveau prix :\n");
            scanf("%f", &(a+i)->prix);
            printf("Entrez le nouveau titre :\n");
            scanf("%s", (a+i)->titre);
            printf("Entrez le nouveau nom d'auteur :\n");
            scanf("%s", (a+i)->aut);
            printf("Entrez la nouvelle description :\n");
            scanf("%s", (a+i)->dscrp);
            printf("Entrez le nouveau nom d'utilisateur :\n");
            scanf("%s", (a+i)->nom);
            printf("Entrez la nouvelle catégorie :\n");
            scanf("%s", (a+i)->cat);
            printf("Entrez la nouvelle disponibilité :\n");
            scanf("%s", (a+i)->dsp);

            break;
        }
    }

    if (k==0) {
        printf("Ce titre n'existe pas !\n");
        goto blabla;
    }
        sauvegarder(a, N);
        printf("Les informations du livre ont été mises à jour.\n");
    
}

void afficher (livre *a, int N) {
    int ID,j=0;
for (int i=0; i<N; i++) {
	j++;
     printf("Livre %d :\n",j);
     printf("Le titre : %s\n",(a+i)->titre);
     printf("L'auteur : %s\n",(a+i)->aut);
     printf("La description : %s\n",(a+i)->dscrp);
     printf("Le nom d'utilisateur : %s\n",(a+i)->nom);
     printf("La categorie :%s\n",(a+i)->cat);
     printf("La disponibilte :%s\n",(a+i)->dsp);
     printf("L'ID :%d\n",(a+i)->id);
     printf("Le prix :%.2f\n",(a+i)->prix);
    }
}
void rechercher_titre(livre *a, int N) {
    char ttr[50];
    int j = 0;
    
    kacm : printf("Entrez le titre des livres a rechercher :\n");
    scanf("%s", ttr);

    for (int i = 0; i < N; i++) {
        if (strcmp((a + i)->titre, ttr) == 0) {
            j++;
            printf("Livre %d :\n", j);
            printf("Le titre : %s\n", (a+i)->titre);
            printf("L'auteur : %s\n", (a+i)->aut);
            printf("La description : %s\n", (a+i)->dscrp);
            printf("Le nom d'utilisateur : %s\n", (a+i)->nom);
            printf("La categorie : %s\n", (a+i)->cat);
            printf("La disponibilité : %s\n", (a+i)->dsp);
            printf("L'ID : %d\n", (a+i)->id);
            printf("Le prix : %.2f\n", (a+i)->prix);
        }
    }

    if (j == 0) {
        printf("Aucun livre avec ce titre n'a ete trouve.\n");
        goto kacm;
    }
}

void rechercher_auteur(livre *a, int N) {
    char atr[50];
    int j = 0;
    
    kwika : printf("Entrez l'auteur des livres à afficher :\n");
    scanf("%s", atr);

    for (int i = 0; i < N; i++) {
        if (strcmp((a+i)->aut, atr) == 0) {
            j++;
            printf("Livre %d :\n", j);
            printf("Le titre : %s\n", (a+i)->titre);
            printf("L'auteur : %s\n", (a+i)->aut);
            printf("La description : %s\n", (a+i)->dscrp);
            printf("Le nom d'utilisateur : %s\n", (a+i)->nom);
            printf("La categorie : %s\n", (a+i)->cat);
            printf("La disponibilité : %s\n", (a+i)->dsp);
            printf("L'ID : %d\n", (a+i)->id);
            printf("Le prix : %.2f\n", (a+i)->prix);
        }
    }

    if (j == 0) {
        printf("Aucun livre avec cet auteur n'a ete trouve.\n");
    	goto kwika;
	}
}
void Tri_categori (livre *a,int N){
	int j=0;
	 for (int i = 0; i < N; i++) {  
	 j++;
	printf("------------------- Le categori %s ------------------------ \n:",(a+i)->cat);
	 	for (int e = 0; e < N; e++) {
        if (strcmp((a+i)->cat, (a+e)->cat) == 0) {
          
	 printf("Le titre : %s\n", (a+i)->titre);
            printf("L'auteur : %s\n", (a+i)->aut);
            printf("La description : %s\n", (a+i)->dscrp);
            printf("Le nom d'utilisateur : %s\n", (a+i)->nom);
            printf("La categorie : %s\n", (a+i)->cat);
            printf("La disponibilité : %s\n", (a+i)->dsp);
            printf("L'ID : %d\n", (a+i)->id);
            printf("Le prix : %.2f\n", (a+i)->prix);
}
}
}
	
}

int main () {
 livre *ktouba;
 char name[50];
 int p,o, n=50;
 ktouba=(livre*)malloc(50*sizeof(livre));
 lire_fichier_livres(ktouba, &n);
 printf("Entrez votre nom pour commencer :\n");
 scanf("%s",name);
 printf("Choisissez un nombre :\n");
 chinwi : printf("1-Ajouter un livre.\n2-Supprimer un livre selon ID\n3-Modifier un livre selon un titre\n4-Afficher les livres\n5-Rechercher les livres\n6-Tri par categori\n");
 scanf("%d",&p);
 switch (p) {
 case 1 : ajouter(ktouba,n);break;
 case 2 : supprimer(ktouba,n);break;
 case 3 : modifier(ktouba,n);break;
 case 4 : afficher(ktouba,n);break;
 case 5 : hna : printf("1-Titre\n2-Auteur\n0-Retour\n");scanf("%d",&o);
 switch (o) {
 case 0 : goto chinwi;break;
 case 1 : rechercher_titre(ktouba,n);break;
 case 2 : rechercher_auteur(ktouba,n);break;
 default :  printf("Choix erronnee\n"); goto hna;
 }
 case 6 : Tri_categori(ktouba,n);break;
 default : printf("Choix erronnee\n");
 }
  return 0;
}
