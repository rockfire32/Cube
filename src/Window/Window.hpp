#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

constexpr int WIDTH = 360;
constexpr int HEIGHT = 240;

class Window
{
public:
	Window();
	~Window();

	bool GetStatus();
	void Run();

protected:
	bool Status = true;

	SDL_Event event;

	SDL_GLContext context;
	SDL_Window *window = nullptr;

	void Events();
	void DrawCube();

    void Keyboard();
private:
    double x = 0.0,
           y = 0.0, 
           z = 0.0;
};

#endif
