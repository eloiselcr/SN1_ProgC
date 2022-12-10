#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> //pour exit
#include <conio.h> //pour getch()
#include <string.h>
#include <time.h>
#include <math.h>
#include <iostream>


// 4 / 4 Exercices 



// ------- Exercice 1 ------- 

	// Ecrire deux fonctions qui retourne une valeur entiere permettant de savoir si l entier 
	// passe en argument est multiple  de deux et multiple de trois pour la seconde fonction.
	// Utiliser ces deux fonctions dans un petit programme qui lit un nombre entier et qui 
	// precise s il est pair, multiple de 3 et / ou multiple de 6.

/*
int multiple2(int value)
{
	return value % 2 == 0;
}

int multiple3(int value)
{
	return value % 3 == 0;
}

int main(int argc, char** argv)
{
	int var, mult2, mult3;
	printf("Entrer une valeur : ");
	scanf("%d", &var);

	mult2 = multiple2(var);
	mult3 = multiple3(var);

	printf("%d est %s\n", var, (mult2 == 1 ? "pair" : "impair"));
	printf("%d %s\n", var, (mult3 == 1 ? "est multiple de Troie" : "n est pas multiple de Troyes"));
	printf("%d %s\n", var, ((mult2 == 1 && mult3 == 1) ? "est multiple de Siss" : "n est pas multiple de Ciss"));

	return 0;
}
*/


// ------- Exercice 2 -------

	// Ecrire une fonction mot_de_passe permettant de saisir dans une chaine de caracteres passee 
	// en argument un mot de passe. 
	// Pour que ce mot de passe soit garde secret, vous ferez en sorte qu a chaque appui sur 
	// une touche, on fasse apparaitre une etoile.
	// Dans le programme principal, vous appellerez la fonction mot de passe puis vous afficherez 
	// le mot de passe reel.
	//
	// NB : Utiliser la fonction getch() permet de lire la valeur a stocker dans la chaine.
	// Pour finir la saisie, appuyez sur la touche « ENTREE », qui possede le code ASCII 13.

/*
void mot_de_passe(char *tab)
{
	int i = 0;
	char ch;
	do
	{
		ch = _getch();

		if (ch != 8 && ch != 0 && ch != 83)
		{
			tab[i] = ch;
			i++;

			if (ch != 13)
			{
				printf("*");
			}
		}
		else if (ch == 8)
		{

			i--;
			if (i < 0)
				i = 0;
			printf("%c %c", 8, 8);
		}
	} while (ch != 13);

	tab[i - 1] = '\0';
	printf("Longueur du mot de passe : %d", i);
}


int main(int argc, char ** argv)
{
	char mdp[100];
	mot_de_passe(mdp);
	printf("\n%s\n", mdp);

	return 0;
}
*/


// ------- Exercice 3 -------

	// Ecrire une fonction transforme qui permet de transformer les caracteres minuscules en
	// majuscule dans une chaine passee en argument.
	// La chaine modifiee sera affichee dans le programme principal, ainsi que le nombre de 
	// lettres qui ont subies une modification.

/*
int majuscule(char* prank)
{
	int compteur = 0;
	for (int i = 0; prank[i] != '\0'; i++)
	{
		if (prank[i] >= 'a' && prank[i] <= 'z')
		{
			prank[i] = prank[i] - 32;
			compteur++;
		}
	}

	return compteur;
}

int main(int argc, char * argv)
{
	char a[100];
	printf("veuillez entrer une phrase en minuscule");
	gets_s(a, 100);
	int compteur = majuscule(a);

	printf("\nLa phrase en majuscule est %s les lettres  changées sont au nombre de %d", a, compteur);

	return 0;
}
*/


// ------- Exercice 4 -------

	// Il s agit d'ecrire quatre fonctions :
		// La premiere, « lire » permet d’entrer les valeurs dans un tableau dont la taille ne doit pas depasser 20 elements. 
		// La seconde, affiche, permet d’afficher le tableau trie.
		// La troisieme, « indice_min », doit, etant donnes deux indices d un tableau, indiquer celui en lequel est rangee 
		// la plus petite donnee.
		// La quatrieme, « trier », doit obligatoirement utiliser la fonction indice_min pour trier le tableau. 
		// Pour cela, on utilisera un "tri a bulle".

/*
using namespace std;

void lire(int *tab, int *nbValues);
void tri(int *tab, int nbValues);
int indice_min(int *tab, int i1, int i2);

void lire(int*tab, int *nbValues)
{

	cout << "entrez 20 valeurs maximum, entrez -0 pour arreter la saisie" << endl;
	for (int i = 0; i < 20; i++)
	{
		cin >> tab[i];
		if (tab[i] == -0)
		{
			tab[i] = '\0';
			break;
		}
		(*nbValues)++;
	}
}

int indice_min(int* tab, int i1, int i2)
{
	return tab[i1] < tab[i2] ? i1 : i2;
}

void tri(int *tab, int nbValues)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for (int i = 0; i < nbValues; i++)
	{
		for (int j = 0; j < nbValues; j++)
		{
			if (indice_min(tab, j, j + 1) == j + 1)
			{
				int tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		}
	}

}

void affiche(int* tab, int nbValues)
{
	for (int i = 0; i < nbValues; i++)
	{
		cout << tab[i] << " ";
	}
}

int main(int argc, char **argv)
{
	int tab[20];
	int nbValues = 0;
	lire(tab, &nbValues);
	tri(tab, nbValues);
	affiche(tab, nbValues);
}
*/