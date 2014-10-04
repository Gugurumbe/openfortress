#include "terrain.h"
#include <sstream>

Terrain::Terrain() : m_walkable(false), m_height(0)
{
}

Terrain::Terrain(int height, bool walkable) : 
  m_walkable(walkable), m_height(height)
{
}

Terrain::Terrain(const Terrain & t) :
  m_walkable(t.m_walkable), m_height(t.m_height)
{
}

void Terrain::walkable(bool b)
{
  m_walkable=b;
}

bool Terrain::walkable() const
{
  return m_walkable;
}

void Terrain::height(int h)
{
  m_height=h;
}

int Terrain::height() const
{
  return m_height;
}

std::string Terrain::description() const
{
  std::stringstream s;
  if(m_walkable) s << "Walkable cell, height ";
  else s << "Forbidden cell, height";
  s << m_height;
  return s.str();
}
std::ostream & operator<<(std::ostream & str, Terrain const & t)
{
  str<<t.description();
  return str;
}
