#ifndef BASE_MAP_H_INCLUDED
#define BASE_MAP_H_INCLUDED

#include "terrain.h"
#include "position.h"

#include <vector>
#include <exception>

class BaseMap
{
 public:
  BaseMap();
  BaseMap(const BaseMap &);
  virtual void generate() = 0;
  Terrain const & at(Position const & p) const;
  //may raise OOR
  std::vector<std::vector<bool> > neighbours(Position const & p) const;
  //Retourne un carré 3x3 de booléens pour savoir si on peut faire un pas
  //dans la direction donnée ou pas. Si hors zone, vaut false.
  std::vector<std::vector<int> > stairs(Position const & p) const;
  //Retourne les différences d'altitudes avec les voisins. Si hors zone,
  //vaut 0
  int w() const;
  int h() const;

 protected:
  void realloc(int w, int h);
  void set(Position const & p, Terrain const & t);

 private:
  std::vector<std::vector<Terrain> > m_map;
};

class OOR : public std::exception
{
 public:
  OOR(Position const & pos, unsigned int n, unsigned int p) throw();
  virtual const char* what() const throw();
 private:
  Position m_pos;
  unsigned int m_n, m_p;
};

#endif
