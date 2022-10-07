// application.hpp

#pragma once

#include "batch.hpp"
#include "config.h"
#include "object.h"

namespace runner
{
   class Application final
   {
   public:
      Application() = default;

      void run();

   private:
      bool enter();
      void exit();
      bool update();
      void render();

   private:
      void on_key_pressed(const sf::Keyboard::Key key);

   private:
      sf::RenderWindow m_window;
      runner::PrimitiveBatch   m_batch;
      bool             m_running = true;
      sf::Clock        m_clock;
      sf::Time         m_deltatime;
      sf::Vector2i     screen_size;
      sf::Text         text;
      sf::Font         font;
      Object           ball;
      Config           config;
   };
} // !runner
