#pragma once


typedef struct Joueurs
{
	char nom[20]; // nom du joueur
	int numero; // numero du joueur 

	int lancer1[10]; // quilles abbatues au coup 1
	int lancer2[10]; // quilles abbatues au coup 2

	int scoretotal; // Score total en fin de partie 

} Joueurs;