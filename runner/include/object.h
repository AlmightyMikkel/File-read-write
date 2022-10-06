<<<<<<< HEAD
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

=======
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

>>>>>>> c3179183b00178e17d69d8b5315913ff8c31b5af
