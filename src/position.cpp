#include "position.h"

Position::Position() : m_x(0), m_y(0) 
{
}
Position::Position(const Position & p) : m_x(p.m_x), m_y(p.m_y) 
{
}
Position::Position(int x_, int y_) : m_x(x_), m_y(y_) 
{
}
void Position::x(int x_) 
{
  m_x = x_;
}
void Position::y(int y_) 
{
  m_y = y_;
}
int  Position::x() const 
{
  return m_x;
}
int  Position::y() const 
{
  return m_y;
}
bool Position::in_rect(Position const & tl, Position const & br) const
{
  return m_x>=tl.m_x && m_y >= tl.m_y && m_x < br.m_x && m_y < br.m_y;
}
void Position::write_text(std::ostream & str) const
{
  str<<"(x="<<m_x<<", y="<<m_y<<")";
}
void Position::read_text(std::istream & str) 
{
  str>>m_x;
  str>>m_y;
}
Position & Position::operator=(const Position & p) 
{
  m_x = p.m_x;
  m_y = p.m_y;
  return *this;
}
Position & Position::operator+=(const Position & p) 
{
  m_x+=p.m_x;
  m_y+=p.m_y;
  return *this;
}
Position & Position::operator-=(const Position & p) 
{
  m_x-=p.m_x;
  m_y-=p.m_y;
  return *this;
}
Position & Position::operator*=(int k)
{
  m_x *= k ;
  m_y *= k ;
}
Position operator+(const Position & p1, const Position & p2)
{
  Position p(p1);
  p += p2;
  return p;
}
Position operator-(const Position & p1, const Position & p2)
{
  Position p(p1);
  p -= p2;
  return p;
}
Position operator*(int k, const Position & p)
{
  Position pos(p);
  pos *= k;
  return pos;
}
std::ostream & operator<<(std::ostream & str, const Position & p)
{
  p.write_text(str);
  return str;
}
std::istream & operator>>(std::istream & str, Position & p)
{
  p.read_text(str);
  return str;
}
