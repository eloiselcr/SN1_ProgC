#include <SFML/Graphics.hpp>
#include "Player.h"

// Constructeur de la classe Player
Player::Player(int y, int width, int height) {

	this->y = y;
	this->size.x = width;
	this->size.y = height;

	// Définition de la taille, de la couleur et de la position de la forme 
	shape.setSize(this->size);
	shape.setFillColor(sf::Color::White);
	shape.setPosition(sf::Vector2f(400 - (size.x / 2), y));
}

Player::~Player() { // Destructeur 
}

void Player::draw(sf::RenderWindow& window) { // Dessine la forme du joueur 
	window.draw(shape);
}

sf::Vector2f Player::getPosition() { // Retourne la position actuelle 
	return this->shape.getPosition();
}

sf::Vector2f Player::getSize() { // Retourne la taille 
	return this->size;
}

sf::RectangleShape& Player::getShape() { // Retourne la forme
	return shape;
}

// Déplace le joueur en fonction de la position de la souris
void Player::move(const sf::Vector2f& mousePosition, float deltaTime) {
	// Calculer la nouvelle position du joueur en fonction de la position de la souris
	position.x = mousePosition.x - size.x / 2.f;
	position.y = y;

		if (position.x < 0) {
			position.x = 0;
		}
		else if (position.x + size.x > 800) { 
			position.x = 800 - size.x;
		}
	shape.setPosition(position); // Déplacer le joueur
}

