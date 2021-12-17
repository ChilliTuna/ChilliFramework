#include "Application.h"
#include <iostream>

#ifndef WINDOW_WIDTH
#define WINDOW_WIDTH 1280
#endif
#ifndef WINDOW_HEIGHT
#define WINDOW_HEIGHT 720
#endif

bool Application::Initialise()
{
	// Step 1: Initialise GLFW
	if (!glfwInit())
	{
		return false;
	}

	// Step 2: Create window
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "ChilliFramework", nullptr, nullptr);
	if (!window)
	{
		glfwTerminate();
		return false;
	}

	// Step 3: Define which window should be rendered to
	glfwMakeContextCurrent(window);

	// Step 4: Load GLAD's GL functions
	if (!gladLoadGL())
	{
		return false;
	}
	return true;
}

void Application::Run()
{
	int updateIterator = 0;
	// Step 5: Run the "game" loop
	while (!glfwWindowShouldClose(window))
	{
		// Step 5.1: Clear screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Step 5.2: Render stuff here
		#pragma region RenderRegion



		#pragma endregion

		// Step 5.3: Perform update functions
		#pragma region UpdateRegion

		//Iterate through all update functions and run them
		for (updateIterator = 0; updateIterator < updateFuncs.size(); updateIterator++)
		{
			updateFuncs[updateIterator]();
		}

		#pragma endregion

		// Step 5.4: Swap the frame buffers (frame is over)
		glfwSwapBuffers(window);

		// Step 5.5: Check for input
		glfwPollEvents();
	}
}

void Application::Shutdown()
{
	// Step 6: Window has closed, clean up GLFW
	glfwTerminate();
}

void Application::AddUpdateFunc(UpdateFunc updateFunc)
{
	updateFuncs.push_back(updateFunc);
}

void Application::RemoveUpdateFunc(UpdateFunc updateFunc)
{
	std::vector<UpdateFunc> tempVec;
	tempVec.reserve(updateFuncs.size());
	for (int i = 0; i < updateFuncs.size(); i++)
	{
		if (updateFuncs[i] != updateFunc)
		{
			tempVec.push_back(updateFuncs[i]);
		}
	}
	updateFuncs = tempVec;
}