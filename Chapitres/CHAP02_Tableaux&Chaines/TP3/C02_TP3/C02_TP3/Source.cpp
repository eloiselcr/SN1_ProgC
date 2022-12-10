#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


// 5 / 5 exercices



// -------  Exercice 1 ------- 

	// Ecrire un programme qui saisit une chaine de caracteres au clavier et qui l affiche dans l’ordre inverse.
	// Exemple : PASCAL LACSAP


/*
int main()
{
		char str[10];
		int i = 9;

		str[0] = 'P';
		str[1] = 'A';
		str[2] = 'S';
		* (str + 3) = 'C';
		* str(str + 2 + 2) = 'A';
		* str(str + 1 + 1 + 1 + 1 + 1) = 'L';
		* str(str + 6 * 1) = 0x00; // = '\0';

		i = strlen(str);

		while (i >= 0)
		{
			printf("%c", str[i]);
			i--;
		}

		return 0;

}
*/


// ------- Exercice 2 -------

	// Ecrivez un programme qui cherche la premiere occurrence d'un caractere (donne par l utilisateur) 
	// dans une chaine (donnee par l utilisateur) en partant de la droite.
	// 
	//	Ex : chaine entree : « le langage C est un langage extraordinaire » et le caractere a rechercher est le ‘a’.
	//	Le resultat attendu a l ecran est le suivant :
	//	« Le caractere a se trouve a la position 4 a partir de la droite. » 


/*
int main()
{
	char strphrase[100];
	char strcaractere;
	int i;
	int compteur = 1;


	printf("Rentrer la phrase  :");
	gets_s(strphrase, 100);
	printf("Rentrer le caractère recherche : ");
	scanf("%c", &strcaractere) ;

	for (i = strlen(strphrase) - 1; i >= 0; i--)
	{
		if (strphrase[i] != strcaractere)
		{
			compteur = compteur + 1;
		}
		else break;
	}

	if (compteur == strlen(strphrase))
	{
		printf("Le caractere n'est pas présent dans la phrase.");
	}
	else
	{
		printf("Le caractere %c se trouve a la position %d dans la phrase.", strcaractere, compteur);
	}

	return 0;
}
*/


// ------- Exercice 3 -------

	// Ecrire un programme qui saisit une chaine de caracteres au clavier et qui compte le
	// nombre de fois que chacune des lettres de l alphabet et le nombre d espaces ont ete
	// presents dans la phrase.

/*
int main(int argc, char ** argv)
{
	char chainCharacter[100] = "", tabC[52], cMin, cMaj;
	int i, j = 0, t = 0, a, b, e = 0;

	//printf("Les lettres de l alphabet en minuscule : ");
	for (cMin = 'a'; cMin <= 'z'; cMin++)
	{
		//printf("%c", cMin);
		tabC[t] = cMin;
		t++;
	}
	//printf("\n");

	//printf("Les lettres de l alphabet en majuscule : ");
	for (cMaj = 'A'; cMaj <= 'Z'; cMaj++)
	{
		//printf("%c", cMaj);
		tabC[t] = cMaj;
		t++;
	}
	//printf("\n");
	printf("Mon tableau de l alphabet est : ");
	for (a = 0; a < t; a++)
	{
		printf("%c", tabC[a]);
	}
	printf("\n\nSaisir une chaine de caracteres svp :\n");
	fgets(chainCharacter, 100, stdin);
	for (i = 0; chainCharacter[i] != '\0'; i++)
	{
		for (b = 0; b < t; b++)
		{
			if (chainCharacter[i] == tabC[b])
			{
				j++;
			}
		}
		if (chainCharacter[i] == ' ')
		{
			e++;
		}
	}
	printf("\nLe nombre de lettre de l alphabet est de %d et d espaces dans votre chaine est de %d\n", j, e);
	return(0);
}
*/


// ------- Exercice 4 -------

	// Ecrivez un programme en C qui saisit une chaine donnee par l utilisateur et qui
	// convertit les eventuelles majuscules en minuscules.

/*
int main(int argc, char ** argv)
{
	char chaine1[100], tMaj[26], cMaj;
	int i, k, c = 0;
	for (cMaj = 'A'; cMaj <= 'Z'; cMaj++)
	{
		tMaj[c] = cMaj;
		c++;
	}
	printf("Rentrez votre chaine de caracteres de 100 caracteres max\n");
	fgets(chaine1, 100, stdin);
	for (i = 0; chaine1[i] != '\0'; i++)
	{
		for (k = 0; k < c; k++)
		{
			if (chaine1[i] == tMaj[k])
			{
				chaine1[i] = tolower(chaine1[i]);
			}
		}
	}
	printf("Votre chaine sans majuscules donne : %s", chaine1);
	return(0);
}
*/


// ------- Exercice 5 -------

	// Realisez un programme permettant de saisir une chaine de caracteres ayant
	// eventuellement des espaces puis de traiter cette chaîne sans espaces.
	// Vous afficherez cette chaine sans espaces.

/*
int main(int argc, char ** argv)
{
	char chaine2[100], res[100];
	int i, j = 0;
	printf("Rentrez votre chaine de caracteres : ");
	fgets(chaine2, 100, stdin);
	for (i = 0; chaine2[i] != '\0'; i++)
	{
		if (chaine2[i] != ' ')
		{
			res[j] = chaine2[i];
			j++;
		}
	}
	res[j] = '\0';
	printf("Votre chaine sans espaces donne : %s", res);
	return (0);
}
*/