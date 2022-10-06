// application.cpp

#include "application.hpp"


//How do I send the window size to the object so that I can either warp or contain the ball?
//Do I need some backup things for the .contains and .as_"    " in case the bool is false?
<<<<<<< HEAD
//Does .as_string turn back "" or did I fuck up?
=======
>>>>>>> c3179183b00178e17d69d8b5315913ff8c31b5af



namespace runner
{
   void Application::run()
   {
       std::string title;
       if (!font.loadFromFile("assets/Arialn.ttf")) {
           return;
       }

<<<<<<< HEAD
       if (!font.loadFromFile("assets/Arialn.ttf")) {
           return;
       }

       if (config.load("./assets/config.txt")) {
           std::string title;
           if (config.contains("window_title")) config.as_string("window_title", title);
=======
       if (config.load("./assets/config.txt")) {

           if (config.contains("window_title")) config.as_string("windows_title", title);
>>>>>>> c3179183b00178e17d69d8b5315913ff8c31b5af
           //Add something IF container doesnt have window_title
           text.setString(title);
       }
       else {
           text.setString("Failed to open file");
       }

<<<<<<< HEAD
       //Have an else if config doenst contain!
       if (config.contains("window_width")) config.as_int("window_width", screen_size.x);
       if (config.contains("window_height")) config.as_int("window_height", screen_size.y);


=======

       int window_width{}, window_height{};
       //Have an else if config doenst contain!
       if (config.contains("window_width")) config.as_int("window_width", window_width);
       if (config.contains("window_height")) config.as_int("window_height", window_height);


>>>>>>> c3179183b00178e17d69d8b5315913ff8c31b5af
       text.setFont(font);
       text.setCharacterSize(24);
       text.setFillColor(sf::Color::Green);
       text.setStyle(sf::Text::Bold);
       text.setPosition(400, 50);


<<<<<<< HEAD
       const sf::VideoMode mode{(unsigned)screen_size.x, (unsigned)screen_size.y};
=======
       const sf::VideoMode mode{ (unsigned)window_width, (unsigned)window_height };
>>>>>>> c3179183b00178e17d69d8b5315913ff8c31b5af
       const sf::Uint32 flags = sf::Style::Titlebar | sf::Style::Close;
       m_window.create(mode, text.getString(), flags);
       if (!m_window.isOpen() || !enter()) {
           return;
       }

      m_window.setKeyRepeatEnabled(false);
      while (m_window.isOpen()) {
         sf::Event event;
         while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::MouseMoved) {
               on_mouse_move({ float(event.mouseMove.x), float(event.mouseMove.y) });
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
               on_button_pressed(event.mouseButton.button);
            }
            else if (event.type == sf::Event::MouseButtonReleased) {
               on_button_released(event.mouseButton.button);
            }
            else if (event.type == sf::Event::KeyPressed) {
               on_key_pressed(event.key.code);
            }
            else if (event.type == sf::Event::Closed) {
               m_window.close();
            }
         }

         if (!update()) {
            m_window.close();
         }

         render();
      }

      exit();
   }

   bool Application::enter()
   {
      return true;
   }

   void Application::exit()
   {
   }

   bool Application::update()
   {
      m_deltatime = m_clock.restart();
      ball.update({screen_size});

      return m_running;
   }

   void Application::render()
   {
      m_batch.clear();
      { 
          m_batch.draw_circle(ball.get_position(), 
                              ball.get_radius(), 
                              ball.get_sections(), 
                              ball.get_color());
      }
      
      m_window.clear(sf::Color{ 0x44, 0x55, 0x66, 0xff });
      m_window.draw(text);
      m_batch.present(m_window);
      m_window.display();
   }

   void Application::on_mouse_move(const sf::Vector2f &position) 
   {
      m_mouse_position = position;
   }

   void Application::on_key_pressed(const sf::Keyboard::Key key)
   {
      if (key == sf::Keyboard::Key::Escape) {
         m_running = false;
      }
   }

   void Application::on_key_released(const sf::Keyboard::Key key)
   {
   }

   void Application::on_button_pressed(const  sf::Mouse::Button button)
   {
   }

   void Application::on_button_released(const sf::Mouse::Button button)
   {
   }
} // !runner
