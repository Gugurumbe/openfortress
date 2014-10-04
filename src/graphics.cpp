#include "graphics.h"

Graphics::Graphics(): m_map(0)
{
}
Graphics::Graphics(const BaseMap * map): m_map(map)
{
}
const BaseMap * Graphics::map() const
{
  return m_map;
}
void Graphics::map(const BaseMap * m)
{
  m_map = m;
}
void Graphics::on_quit()
{
}
