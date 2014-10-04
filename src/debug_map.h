#ifndef DEBUG_MAP_INCLUDED
#define DEBUG_MAP_INCLUDED

#include "base_map.h"

#include <iostream>

class DebugMap : public BaseMap
{
 public:
  DebugMap();
  DebugMap(unsigned int w, unsigned int h);
  void w(unsigned int w);
  void h(unsigned int h);
  int w() const;
  int h() const;
  // Set the size of the next generated map
  virtual void generate();
 private:
  void add_walkable_layer(int n);
  unsigned int w_command;
  unsigned int h_command;
  unsigned int max_height_generated;
};

std::ostream & operator<<(std::ostream & str, DebugMap const & m);

#endif
