#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <"functions.h">

// NOTE : utiliser des pointeurs pour venir chercher les valeurs en dehors des 
// autres fonctions ! ex : score, joueurs, lancer...

int saisir_joueur(char t_joueur)

// FONCTION saisir_joueur
// -> Cette fonction a pour but de remplir le tableau des joueurs en début de partie.
// Elle demande dans un 1er temps le nombre total de joueurs. En fonction
// de cette variable, on remplit dans une boucle x fois le nombre de joueurs, les
// informations.

{
	int total_joueurs = 0;
	int counter = 0;

	while (total_joueurs <= 0 || total_joueurs > 6) 
	{
		printf("Rentrer le nombre de joueur : ");
		scanf("%d", &total_joueurs);

		if (total_joueurs <= 0 || total_joueurs > 6)
		{
			printf("Ce nombre de joueurs n'est pas valide. Pour rappel, celui-ci doit etre entre 0 et 6 pour respecter les regles.\n\n");
		}
	}

	struct Joueurs InfoJoueurs[total_joueurs];

	for (counter = 0; counter < total_joueurs; counter++)
	{
		printf("\n Entrez le nom du joueur : ");
		scanf("%s", &InfoJoueurs[counter].nom);

	}

}


int jouer(int *t_score, int joueur, int tour, int lancer)

// FONCTION jouer
// -> Cette fonction gère le déroulement de la partie de bowling. Dans une boucle de
// 10 tours, on demande à chaque joueurs de venir tirer 2 fois en utilisant la fonction
// srand. 
// **** IMPORTANT : 
// 1) Inclus dans une condition : si le joueur fait un strike, alors celui-ci ne 
// joue pas une seconde fois.
// 2) Durant le 10eme tours, si un joueur fais un strike ou un spare, alors celui-ci
// a le droit a un lancé supplémentaire.

{
	int tours = 0;
	int joueurplay = 1;

	printf("La partie peut commencer !");

	// Boucle (pour tours = 0; tours = 10, tours++)
	// {
	//   Boucle (pour joueurs = 0; joueurs < joueurs_max; joueurs++)
	//    {
	//      Afficher ("C'est au joueur n° %d de s'avancer au pupitre !", joueurplay);
	//      Afficher ("Veuillez appuyer sur '*' pour lancer votre boule.");
	//		Si (* est entré par l'utilisateur)
	//         {
	//       srand
	//         }
	//      Sinon
	//         {
	//           Afficher("Merci d'appuyer sur la bonne touche !");
	//         }
	// 
	//		joueurplay++;
	//    }
	//  tours++;
	// }
}


void remplir_tableau_score(t) // t([0][0][0]=9) // t([0][0][1]=1) // t([0][1][0]=9)

// FONCTION remplir_tableau_score
// -> A chaque fois qu'un coup est tiré, il faut attribuer le lancé au bon joueur.
{
	
}


void calculer_score(int *t_score)

// FONCTION calculer_score
// -> Cette fonction vient récupérer les données de chaque lancés pour tous les 
// joueurs. On additionne chaque nombre d'une même ligne et on obtient un score 
// final du joueur.
{

}


void afficher_score(int *t_score)

// FONCTION afficher_score
// -> Cette fonction vient récupérer les scores finaux de chaque joueurs via
// calculer_score. Sans une boucle, elle vient trier chaque score par ordre croissant.
// Ainsi on arrive à un classement de joueurs, qu'on affiche ensuite.
{

	printf("La partie est finie ! Voici donc les scores pour chaque joueurs : \n\n");

}



