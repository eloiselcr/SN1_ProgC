#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


// 2 / 2 Exercices 



// -------  Exercice 1 ------- 

	// Soit le tableau t declare ainsi :
	//		float t[3][4];
	// Ecrire le programme permettant de calculer, dans une variable nommee somme, la somme des elements de t.

/*
int main(int argc, char** argv)
{
	float t[3][4];
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			printf("Entrez la valeur [%d][%d] : ", i, j);
			scanf("%f", &t[i][j]);
		}
	}
	float somme = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			somme += t[i][j];
		}
	}
	printf("La somme vaut %f\n", somme);
	return 0;
}
*/


// -------  Exercice 2 -------

	// Soit le tableau t declare ainsi : 
	//		float t[3][4];
	// Et le tableau m ainsi declare :
	//		float m[3];
	// Ecrire le programme qui calcule la moyenne de chaque ligne du tableau t et le stocke dans la case 
	// correspondante du tableau m.

/*
int main(int argc, char ** argv)
{
	srand(time(NULL));
	float t[3][4];
	float m[3];
	int i = 0;
	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			t[i][j] = rand() % 100;
		}
	}
	while (i < 3)
	{
		float somme = 0;
		j = 0;
		while (j < 4)
		{
			somme + t[i][j];
			j++;
		}
		m[i] = somme / 4.0;
		i++;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%6.2, ", t[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 3; i++)
	{
		printf("Moyenne %d : %f\n", i + 1, m[i]);
	}
	return 0;
}
*/