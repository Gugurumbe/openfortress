#include "sfml_options.h"

#include <fstream>
#include <iostream>
#include <sstream>

SfmlOptions::SfmlOptions():
  m_fullscreen(false),
  m_w(640),
  m_h(480)
{
  //Attempt to find a configuration file ...
  std::string conf = user_config();
  if(conf != "")
    {
      std::ifstream str(conf.c_str(), std::ifstream::in);
      if(str)
	{
	  //Reading :
	  //1. true or false (anything) if fullscreen is to be set
	  //2. resolution width
	  //3. resolution height
	  std::string fs, w, h;
	  str>>fs>>w>>h;
	  if(fs == "true") m_fullscreen = true;
	  std::stringstream str_w(w);
	  str_w>>m_w;
	  std::stringstream str_h(h);
	  str_h>>m_h;
	}
    }
  else
    {
      std::cerr<<"Unable to find where you store your own graphical config."
	       <<"\nUntil you set HOME or USERPROFILE, your settings will "
	       <<"be forgotten each time you close this program.\n";
    }
}
SfmlOptions::~SfmlOptions()
{
  std::string conf = user_config();
  std::string conf_dir = user_config_dir();
  if(conf != "")
    {
      MKDIR(conf_dir);
      std::ofstream str(conf.c_str(), 
			std::ifstream::out | std::ifstream::trunc);
      if(str)
	{
	  str<<(m_fullscreen?"true ":"false ")<<m_w<<" "<<m_h<<std::endl;
	  str<<"Order for these : fullscreen (true or anything but blank)"
	     <<", width, height, then your own comments.";
	}
    }
}
bool SfmlOptions::fullscreen() const
{
  return m_fullscreen;
}
void SfmlOptions::fullscreen(bool f)
{
  m_fullscreen=f;
}
int SfmlOptions::res_w() const
{
  return m_w;
}
int SfmlOptions::res_h() const
{
  return m_h;
}
void SfmlOptions::res_w(int w)
{
  m_w=w;
}
void SfmlOptions::res_h(int h)
{
  m_h=h;
}
