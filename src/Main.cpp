#include "Window/Window.hpp"

int main()
{
	Window win;

	while ( win.GetStatus() )
	{
		win.Run();
	}

	return 0;
}
