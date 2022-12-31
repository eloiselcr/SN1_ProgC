#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h >


// FONCTION NOMBRE DE JOUEURS
/*
int main(int argc, char** argv) 
{

	int nbjoueurs = 0;
	while (nbjoueurs <= 0 || nbjoueurs > 6)
	{
		printf("Rentrer le nombre de joueur : ");
		scanf("%d", &nbjoueurs);
		
		if (nbjoueurs <= 0 || nbjoueurs > 6)
		{
			printf("Ce nombre de joueurs n'est pas valide. Pour rappel, celui-ci doit etre entre 0 et 6 pour respecter les regles.\n\n");
		}
	}

	printf("Le nombre de joueurs est de : %d", nbjoueurs);

	return(0);
}
*/


// FONCTION INITIALISATION DES DONNEES DE PARTIE (à mettre au début)
/*
int main(int argc, char** argv)
{
	char namej1, namej2, namej3, namej4, namej5, namej6;

	int tours = 10;
	int comptage = 0;

	int t1l1j1 = 0, t1l1j2 = 0, t1l1j3 = 0, t1l1j4 = 0, t1l1j5 = 0, t1l1j6 = 0;
	int t1l2j1 = 0, t1l2j2 = 0, t1l2j3 = 0, t1l2j4 = 0, t1l2j5 = 0, t1l2j6 = 0;

	int t2l1j1 = 0, t2l1j2 = 0, t2l1j3 = 0, t2l1j4 = 0, t2l1j5 = 0, t2l1j6 = 0;
	int t2l2j1 = 0, t2l2j2 = 0, t2l2j3 = 0, t2l2j4 = 0, t2l2j5 = 0, t2l2j6 = 0;

	int t3l1j1 = 0, t3l1j2 = 0, t3l1j3 = 0, t3l1j4 = 0, t3l1j5 = 0, t3l1j6 = 0;
	int t3l2j1 = 0, t3l2j2 = 0, t3l2j3 = 0, t3l2j4 = 0, t3l2j5 = 0, t3l2j6 = 0;

	int t4l1j1 = 0, t4l1j2 = 0, t4l1j3 = 0, t4l1j4 = 0, t4l1j5 = 0, t4l1j6 = 0;
	int t4l2j1 = 0, t4l2j2 = 0, t4l2j3 = 0, t4l2j4 = 0, t4l2j5 = 0, t4l2j6 = 0;

	int t5l1j1 = 0, t5l1j2 = 0, t5l1j3 = 0, t5l1j4 = 0, t5l1j5 = 0, t5l1j6 = 0;
	int t5l2j1 = 0, t5l2j2 = 0, t5l2j3 = 0, t5l2j4 = 0, t5l2j5 = 0, t5l2j6 = 0;

	int t6l1j1 = 0, t6l1j2 = 0, t6l1j3 = 0, t6l1j4 = 0, t6l1j5 = 0, t6l1j6 = 0;
	int t6l2j1 = 0, t6l2j2 = 0, t6l2j3 = 0, t6l2j4 = 0, t6l2j5 = 0, t6l2j6 = 0;

	int t7l1j1 = 0, t7l1j2 = 0, t7l1j3 = 0, t7l1j4 = 0, t7l1j5 = 0, t7l1j6 = 0;
	int t7l2j1 = 0, t7l2j2 = 0, t7l2j3 = 0, t7l2j4 = 0, t7l2j5 = 0, t7l2j6 = 0;

	int t8l1j1 = 0, t8l1j2 = 0, t8l1j3 = 0, t8l1j4 = 0, t8l1j5 = 0, t8l1j6 = 0;
	int t8l2j1 = 0, t8l2j2 = 0, t8l2j3 = 0, t8l2j4 = 0, t8l2j5 = 0, t8l2j6 = 0;

	int t9l1j1 = 0, t9l1j2 = 0, t9l1j3 = 0, t9l1j4 = 0, t9l1j5 = 0, t9l1j6 = 0;
	int t9l2j1 = 0, t9l2j2 = 0, t9l2j3 = 0, t9l2j4 = 0, t9l2j5 = 0, t9l2j6 = 0;

	int t10l1j1 = 0, t10l1j2 = 0, t10l1j3 = 0, t10l1j4 = 0, t10l1j5 = 0, t10l1j6 = 0;
	int t10l2j1 = 0, t10l2j2 = 0, t10l2j3 = 0, t10l2j4 = 0, t10l2j5 = 0, t10l2j6 = 0;
	int t10l3j1 = 0, t10l3j2 = 0, t10l3j3 = 0, t10l3j4 = 0, t10l3j5 = 0, t10l3j6 = 0;

	int t1j1tot = 0, t1j2tot = 0, t1j3tot = 0, t1j4tot = 0, t1j5tot = 0, t1j6tot = 0; // Score des 2 lancés pour le Tour 1
	int t2j1tot = 0, t2j2tot = 0, t2j3tot = 0, t2j4tot = 0, t2j5tot = 0, t2j6tot = 0; // Score des 2 lancés pour le Tour 2
	int t3j1tot = 0, t3j2tot = 0, t3j3tot = 0, t3j4tot = 0, t3j5tot = 0, t3j6tot = 0; // Score des 2 lancés pour le Tour 3
	int t4j1tot = 0, t4j2tot = 0, t4j3tot = 0, t4j4tot = 0, t4j5tot = 0, t4j6tot = 0; // Score des 2 lancés pour le Tour 4
	int t5j1tot = 0, t5j2tot = 0, t5j3tot = 0, t5j4tot = 0, t5j5tot = 0, t5j6tot = 0; // Score des 2 lancés pour le Tour 5
	int t6j1tot = 0, t6j2tot = 0, t6j3tot = 0, t6j4tot = 0, t6j5tot = 0, t6j6tot = 0; // Score des 2 lancés pour le Tour 6
	int t7j1tot = 0, t7j2tot = 0, t7j3tot = 0, t7j4tot = 0, t7j5tot = 0, t7j6tot = 0; // Score des 2 lancés pour le Tour 7
	int t8j1tot = 0, t8j2tot = 0, t8j3tot = 0, t8j4tot = 0, t8j5tot = 0, t8j6tot = 0; // Score des 2 lancés pour le Tour 8
	int t9j1tot = 0, t9j2tot = 0, t9j3tot = 0, t9j4tot = 0, t9j5tot = 0, t9j6tot = 0; // Score des 2 lancés pour le Tour 9
	int t10j1tot = 0, t10j2tot = 0, t10j3tot = 0, t10j4tot = 0, t10j5tot = 0, t10j6tot = 0; // Score des 2 lancés pour le Tour 10

	int scoretotalj1 = 0, scoretotalj2 = 0, scoretotalj3 = 0, scoretoralj4 = 0, scoretotalj5 = 0, scoretotalj6 = 0;


	printf("Bienvenue dans le jeu du Bowling !\n");

	int nbjoueurs = 0;
	while (nbjoueurs <= 1 || nbjoueurs > 6)
	{
		printf("Rentrer le nombre de joueur : ");
		scanf("%d", &nbjoueurs);

		if (nbjoueurs <= 1 || nbjoueurs > 6)
		{
			printf("Ce nombre de joueurs n'est pas valide. Pour rappel, celui-ci doit etre entre 1 et 6 pour respecter les regles.\n\n");
		}
	}

	printf("Le nombre de joueurs est de : %d", nbjoueurs);

	while (comptage < tours)
	{
		printf("Le joueur 1 entre sur la piste. Appuyez sur '*' pour lancer votre boule.");

	}


}
*/
