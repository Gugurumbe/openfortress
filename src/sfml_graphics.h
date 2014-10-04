#ifndef SFML_GRAPHICS_H_INCLUDED
#define SFML_GRAPHICS_H_INCLUDED

#include "graphics.h"
#include "sfml_options.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class SfmlGraphics : public Graphics
{
 public:
  SfmlGraphics();
  SfmlGraphics(const BaseMap * map);
  virtual ~SfmlGraphics();
  virtual void open_window();
 protected:
  virtual void draw(sf::RenderWindow & win);
  void close();
  void lock();
  void unlock(); // When using the RenderWindow outside draw()
 private:
  void loop();
  bool m_quit;
  sf::Mutex m_threadmutex;
  sf::Thread m_thread;
  sf::RenderWindow * m_window;
  SfmlOptions m_opt;
};

#endif
