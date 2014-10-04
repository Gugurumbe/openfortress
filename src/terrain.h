#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <string>
#include <iostream>

//La classe Terrain définit une case. Plus exactement, une base pour une 
//classe.

class Terrain
{
 public:
  Terrain();
  Terrain(int height, bool walkable);
  Terrain(const Terrain &);
  void walkable(bool w);
  bool walkable() const;
  void height(int h);
  int height() const;
  virtual std::string description() const;
  //The description is created for each call
 private:
  bool m_walkable;
  int m_height;
};

std::ostream & operator<<(std::ostream & str, Terrain const & t);

#endif
