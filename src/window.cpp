#include "window.h"

#include <iostream>
#include <cstdlib>

Window::Window(): SfmlGraphics(), m_dead(false)
{
}
Window::Window(const BaseMap * m):
  SfmlGraphics(m), m_dead(false)
{
}
bool Window::dead() const
{
  return m_dead;
}
void Window::on_quit()
{
  m_dead = true;
  close();
}
 void Window::draw(sf::RenderWindow & w)
{
  w.clear(sf::Color(rand()%256, rand()%256, rand()%256));
  w.display();
}
