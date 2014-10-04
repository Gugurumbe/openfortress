#ifndef SFML_OPTIONS_INCLUDED
#define SFML_OPTIONS_INCLUDED

#include "build.h"

class SfmlOptions
{
 public:
  SfmlOptions();
  virtual ~SfmlOptions();
  bool fullscreen() const;
  void fullscreen(bool enabled);
  int res_w() const;
  int res_h() const;
  void res_w(int w);
  void res_h(int h);
 private:
  bool m_fullscreen;
  int m_w;
  int m_h;
};

#endif
