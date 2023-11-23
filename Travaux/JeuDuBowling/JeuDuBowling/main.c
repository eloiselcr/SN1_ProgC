#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>

#define JOUEURMAX 6 // Le nombre de joueurs max = 6
#define NOMBRES_TOURS 10 // Il y aura 10 Tours
#define LANCERMAX 2 // Chaque joueur joue 2 lancers par Tour
#define MAX_QUILLE 10 // 10 quilles sur la piste

typedef struct 
    // Structure pour les joueurs
{
    char nom[64]; // nom du joueur
    int scores[NOMBRES_TOURS][LANCERMAX]; // son score tour/lancer
    int total_score; // score total du joueur a la fin de la partie
} Joueur;

Joueur joueur[JOUEURMAX];
int nombrejoueur;

void nombresjoueurs() 

// FONCTION NOMBRESJOUEURS
// -> Demande le nombre maximum de joueurs et leurs noms.
{
    printf("Entrez le nombre de joueurs (maximum %d) : ", JOUEURMAX); // Demande combien de joueurs présents
    scanf("%d", &nombrejoueur);

    while (nombrejoueur > JOUEURMAX) // Si le nombre de joueur rentre depasse 6
    {
        printf("\nAttention ! Le nombre de joueurs ne peut pas depasser %d\n", JOUEURMAX);
        printf("Entrez le nombre de joueurs (maximum %d) : ", JOUEURMAX);
        scanf("%d", &nombrejoueur);
    }

    for (int i = 0; i < nombrejoueur; i++) // Demande les noms des joueurs 
    {
        printf("\nEntrez le nom du joueur %d : ", i + 1); 
        scanf("%s", joueur[i].nom);
    }

    printf("C'est tout bon !\n");
}

int lancer(int quille_rest) 

// FONCTION LANCER 
// -> Simule le lancer d'une quille de Bowling
{
    //return rand() % 11;
    return rand() % (quille_rest + 1);
}

void jouertour(int joueurs, int tour) 

// FONCTION JOUERTOUR
// -> Permet de jouer un tour pour le joueur
{
    printf("\n************ Tour %d ************ \n", tour+1); // Affiche le tour en cours

    char c = 'a';
    printf("\n%s, c'est a ton tour ! Avances toi sur la piste pour jouer...\n", joueur[joueurs].nom); // Appel du joueur 

        // LANCER 1

    printf("\n-- Premier lancer --\n");
    printf("Appuie sur * pour lancer la boule : ");
    c = _getch();

   while (c != '*') // Si le joueur n'appuie pas sur '*'
   {
     printf("\nTOUCHE BON SANG !!\n", joueur[joueurs].nom);
     c = _getch();
   }

   int lancer1 = lancer(MAX_QUILLE); // Au lancer1, toutes les quilles sont presentes

   if (lancer1 == MAX_QUILLE)
   { // Si Strike
     printf("Et c'est le Strike ! X\n");
     joueur[joueurs].scores[tour][0] = MAX_QUILLE;
     return;
   }
   if (lancer1 == 0)
   {
       printf("Rate ! Faudrait qu'on rajoute une fonction barrieres :p\n");
   }

   printf("BOOM ! Tu as abattu %d quilles\n", lancer1); // Si le joueur fait un lancer1 normal
   
   
        // LANCER 2

   int lancer2 = lancer(MAX_QUILLE - lancer1);

   printf("\n-- Deuxieme lancer --\n");
   printf("Appuie sur * pour lancer la boule : ");
   c = _getch();

   while (c != '*') // Si le joueur n'appuie pas sur '*'
   {
       printf("\nTOUCHE BON SANG !!\n", joueur[joueurs].nom);
       c = _getch();
   }

   if (lancer1 + lancer2 == MAX_QUILLE)
   { // Si Spare
     printf("Et c'est le Spare ! /\n\n");
     joueur[joueurs].scores[tour][0] = lancer1;
     joueur[joueurs].scores[tour][1] = MAX_QUILLE - lancer1;
   }
   else
   {
     printf("BOOM ! Tu as abattu %d quilles.\n\n", lancer2);
     joueur[joueurs].scores[tour][0] = lancer1; // On sauvegarde le lancer1
     joueur[joueurs].scores[tour][1] = lancer2; // On sauvegarde le lancer2
   }
}

void calculscore() 

