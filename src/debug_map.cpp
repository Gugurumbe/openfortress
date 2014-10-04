#include "debug_map.h"

#include <queue>
#include <cstdlib>

#include <iomanip>

DebugMap::DebugMap() : BaseMap(), w_command(0), h_command(0),
		       max_height_generated(0)
{
}

DebugMap::DebugMap(unsigned int w, unsigned int h) : 
  BaseMap(), w_command(w), h_command(h)
{
}						     

void DebugMap::w(unsigned int w)
{
  w_command = w;
}

void DebugMap::h(unsigned int h)
{
  h_command = h;
}

int DebugMap::w() const 
{
  return BaseMap::w();
}

int DebugMap::h() const 
{
  return BaseMap::h();
}

void DebugMap::generate()
{
  realloc(0, 0);
  realloc(w_command, h_command);
  max_height_generated = 0;
  Terrain t(0, true);
  Position coin(0, 0);
  Position coincoin(BaseMap::w(), BaseMap::h());
  Position y(0, 1);
  for(int x=0; x < BaseMap::w(); x++)
    {
      for(Position p(x, 0); p.in_rect(coin, coincoin); p += y)
	{
	  set(p, t);
	}
    }
  const float ratio = 0.05;
  int n = ratio * BaseMap::w() * BaseMap::h();
  while(max_height_generated<10)
    {
      add_walkable_layer(n);
    }
}

void DebugMap::add_walkable_layer(int n)
{ 
  Position neutre(0, 0);
  Position x(1,0);
  Position y(0,1);
  Position taille(BaseMap::w(), BaseMap::h());     
  if(n < BaseMap::w() * BaseMap::h())
    {
      Position racine
	(std::rand() % BaseMap::w(), std::rand() % BaseMap::h());
      Position p;
      std::queue<Position> primaire, secondaire;
      Terrain tampon;
      primaire.push(racine);
      for(int i = 0 ; i < n ; i++)
	{
	  if(primaire.empty()) 
	    {
	      p = secondaire.front();
	      secondaire.pop();
	    }
	  else 
	    {
	      p = primaire.front();
	      primaire.pop();
	    }
	  tampon = at(p);
	  if(tampon.height() >= max_height_generated) 
	    {
	      max_height_generated = tampon.height() + 1;
	    }
	  tampon.height(tampon.height() + 1);
	  set(p, tampon);
	  if(std::rand()%2) primaire.push(p + x);
	  else secondaire.push(p + x);
	  if(std::rand()%2) primaire.push(p - x);
	  else secondaire.push(p - x);
	  if(std::rand()%2) primaire.push(p + y);
	  else secondaire.push(p + y);
	  if(std::rand()%2) primaire.push(p - y);
	  else secondaire.push(p - y);
	}
    }
  else
    {
      Terrain tampon;
      for(int x_ = 0 ; x_ < BaseMap::w() ; x_++)
	for(Position p(x_, 0) ; p.in_rect(neutre, taille) ; p += y)
	  {
	    tampon=at(p);
	    tampon.height(tampon.height() + 1);
	    set(p, tampon);
	  }
      max_height_generated++;
    }
}

std::ostream & operator<<(std::ostream & str, DebugMap const & m)
{
  str<<"Map "<<std::setw(3)<<m.w()<<"x"<<m.h()<<" : \n";
  Position coin(0, 0);
  Position coincoin(m.w(), m.h());
  Position y(0, 1);
  for(int x = 0 ; x < m.w() ; x++)
    for(Position p(x, 0) ; p.in_rect(coin, coincoin) ; p += y)
      {
	str<<std::setw(14)<<p<<" : "<<m.at(p)<<std::endl;
      }
  return str;
}
