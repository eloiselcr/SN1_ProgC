#pragma once


typedef struct Joueurs
{
	char nom[20]; // nom du joueur

	int lancer1[10]; // quilles abbatues au coup 1
	int lancer2[10]; // quilles abbatues au coup 2

	int total;

} Joueurs;