#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>


// 3 / 3 Exercices 



// -------  Exercice 1 ------- 

	// Realiser le programme en langage C permettant de lire 10 nombres entiers dans un tableau
	// avant d en chercher le plus grand et le plus petit.

/*
int main(int argc, char** argv)
{
	int tab[10];
	for (int i = 0; i < 10; i++)
	{
		printf("Entrez le nombre %d : ", i + 1);
		scanf("%d", &tab[i]);
	}

	int min = tab[0];
	int max = tab[0];
	int i = 1;
	while (i < 10)
	{
		if (tab[i] < min)
		{
			min = tab[i];
		}
		if (tab[i] > max)
		{
			max = tab[i];
		}
		i = i++;
	}
	printf("Le minimum du tableau est %d, le maximum est %d.\n", min, max);
	return 0;
}
*/


// -------  Exercice 2 -------

	// Soient deux tableaux t1 et t2 declares ainsi :
	//		float t1[10], t2[10] ;
	// Realisez le programme en langage C permettant de recopier dans t1 tous les elements positifs de t2.

/*
int main(int argc, char** argv)
{
	int t2[10];
	float t3[10];
	int i, count, j = 0, nbTable, nombreTb, stockValue;

	printf("Rentrez le nombre d elements de votre tableau inferieur a 10 et superieur a 0 : \n");
	scanf("%d", &nbTable);

	while (nbTable < 0 && nbTable > 10)
	{
		printf("Rentrez le nombre d elements de votre tableau inferieur a 10 et superieur a 0 : \n");
		scanf("%d", &nbTable);
	}

	for (i = 0; i < nbTable; i++)
	{
		printf("Rentrez un nombre : \n");
		scanf("%d", &nombreTb);

		t2[i] = nombreTb;

		if (t2[i] > 0)
		{
			t3[j] = t2[i];
			j++;
		}
	}

	printf("\n");

	for (count = 0; count < nbTable; count++)
	{
		printf("%.f | ", t3[count]);
	}
}
*/


// -------  Exercice 3 -------

	// Soit le tableau t declare ainsi :
	//		float t[10] ;
	// Realisez un programme en C permettant de calculer dans une variable somme, la somme des elements de t.

/*
int main(int argc, char ** argv)
{
	float t[10], somme = 0;

	for (int i = 0; i < 10; i++)
	{
		printf("Entrez une valeur : ");
		scanf("%f", &t[i]);
		somme += t[i];
	}

	printf("La somme vaut %d.\n", somme);

	_getch();
	return 0;
}
*/

