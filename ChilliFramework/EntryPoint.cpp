//Currently testing library implementation. Rearchitecture current setup after confirming libraries are setup correctly
#define GLFW_INCLUDE_NONE
#include "glfw3.h"
#include "glad.h"

int main()
{
	GLFWwindow* window;
	
	// Step 1: Initialise GLFW
	if (!glfwInit())
	{
		return -1;
	}

	// Step 2: Create window
	window = glfwCreateWindow(1280, 720, "ChilliFramework", nullptr, nullptr);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Step 3: Define which window should be rendered to
	glfwMakeContextCurrent(window);

	// Step 4: Load GLAD's GL functions
	if (!gladLoadGL())
	{
		return -1;
	}
	
	#pragma region PreRenderRegion
	
	float col = 0;
	bool colIncrease = true;

	#pragma endregion

	// Step 5: Run the "game" loop
	while (!glfwWindowShouldClose(window))
	{
		// Step 5.1: Clear screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Step 5.2: Render stuff here
		#pragma region RenderRegion


		if (col >= 1)
		{
			colIncrease = false;
		}
		else if (col <= 0)
		{
			colIncrease = true;
		}

		if (colIncrease ? col += 0.01f : col -= 0.01f);

		glClearColor(col, 0, 1 - col, 1);


		#pragma endregion

		// Step 5.3: Swap the frame buffers (frame is over)
		glfwSwapBuffers(window);

		// Step 5.4: Check for input
		glfwPollEvents();
	}

	// Step 6: Window has closed, clean up GLFW
	glfwTerminate();
	return 0;

}