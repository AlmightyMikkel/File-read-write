#include <SFML/Graphics.hpp>

class Object
{
private:
	int radius;
	sf::Vector2f position;
	sf::Color color;
	sf::Vector2f velocity;
	int sections;
public:
	Object();
	void update();
	int get_radius();
	sf::Color get_color();
	int get_sections();
	sf::Vector2f get_position();
};

