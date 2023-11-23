#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Brique.h"
#include "Ball.h"


double mapValue(double value, double min, double max, double nMin, double nMax) {
    double newVal = (((value - min) / (max - min)) * (nMax - nMin)) + nMin;
    return newVal;
}

int main(int argc, char** argv) {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Jojo l'abricot");

    std::deque<Brique*> briques;
    Player player(550, 100, 11);
    Ball ball(200, 250, 10, 550);

    int numBriqueLigne = 10; // Nombre de briques par ligne
    int BriqueLarg = 80; // Largeur d'une brique
    int BriqueHaut = 30; // Hauteur d'une brique
    int horizontalSpacing = (window.getSize().x - numBriqueLigne * BriqueLarg) / (numBriqueLigne + 1); // Espacement horizontal entre les briques
    int verticalSpacing = 30; // Espacement vertical entre les briques
    int nbLignes = 4; // Nombre de lignes de briques
    int nbColonnes = numBriqueLigne; // Nombre de colonnes de briques (identique au nombre de briques par ligne)
    for (int i = 0; i < nbLignes; i++) { // Boucle pour créer le nombre de lignes spécifié
        for (int j = 0; j < nbColonnes; j++) { // Boucle pour créer le nombre de briques spécifié par ligne
            int x = horizontalSpacing + j * (BriqueLarg + horizontalSpacing); 
            int y = verticalSpacing + i * (BriqueHaut + verticalSpacing); 
            briques.push_back(new Brique(x, y, BriqueLarg, BriqueHaut, 3)); // Création d'une nouvelle brique et ajout dans la deque
        }
    }

    sf::Clock clock;
    sf::Vector3f xFactor(10, 20, 30);
    float ellapsedTime = 0;

    while (window.isOpen()) {
        float deltaTime = clock.getElapsedTime().asSeconds();
        ellapsedTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
        player.move(mousePosition, deltaTime);

        ball.move(ellapsedTime);

        ball.manageCollisionWith(player, window);

        for (int i = 0; i < briques.size(); i++) {
            if (briques[i]->enVie()) {
                briques[i]->draw(window);
                ball.manageCollisionWithBrique(*briques[i]);
            }
            else {
                briques[i]->destroyAndDelete(briques);
            }
        }

        window.clear(sf::Color::Black);

        // -- PROF -- MULTICOLOR
        // double mappedValue = mapValue(ball.getPosition().x, 0, window.getSize().x, 0, 255);
        // double mappedValue2 = mapValue(ball.getPosition().y, 0, window.getSize().y, 0, 255);
        // double mappedValue3 = (mappedValue + mappedValue2) / 2.0;
        // rdr2.setFillColor(sf::Color(mappedValue, 255 - mappedValue2, mappedValue3));

        // rdr2.setPosition(0, 0);
        // window.draw(rdr2);

        ball.draw(window);
        for (Brique* brique : briques)
        {
            if (brique->enVie())
            {
                brique->draw(window);
            }
        }
        player.draw(window);
        window.display();
    }
    return 0;
}
