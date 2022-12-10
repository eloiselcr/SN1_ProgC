#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h> //pour getch()


// 4 / 5 Exercices 



// -------  Exercice 1 -------

	// Ecrire un programme qui calcule le produit de 2 nombres a et b, sans utiliser 
	// l operation de multiplication.

/*
int main(int argc, char ** argv)
{
	float a;
	float b;
	float temp;
	int I = 1;

	printf("saisir un nombre  :");
	scanf_s("%f", &a);

	temp = a;

	printf("saisir un nombre :");
	scanf_s("%f", &b);

	for (I; I < b; I++)
	{
		a += temp;
	}

	printf("Le resultat de la multiplication est de %.2f", a);
}
*/


// -------  Exercice 2 -------

	// Ecrire un programme qui permet d entrer 3 nombres entiers au clavier, puis les affiche 
	// a l ecran dans l’ordre croissant.

/*
int main(int argc, char ** argv)
{
	int a = 0, b = 0, c = 0, max, mil, min;

	printf("Entrez trois nombres entier :");
	scanf("%d %d %d", &a, &b, &c);

	if (a > b && a > c) { max = a; }
	if (b > a && b > c) { max = b; }
	if (c > b && c > a) { max = c; }
	if (a > b && a < c) { mil = a; }
	if (b > a && b < c) { mil = b; }
	if (c > b && c < a) { mil = c; }
	if (a < b && a < c) { min = a; }
	if (b < a && b < c) { min = b; }
	if (c < b && c < a) { min = c; }

	printf("Rangement en ordre croissante : %d %d %d", min, mil, max);
}
*/


// -------  Exercice 3 -------

	// Les tarifs d affranchissement d une lettre sont les suivants :
	//		Au dessous de 20 g : 3.00 frs
	//		A partir de 20 g et endessous de 50 g : 3.95 frs
	//		A partir de 50 g : 5.90 frs
	// Ecrire le programme qui delivre le tarif pour un poids (donne au clavier).

/*
int main(int argc, char ** argv)
{
	float poids;

	printf("Saisir un nombre : ");
	scanf_s("%f", &poids);

	if (poids < 20)
	{
		printf("Vous devez payer 3frs.");
	}
	if (poids >= 20 && poids < 50)
	{
		printf("Vous devrez payer 3.95frs.");
	}
	else {
		printf("Vous devez payer 5.90frs.");
	}
}
*/


// -------  Exercice 4 -------

	// On desire effectuer un questionnaire aupres des eleves d un lycee afin de connaitre
	// mieux leurs activites extra - scolaires.
	// Réalisez un programme demandant a chaque eleve, son age, son sexe, le nombre de fois ou 
	// il va au cinema par mois, si il prefere le Quick ou le Mac Donald, le nombre de fois ou il 
	// y va par mois, si il pratique un sport et si oui pratique t-il un sport parmi :
	//		foot, tennis, basket, judo, natation ? 
	// Quand l’eleve a entre toutes les informations, affichez lui le recapitulatif des reponses 
	// a son questionnaire, puis passez a l eleve suivant.

/*
int main(int argc, char** argv)
{
	char nom[50], genre[5], food[50], nomsport[30];
	int age, cinema, numfood, pratiquesport=0, sportliste;


	printf("------ Bienvenue sur la fiche de renseignement ! ------\n\n");
	printf("Veuillez repondre a ces questions : \n\n");

	printf("Votre nom : "); // nom
	scanf("%s", nom);
	printf("Votre age : "); // age
	scanf("%d", &age);
	printf("Votre genre (H/F/NB) : "); // genre
	scanf("%s", genre);
	printf("Combien de fois allez vous au cinema par mois ? "); // cinema
	scanf("%d", &cinema);
	printf("Preferez vous Quick ou Mac Donald ? "); // food
	scanf("%s", food);
	printf("Combien de fois y allez vous par mois ? "); // food par mois
	scanf("%d", &numfood);
	printf("Pratiquez vous un sport ? (1/0) "); // pratique sport
	scanf("%d", pratiquesport);

	if (pratiquesport == 1)
	{
		printf("Pratiquez vous un sport parmi : foot, tennis, basket, judo ou natation ? (1/0) ");
		scanf("%d", &sportliste);

		if (sportliste == 1)
		{
			printf("Lequel ?");
			scanf("%s", nomsport);
		}
	}

	printf("====-====-====- BIENVENUE %s -====-====-====\n\n", nom);
	printf("Voici ton recapitualtif : \n");

	printf("Nom : %s", nom);
	printf("Age : %d", age);
	printf("Ton genre : %s", genre);
	printf("Vous allez %d fois au cinema par mois.", cinema);
	printf("Vous preferez le fast food %s, d'ailleurs vous y allez %d fois par mois.", food, numfood);
	if (pratiquesport == 1)
	{
		printf("Vous pratiquez un sport qui est le/la %s.", nomsport);
	}
	else
	{
		printf("Vous ne pratiquez pas de sport.");
	}
	printf("Merci d'avoir repondu !\n\n");
}
*/

// -------  Exercice 5 -------	

	// Ecrire un programme qui affiche « la table de multiplication » des nombres de 1 a x, sous la 
	// forme ci-dessous, x etant une donnee entree au clavier comprise entre 2 et 10 :

/*
int main(int argc, char ** argv)
{
	int x = 0, i, j, resultat;

	while (x < 2 || x > 10)
	{
		printf("Rentrez une valeur de x comprise entre 2 et 10 : ");
		scanf("%d", &x);
	}

	printf("\t|");

	for (i = 1; i <= x; i++)
	{
		printf("%3d ", i);
	}

	printf("\n-------------------------------------------------------\n");

	for (i = 1; i <= x; i++) {
		printf("%d	|", i);

		for (j = 1; j <= x; j++) {
			resultat = i * j;
			printf("%3d ", resultat);
		}

		printf("\n");
	}
}
*/
