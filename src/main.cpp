#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "build.h"

#include "terrain.h"
#include "base_map.h"
#include "debug_map.h"
#include "window.h"

int main(int argc, char * argv[])
{
  std::srand(std::time(0));
  std::vector<std::string> args(argc);
  std::string version = VERSION;
  for(int i=0; i<argc; i++)
    {
      args[i]=argv[i];
    }
  std::string executable = args[0];
  std::cout<<executable<<" ("<<version<<")"<<std::endl;
  for(unsigned int i=1; i < args.size(); i++)
    {
      std::cout<<"Warning : Unused argument '"<<args[i]<<"'.\n";
    }
  Terrain t1(true, 5);
  std::cout<<t1.description()<<std::endl;
  DebugMap m(6, 4);
  m.generate();
  std::cout<<m<<std::endl;
  Window w(&m);
  w.open_window();
  /*
  std::cout<<"Say something when you're done : ";
  std::string foo;
  std::cin>>foo;
  std::cout<<"Ok. Thanks.\n";
  */
  sf::sleep(sf::seconds(10));
  return 0;
}
