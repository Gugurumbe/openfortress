#include "build.h"

std::string user_config_dir()
{
  char * home = getenv("HOME");
  if(home) return std::string(home) + "/.openfortress/";
  home = getenv("USERPROFILE");
  if(home) return std::string(home) + "/.openfortress/";
  return "";
}

std::string user_config()
{
  return user_config_dir() + "graphics.conf";
}
