#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include "sfml_graphics.h"

class Window : public SfmlGraphics
{
 public:
  Window();
  Window(const BaseMap * map);
  bool dead() const;
 protected:
  virtual void on_quit();
  virtual void draw(sf::RenderWindow & window);
 private:
  bool m_dead;
};

#endif
