#include "object.h"


Object::Object()
{
	radius = 20;
	sections = 30;
	color = sf::Color::Green;
	position = { 300, 300 };
	velocity = { 1, 1 };
}

void Object::update() {
	position += velocity;
}

int Object::get_radius() {
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