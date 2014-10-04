#ifndef SFML_WINDOW_H_INCLUDED
#define SFML_WINDOW_H_INCLUDED

#include "sfml_graphics.h"

class SfmlWindow: public SfmlGraphics
{
 public:
  SfmlWindow();
  SfmlWindow(const Basemap * map);
};

#endif
