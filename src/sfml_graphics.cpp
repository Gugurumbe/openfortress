#include "sfml_graphics.h"
#include "build.h"

SfmlGraphics::SfmlGraphics(): 
  Graphics(), m_thread(&SfmlGraphics::loop, this), m_quit(false),
  m_window(0), m_opt()
{
  m_thread.launch();
}
SfmlGraphics::SfmlGraphics(const BaseMap * map):
  Graphics(map), m_thread(&SfmlGraphics::loop, this), m_quit(false),
  m_window(0), m_opt()
{
  m_thread.launch();
}
void SfmlGraphics::open_window()
{
  m_threadmutex.lock();
  if(m_window) delete m_window;
  m_window = new sf::RenderWindow(sf::VideoMode
				  (m_opt.res_w(), m_opt.res_h()),
				  std::string
				  ("Openfortress version ") + VERSION);
  m_threadmutex.unlock();
}
SfmlGraphics::~SfmlGraphics()
{
  m_threadmutex.lock();
  m_quit = true;
  m_threadmutex.unlock();
  m_thread.wait();
  if(m_window) delete m_window;
}
void SfmlGraphics::loop()
{
  bool done = false;
  sf::Event e;
  sf::Clock chrono;
  sf::Time delay = sf::milliseconds(30);
  sf::Time last_update = -delay;
  chrono.restart();
  do
    {
      m_threadmutex.lock();
      done = m_quit;
      while(m_window && m_window->pollEvent(e))
	{
	  switch(e.type)
	    {
	    case sf::Event::Closed:
	      on_quit();
	      break;
	    default:
	      break;
	    }
	}
      m_threadmutex.unlock();
      sf::sleep(delay - (chrono.getElapsedTime() - last_update));
      last_update += delay;
      m_threadmutex.lock();
      if(m_window) draw(*m_window);
      m_threadmutex.unlock();
    }while(!done);
}
void SfmlGraphics::draw(sf::RenderWindow & window)
{
  window.display();
}
void SfmlGraphics::close()
{
  if(m_window) m_window->close();
}
