// application.cpp

#include "application.hpp"

namespace runner
{
    void Application::run()
    {
        std::string title;
        if (!font.loadFromFile("assets/Arialn.ttf")) {
            return;
        }

        if (config.load("./assets/config.txt")) {
            std::string title;
            if (config.contains("window_title")) config.as_string("window_title", title);
            else {
                text.setString("Failed to open file");
            }
            text.setString(title);

            if (config.contains("window_width")) config.as_int("window_width", screen_size.x);
            if (config.contains("window_height")) config.as_int("window_height", screen_size.y);

            text.setFont(font);
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Green);
            text.setStyle(sf::Text::Bold);
            text.setPosition(400, 50);


            const sf::VideoMode mode{ (unsigned)screen_size.x, (unsigned)screen_size.y };
            const sf::Uint32 flags = sf::Style::Titlebar | sf::Style::Close;
            m_window.create(mode, text.getString(), flags);
            if (!m_window.isOpen() || !enter()) {
                return;
            }

            m_window.setKeyRepeatEnabled(false);
            while (m_window.isOpen()) {
                sf::Event event;
                while (m_window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
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


   void Application::on_key_pressed(const sf::Keyboard::Key key)
   {
      if (key == sf::Keyboard::Key::Escape) {
         m_running = false;
      }
   }

} // !runner
