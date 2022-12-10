#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>




// 2 / 5 Exercices 



// ------- Exercice 1 ------- 

	// adr1 et adr2 sont des pointeurs pointant sur des reels.
	// Le contenu de ou pointe adr1 vaut - 45, 78; le contenu de ou pointe adr2 vaut 678, 89.
	// Ecrire un programme qui ne contient que deux variables (adr1 et adr2) de type
	// pointeurs sur reel, qui stocke deux valeurs reelles (-45.78 et 678.89) et qui affiche les
	// adresses des espaces memoires qui stockent les deux reels ainsi que le contenu de
	// ces deux espaces.

/*
int main(int argc, char ** argv)
{
	float *ard1;
	float *ard2;

	ard1 = (float*)malloc(sizeof(float));
	ard2 = (float*)malloc(sizeof(float));

	*ard1 = -45.78;
	*ard2 = 678.89;

	printf("L'emplacement memoire de %.2f est %p.\n", *ard1, ard1);
	printf("L'emplacement memoire de %.2f est %p.\n", *ard2, ard2);

	return 0;
}
*/

/*
	printf("L'emplacement mémoire de ard1 (%f) est à %p\n", ard1, &f);
	printf("L'emplacement mémoire de ard2 (%f) est à %p\n", ard2, &f);
*/


// ------- Exercice 2 ------- 

	// Soit adr_deb un pointeur sur entiers, vous ferez en sorte que adr_deb pointe sur un
	// emplacement memoire suffisant afin de stocker 6 entiers donnes par l utilisateur.
	// Puis vous rangerez ces valeurs dans l ordre croissant.
	// Rechercher le maximum, l afficher ainsi que son adresse et sa position. 

/*
int main(int argc, char** argv)
{
	int* adr_deb;
	adr_deb = (int*)malloc(6 * sizeof(int));

	for (int i = 0; i < 6; i++)
	{
		printf("Rentrez un nombre : ");
		scanf("%d", adr_deb + i);
		printf("L'emplacement memoire est %p pour un contenu de %d\n", adr_deb + i, *(adr_deb + i));
	}

	int a;
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (*(adr_deb + i) > *(adr_deb))
			{
				a = *(adr_deb + i);
				*(adr_deb + i) = *(adr_deb + j);
				*(adr_deb + j) = a;
			}
		}
	}

	return 0;
}
*/


// ------- Exercice 3 ------- 

	// Soit une variable de type char *, ecrire un programme qui saisit une chaine de
	// caracteres et qui la stocke dans cette variable, puis qui affiche les elements de la
	// chaine caractere par caractere avec leur adresse.


// ------- Exercice 4 ------- 

	// tab1 et tab2 sont des variables locales a main :
	// int tab1[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
	// int tab2[] = { -19,18,-17,16,-15,14,-13,12,-11,10,-9,8,-7,6,-5,4,-3,2,-1,0 };
	// Ecrire une fonction de prototype void affiche(int *tab, int i, int j) qui permet
	// d afficher les i*j nombres suivant un tableau i x j (a l affichage i lignes et j colonnes).
	// La mettre en oeuvre dans main() pour afficher tab1 et tab2.


// ------- Exercice 5 ------- 

	// Calculer et afficher les racines de ax2+bx+c=0.
	// Une fonction de prototype void saisie(float *aa, float *bb, float *cc) permet de saisir
	// a, b, c.
	// Une fonction de prototype float *calcul(float aa, float bb, float cc) exécute les
	// calculs et renvoie les résultats.
	// a, b, c sont des variables locales a main();
	// main() se contente de saisir a, b et c puis d appeler saisie et calcul et d afficher les
	// solutions.