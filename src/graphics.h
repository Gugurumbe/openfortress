#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <string>

#include "base_map.h"

class Graphics
{
 public:
  Graphics();
  Graphics(const BaseMap * map);
  virtual void open_window() = 0;
  const BaseMap * map() const;
  void map(const BaseMap * m);
 protected:
  virtual void on_quit();
 private:
  const BaseMap * m_map;
};

#endif
