# Version minimale de CMake :
cmake_minimum_required(VERSION 2.6)

#Définition du projet
project(Openfortress)
set(Openfortress_VERSION_MAJOR 1)
set(Openfortress_VERSION_MINOR 0)

set(sources 
  "src/main.cpp"
  "src/terrain.cpp"
  "src/base_map.cpp"
  "src/debug_map.cpp"
  "src/position.cpp"
  "src/graphics.cpp" 
  "src/sfml_options.cpp"
  "src/build.cpp"
)
set(PROJECT_SOURCE_DIR src)
set(PROJECT_BINARY_DIR bin)

# Pour l'instant, l'utilisateur DOIT choisir le moteur de rendu SFML.
option(USE_SFML "Use SFML Version 2.1" ON)
include(FindPkgConfig)
pkg_check_modules(GRAPHICS_LIB REQUIRED sfml-system>=2.1 sfml-window>=2.1 sfml-graphics>=2.1)


set(sources ${sources} "src/sfml_graphics.cpp" "src/window.cpp")

#Fichier de configuration
set(user_home "${HOME}")
if(NOT ${user_home})
  set(user_home "${USERPROFILE}")
endif(NOT ${user_home})
if(NOT ${user_home})
  echo("WARNING : Cannot find a place to store your data.\n")
  echo("Please export the correct place to HOME or USERPROFILE.")
else(NOT ${user_home})
endif(NOT ${user_home})
configure_file("${PROJECT_SOURCE_DIR}/build.h.in"
	"${PROJECT_BINARY_DIR}/build.h")
include_directories("${PROJECT_BINARY_DIR}")
include_directories(GRAPHICS_LIB_INCLUDE_DIR)
add_executable(openfortress ${sources})
link_directories(${GRAPHICS_LIB_LIBRARY_DIRS})
target_link_libraries(openfortress ${GRAPHICS_LIB_LIBRARIES})
install(TARGETS openfortress DESTINATION bin)
install(FILES "{PROJECT_BINARY_DIR}/build.h" DESTINATION include)