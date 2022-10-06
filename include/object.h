#include <SFML/Graphics.hpp>

class Object
{
private:
	float radius;
	sf::Vector2f position;
	sf::Color color;
	sf::Vector2f velocity;
	int sections;
	float speed;
public:
	Object();
	void update(sf::Vector2i screen_size);
	float get_radius();
	sf::Color get_color();
	int get_sections();
	sf::Vector2f get_position();
};
