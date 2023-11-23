#pragma once

#include "Player.h"
#include "Brique.h"
#include <SFML/Graphics.hpp>

class Ball { // METHODES PRIVEES 

private:

	sf::CircleShape shape; // Forme
	sf::Vector2f oldPosition; // Ancienne position 
	sf::Vector2f position; // Position actuelle 

	float speed; // Vitesse 
	int radius; // Rayon 
	sf::Vector2f direction; // Direction 

	static bool isRandInitialized;

	double randomizeAngle(); 
	void setAngle(double angle); // D�finit l'angle de la direction 


public: // -- METHODES PUBLIQUES --

	Ball(int x, int y, int radius, float speed); // Constructeur de la classe Ball
	~Ball(); // Destructeur 

	void move(float elapsedTime); // D�place la balle en fonction du temps �coul�
	void draw(sf::RenderWindow& window); // Dessine la balle 

	float getSpeed() const; // Retourne la vitesse 
	void setSpeed(float newSpeed); // D�finit la vitesse 

	void setPosition(sf::Vector2f newPosition); // D�finit la position 
	void setDirection(sf::Vector2f newDirection); // D�finit la direction 

	sf::Vector2f getPosition() const; // Retourne la position 
	sf::CircleShape& getShape(); // Retourne la forme 

	void manageCollisionWith(Player& player, sf::RenderWindow& window); // G�re les collisions de la balle avec le joueur
	bool checkCollisionWith(Player& player); // V�rifie collision entre balle etjoueur
	void manageCollisionWithBrique(Brique& brique); // G�re les collisions de la balle avec une brique
};