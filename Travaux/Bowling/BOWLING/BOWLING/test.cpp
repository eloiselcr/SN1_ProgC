#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h >


int maint(int argc, char** argv)
{
	int total_joueurs = 0;

	while (total_joueurs <= 0 || total_joueurs > 6) // tant que le nombre
	{
		printf("Rentrer le nombre de joueur : ");
		scanf("%d", &total_joueurs);

		if (total_joueurs <= 0 || total_joueurs > 6)
		{
			printf("Ce nombre de joueurs n'est pas valide. Pour rappel, celui-ci doit etre entre 0 et 6 pour respecter les regles.\n\n");
		}
	}



	return(0);
}