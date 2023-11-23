#include "Ball.h"

bool Ball::isRandInitialized = false;

Ball::Ball(int x, int y, int radius, float speed) :
	position(x, y),
	oldPosition(position),
	direction(1.f, 1.f),
	radius(radius),
	speed(speed) 
	{
	shape.setFillColor(sf::Color::White);
	shape.setRadius(radius);
	setAngle(randomizeAngle());
}

Ball::~Ball() {
}

double Ball::randomizeAngle() {
	if (!isRandInitialized) {
		srand(time(NULL));
		isRandInitialized = true;
	}
	return (((double)rand() / (double)RAND_MAX) * 60.0) - 30.0;
}

void Ball::setAngle(double angle) {
	direction.x = sin(angle);
	direction.y = -cos(angle);
}

void Ball::move(float elapsedTime) {
	oldPosition = position;
	position += elapsedTime * speed * direction;
	shape.setPosition(position);
}

void Ball::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

float Ball::getSpeed() const {
	return speed;
}

void Ball::setPosition(sf::Vector2f newPosition) {
	position = newPosition;
	oldPosition = position;
	shape.setPosition(position);
}

sf::Vector2f Ball::getPosition() const {
	return position;
}

void Ball::setDirection(sf::Vector2f newDirection) {
	direction = newDirection;
}

sf::CircleShape& Ball::getShape() {
	return shape;
}

bool Ball::checkCollisionWith(Player& player) {
	return shape.getGlobalBounds().intersects(player.getShape().getGlobalBounds());
}


void Ball::manageCollisionWith(Player& player, sf::RenderWindow& window)
{
	if (position.y <= 0) {
		direction.y *= -1;
		position.y = 0;
	}
	else if (position.y + 2 * radius >= window.getSize().y) {
		direction.y *= -1;
		position.y = window.getSize().y - 2 * radius;
	}
	if (position.x <= 0) {
		direction.x *= -1;
		position.x = 0;
	}
	else if (position.x + 2 * radius >= window.getSize().x) {
		direction.x *= -1;
		position.x = window.getSize().x - 2 * radius;
	}

	if (shape.getGlobalBounds().intersects(player.getShape().getGlobalBounds())) {
		float relativePosition = (position.x + radius) - (player.getPosition().x + player.getSize().x / 2);
		direction.x = relativePosition / (player.getSize().x / 2);
		direction.y *= -1;
		position.y = player.getPosition().y - radius * 2;
	}
}

void Ball::manageCollisionWithBrique(Brique& brique) {
	sf::FloatRect ballRect(position.x, position.y, 2 * radius, 2 * radius);
	sf::FloatRect briqueRect(brique.getPosition().x, brique.getPosition().y, brique.getSize().x, brique.getSize().y);

	if (ballRect.intersects(briqueRect)) {

		double relativeIntersectX = position.x + radius - brique.getPosition().x - brique.getSize().x / 2.0;
		double relativeIntersectY = position.y + radius - brique.getPosition().y - brique.getSize().y / 2.0;

		double normalizedRelativeIntersectionX = relativeIntersectX / (brique.getSize().x / 2.0);
		double normalizedRelativeIntersectionY = relativeIntersectY / (brique.getSize().y / 2.0);

		if (std::abs(normalizedRelativeIntersectionX) > std::abs(normalizedRelativeIntersectionY)) {
			if (normalizedRelativeIntersectionX > 0) {
				position.x = brique.getPosition().x + brique.getSize().x + radius;
				brique.hit();
			}
			else {
				position.x = brique.getPosition().x - 2 * radius;
				brique.hit();
			}
			direction.x = -direction.x;
		}

		else {
			if (normalizedRelativeIntersectionY > 0) {
				position.y = brique.getPosition().y + brique.getSize().y + radius;
				brique.hit();
			}
			else {
				position.y = brique.getPosition().y - 2 * radius;
				brique.hit();
			}
			direction.y = -direction.y;
		}
	}
}


