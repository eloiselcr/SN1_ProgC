#pragma once

#include <deque>
#include <SFML/Graphics.hpp>

class Brique {

private: // -- METHODES PRIVEES -- 

	sf::RectangleShape shape; // La forme 
	sf::Vector2f position; // Position 
	sf::Vector2f size; // Taille 
	int vie; // Nombre de vies restantes 
	sf::Clock clock; // Horloge utilis�e pour le suivi du temps
	float lastCollisionTime; // Temps de la derni�re collision avec la balle
	void setColor(); // D�finit la couleur de la brique en fonction de son nombre de vies


public: // -- METHODES PUBLIQUES -- 

	sf::Vector2f getPosition(); // Retourne la position 
	sf::Vector2f getSize(); // Retourne la taille 
	sf::RectangleShape getShape(); // Retourne la forme 


	Brique(int x, int y, int width, int height, int vie); // Constructeur de la classe Brique
	~Brique(); // Destructeur

	void draw(sf::RenderWindow& window); // Dessine la brique sur la fen�tre
	bool enVie(); // V�rifie si la brique est encore en vie
	void hit(); // R�duit le nombre de vies de la brique lorsqu'elle est touch�e
	bool operator==(const Brique& other) const; // Surcharge de l'op�rateur d'�galit� pour les briques
	void destroyAndDelete(std::deque<Brique*>& briques); // D�truit la brique et la supprime de la liste
};