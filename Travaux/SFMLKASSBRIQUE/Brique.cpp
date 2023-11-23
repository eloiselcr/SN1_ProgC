#include "Brique.h"

// Constructeur de la classe Brique
Brique::Brique(int x, int y, int width, int height, int vie) {
	this->position = sf::Vector2f(x, y);
	this->size = sf::Vector2f(width, height);
	this->shape = sf::RectangleShape(size);
	this->vie = vie;
	shape.setFillColor(sf::Color::Green); 
	this->shape.setOutlineColor(sf::Color::White); // Blanc
	this->shape.setOutlineThickness(1); // Largeur 1 pixel pour le contour
	this->lastCollisionTime = 0; 
}

Brique::~Brique() { // Destructeur 
}

void Brique::draw(sf::RenderWindow& window) { // Dessine la brique sur la fenêtre spécifiée si elle est encore en vie
	if (enVie()) {
		shape.setPosition(position);
		window.draw(shape);
	}
}

sf::Vector2f Brique::getPosition() { // Retourne la position 
	return position;
}

sf::Vector2f Brique::getSize() { // Retourne la taille 
	return size;
}

sf::RectangleShape Brique::getShape() { // Retourne la forme 
	return shape;
}

bool Brique::enVie() { // Vérifie si la brique est encore en vie
	return vie > 0;
}

// Réduit la santé de la brique lorsqu'elle est encore en vie et met à jour sa couleur
void Brique::hit() {
	if (enVie()) {
		if (clock.getElapsedTime().asSeconds() - lastCollisionTime >= 0.1) {
			vie--;
			setColor();
			lastCollisionTime = clock.getElapsedTime().asSeconds();
		}
	}
}

void Brique::setColor() { // Change la couleur de la brique en fonction de sa santé
	this->shape.setOutlineColor(sf::Color::White); // Blanc
	this->shape.setOutlineThickness(1); // Largeur de 1 pixel pour le contour
	if (this->vie == 2) {
		this->shape.setFillColor(sf::Color(255, 165, 0)); // Orange
	}
	else if (this->vie == 1) {
		this->shape.setFillColor(sf::Color::Red); // Rouge
	}
}

bool Brique::operator==(const Brique& other) const { // Surcharge de l'opérateur 
	// Renvoyer true si cette brique est la même que l'autre brique, sinon false
	return this == &other;
}

void Brique::destroyAndDelete(std::deque<Brique*>& briques) { // Détruit la brique et la supprime de la deque de briques
	briques.erase(std::remove(briques.begin(), briques.end(), this), briques.end());
	delete this; // Supprimer l'objet de la mémoire
}