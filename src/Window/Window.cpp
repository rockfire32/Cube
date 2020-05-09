#include "Window.hpp"

Window::Window()
{
	if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		Status = false;
	}
	else
	{
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	
		window = SDL_CreateWindow("Cube", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

		context = SDL_GL_CreateContext(window);
		if ( context == nullptr )
		{
			Status = false;
		}

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClearDepth(1.0);
		glDepthFunc(GL_LESS);
		glEnable(GL_DEPTH_TEST);
		glShadeModel(GL_SMOOTH);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (float) WIDTH / (float) HEIGHT, 0.1f, 100.0f);
		glMatrixMode(GL_MODELVIEW);
	}
}

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Window::GetStatus()
{
    return Status;
}

void Window::Run()
{
    static int currTicks = 0,
               lastTicks = 0;

    currTicks = SDL_GetTicks();

    if ( currTicks > lastTicks + 30 )
    {
        Events();
        DrawCube();

        lastTicks = currTicks;
    }

    glFlush();
	SDL_GL_SwapWindow(window);
}

void Window::Events()
{
    while ( SDL_PollEvent(&event) )
	{
		switch ( event.type )
		{
			case SDL_QUIT:
			{
				Status = false;
				break;
			}
            case SDL_KEYDOWN:
            {
                Keyboard();
                break;
            }
            default:
            {
                break;
            }
        }
	}
}

void Window::DrawCube()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -7.0f);

    glRotatef(x, 1.0f, 0.0f, 0.0f);
    glRotatef(y, 0.0f, 1.0f, 0.0f);
    glRotatef(z, 0.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glEnd();
}

void Window::Keyboard()
{
    switch ( event.key.keysym.sym )
    {
        case SDLK_q:
        {
            Status = false;
            break;
        }
        case SDLK_w:
        {
            x = x - 0.5;
            break;
        }
        case SDLK_s:
        {
            x = x + 0.5;
            break;
        }
        case SDLK_a:
        {
            y = y - 0.5;
            break;
        }
        case SDLK_d:
        {
            y = y + 0.5;
            break;
        }
    }
}
