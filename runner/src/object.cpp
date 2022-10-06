#include "object.h"


Object::Object()
{
	radius = 20;
	sections = 30;
	color = sf::Color::Green;
	position = { 300, 300 };
	velocity = { 1, 0.5f };
}

void Object::update(sf::Vector2i screen_size) {
	this->position += this->velocity;

	if (this->position.x > (float)screen_size.x) {
		this->velocity.x = -this->velocity.x;
	}
	if (this->position.y > (float)screen_size.y) {
		this->velocity.y = -this->velocity.y;
	}
	if (this->position.x < 0) {
		this->velocity.x = -this->velocity.x;
	}
	if (this->position.y < 0) {
		this->velocity.y = -this->velocity.y;
	}
}

float Object::get_radius() {
	return this->radius;
}

sf::Color Object::get_color() {
	return this->color;
}

int Object::get_sections() {
	return this->sections;
}
sf::Vector2f Object::get_position() {
	return this->position;
}