#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

#include <iostream>

class Position
{
public:
  Position();
  Position(const Position &);
  Position(int x, int y);
  void x(int x);
  void y(int y);
  int x() const;
  int y() const;
  bool in_rect
  (Position const & topleft, Position const & bottomright) const;
  void write_text(std::ostream & str) const;
  void read_text(std::istream & str);
  Position & operator=(const Position &);
  Position & operator+=(const Position &);
  Position & operator-=(const Position &);
  Position & operator*=(int k);
private:
  int m_x;
  int m_y;
};

Position operator+(const Position & p1, const Position & p2);
Position operator-(const Position & p1, const Position & p2);
Position operator*(int k, const Position & p);
std::ostream & operator<<(std::ostream & str, const Position & p);
std::istream & operator>>(std::istream & str, Position & p);

#endif
