#include "build.h"

std::string user_config_dir()
{
  std::string home = getenv("HOME");
  if(home!="") return home + "/.openfortress/";
  home = getenv("USERPROFILE");
  if(home!="") return home + "/.openfortress/";
  return "";
}

std::string user_config()
{
  return user_config_dir() + "graphics.conf";
}
