#include "base_map.h"
#include <sstream>

#define max(a,b) (a<b?b:a)
#define min(a,b) (a>b?b:a)

#define IN_RECT(x,y,w,h,pt_x,pt_y)		\
  (pt_x>=x					\
    && pt_y>=y					\
    && pt_x<x+w					\
   &&pt_y<y+h)

OOR::OOR(Position const & pos, unsigned int n, unsigned int p) throw():
  std::exception(),
  m_pos(pos), m_n(n), m_p(p)
{
}

const char* OOR::what() const throw()
{
  std::stringstream s;
  s<<"Cell "<<m_pos<<" is out of bounds "<<m_p<<"x"<<m_n<<".";
  return s.str().c_str();
}

BaseMap::BaseMap()
{
}

BaseMap::BaseMap(const BaseMap & m): m_map(m.m_map)
{
}

Terrain const & BaseMap::at(Position const & pos) const
{
  if(pos.in_rect(Position(0, 0), Position(w(), h())))
    return m_map[pos.y()][pos.x()];
  else throw OOR(pos, h(), w());
}

std::vector<std::vector<bool> > 
BaseMap::neighbours(Position const & p) const
{
  std::vector<std::vector<bool> > lignes(3);
  for(int i = 0 ; i < 3 ; i++)
    {
      lignes[i].resize(3);
      for(int j = 0 ; j < 3 ; j ++)
	{
	  lignes[i][j] = false;
	}
    }
  for(int i = max(0, p.y()-1) ; i < min(m_map.size(), p.y()+2) ; i++)
    {
      for(int j = max(0, p.x()-1) ; j < min(m_map[i].size(), p.x()+2) ; j++)
	{
	  lignes[i - p.y() + 1][j - p.x() + 1] = m_map[i][j].walkable();
	}
    }
  return lignes;
}

std::vector<std::vector<int> > BaseMap::stairs(Position const & p) const
{
  std::vector<std::vector<int> > lignes(3);
  int h = 0;
  try
    {
      h = at(p).height();
    }
  catch(...){}
  for(int i = 0 ; i < 3 ; i++)
    {
      lignes[i].resize(3);
      for(int j = 0 ; j < 3 ; j ++)
	{
	  lignes[i][j] = 0;
	}
    }
  for(int i = max(0, p.y()-1) ; i < min(m_map.size(), p.y()+2) ; i++)
    {
      for(int j = max(0, p.x()-1) ; j < min(m_map[i].size(), p.x()+2) ; j++)
	{
	  lignes[i - p.y() + 1][j - p.x() + 1] = m_map[i][j].height() - h;
	}
    }
  return lignes;
}

int BaseMap::w() const
{
  if(m_map.size() == 0) return 0;
  return m_map[0].size();
}

int BaseMap::h() const
{
  return m_map.size();
}

void BaseMap::realloc(int w, int h)
{
  m_map.resize(h);
  for(int i = 0 ; i < m_map.size() ; i++)
    {
      m_map[i].resize(w);
    }
}

void BaseMap::set(Position const & p, Terrain const & t)
{
  if(p.in_rect(Position(0, 0), Position(w(), h())))
    m_map[p.y()][p.x()]=t;
  else throw OOR(p, h(), w());
}