// FONCTION CALCULSCORE
// -> Calcule les scores a chaque fin de partie.
{
    for (int i = 0; i < nombrejoueur; i++) // Pour tous les joueurs
    {
        int total_score = 0; // On initialise total_score a 0 pour tout le monde
        for (int j = 0; j < NOMBRES_TOURS; j++)  // A chaque tours realises
        {
            int score1 = joueur[i].scores[j][0]; // Score du lancer1
            int score2 = joueur[i].scores[j][1]; // Score du lancer2
            total_score += score1 + score2; // On additionne lancer1 + lancer2
            if (score1 == MAX_QUILLE) 
            { // Si Strike
                total_score += joueur[i].scores[j + 1][0] + joueur[i].scores[j + 1][1];
            }
            else if (score1 + score2 == MAX_QUILLE) 
            { // Si Spare
                total_score += joueur[i].scores[j + 1][0];
            }
        }
        joueur[i].total_score = total_score; 
    }
}

void afficherscore()

// FONCTION AFFICHERSCORE
// -> Permet d'afficher les scores pour chaque joueurs a la fin d'une partie.
{
    printf("\nEt c'est termine !");
    printf("\n\n******* TABLEAU DES SCORES *******\n\n");

    for (int i = 0; i < nombrejoueur; i++) // Pour tous le joueurs
    {
        printf("%s : ", joueur[i].nom);
        for (int j = 0; j < NOMBRES_TOURS; j++)
        {
            int score1 = joueur[i].scores[j][0];
            int score2 = joueur[i].scores[j][1];
            if (score1 == MAX_QUILLE) { // Strike
                printf("X ");
            }
            else
            {
                printf("%d %d |", score1, score2);
            }
        }
        printf("    Total : %d\n", joueur[i].total_score);
    }
}

void afficher_regles()

// FONCTION AFFICHER_REGLES
// -> Permet d'afficher les regles du jeu depuis le menu principal.
{
    printf("\nRegles du Bowling : \n");
    printf("1. Il y a 10 tours dans une partie de bowling.\n");
    printf("2. Chaque joueur a 2 lancers par tour.\n");
    printf("3. Le but est de renverser le plus de quilles possible avec chaque lancer.\n");
    printf("4. Si un joueur renverse toutes les quilles avec son premier lancer, c'est un 'strike'.\n");
    printf("5. Si un joueur renverse toutes les quilles restantes avec son deuxième lancer, c'est un 'spare'.\n");
    printf("6. Les scores sont calcules en fonction du nombre de quilles renversees.\n\n");
    printf("Appuyez sur une touche pour retourner au menu principal.\n\n\n");
    char c = _getch();
    while (c == 0 || c == 0xE0)
    {
        c = _getch();
    }
}

int main(int argc, char** argv)
{
    srand(time(NULL)); // Initialisation de la fonction rand
    
    int choix; // Choix a partir du MENU
    char rejouer; // Servira pour REJOUER

    printf("Bienvenue dans \n\n\n");

    Sleep(1000);

    printf("                        ********************\n");
    printf("                       *                    *\n");
    printf("                       *      Le Jeu        *\n");
    printf("                       *        du          *\n");
    printf("                       *      BOWLING       * \n");
    printf("                       *                    *\n");
    printf("                        ********************\n");
    printf("                         Burguet ~ Lecronier \n\n\n");

    do { // MENU PRINCIPAL 

        printf("Menu Principal : \n\n");

        printf("1. Lancer la partie \n");
        printf("2. Lire les regles \n");
        printf("3. Quitter le programme \n\n");

        printf("Quel est votre choix ? ");
        scanf("%d", &choix);


        switch (choix) // On initialize un switch pour le MENU en fonction du choix 
        {
        case 1: // Si l'utilisateur lance une partie 
            do
            { // On lance une partie de Bowling

                system("cls");
                printf("Bonne partie !\n");

                nombresjoueurs();

                for (int j = 0; j < NOMBRES_TOURS; j++)
                {
                    for (int i = 0; i < nombrejoueur; i++)
                    {
                        jouertour(i, j);
                    }
                }

                calculscore(); // Calcule des scores de la partie
                afficherscore(); // Affichage des scores de la partie

                printf("\nPressez 'y' pour rejouer, une autre touche pour sortir.\n\n"); // REJOUER ?
                rejouer = _getch();

            } while (rejouer == 'y');
            break;

        case 2: // L'utilisateur souhaite afficher les regles
            afficher_regles();
            break;

        case 3: // L'utilisateur souhaite quitter le programme 
            printf("Au revoir !\n");
            break;

        default: // L'utilisateur n'a pas appuye sur la bonne touche 
            printf("Choix non valide.\n");
            break;
        }

    } while (choix != 3);

    return 0;
}
