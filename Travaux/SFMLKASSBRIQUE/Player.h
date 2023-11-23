#pragma once

#include <SFML/Graphics.hpp>

class Player {

private: // -- METHODES PRIVEES -- 

	sf::RectangleShape shape; // La forme 
	sf::Vector2f position; // Position 
	sf::Vector2f size; // Taille 
	int y; // Coordonnée y fixe 


public: // -- METHODES PUBLIQUES -- 

	Player(int y, int width, int height); // Constructeur de la classe Player
	~Player(); // Destructeur 

	void draw(sf::RenderWindow& window); // Dessine le joueur sur la fenêtre
	sf::Vector2f getPosition(); // Retourne la position 
	sf::Vector2f getSize(); // Retourne la taille 	
	sf::RectangleShape& getShape(); // Retourne la forme 
	void move(const sf::Vector2f& mousePosition, float deltaTime); // Déplace le joueur en fonction de la position de la souris

};