#include "Application.h"

int main()
{
	Application application;

	if (application.Initialise())
	{
		application.Run();
	}
	application.Shutdown();
}