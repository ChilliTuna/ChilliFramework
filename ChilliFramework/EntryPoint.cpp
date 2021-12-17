#include "Application.h"

int main()
{
	Application application;

	if (!application.Initialise())
	{
		return -1;
	}

	application.Run();
		
	application.Shutdown();

	return 0;
}