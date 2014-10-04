#include "window.h"

#include <iostream>

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
  w.clear();
  w.display();
}
