#pragma once
#include "glfw3.h"
#include "glad.h"
#include <vector>

class Application
{
private:
	GLFWwindow* window = nullptr;
	
	typedef void (*UpdateFunc)(void);
	std::vector<UpdateFunc> updateFuncs;

public:

	/// <summary>
	/// Call this before calling run or shutdown
	/// </summary>
	/// <returns>False if failed to initialise</returns>
	bool Initialise();

	/// <summary>
	/// Update functions and rendering are done here
	/// </summary>
	void Run();

	/// <summary>
	/// Clean GLFW after closing the window
	/// </summary>
	void Shutdown();

	/// <summary>
	/// Add a function to happen each frame during the update loop
	/// </summary>
	/// <param name="updateFunc">The function to invoke, as a function pointer returning void and taking no parameters</param>
	void AddUpdateFunc(UpdateFunc updateFunc);

	/// <summary>
	/// Removes a given function from the list of functions that are invoked during each update
	/// </summary>
	/// <param name="updateFunc">The function to remove, as a function pointer returning void and taking no parameters</param>
	void RemoveUpdateFunc(UpdateFunc updateFunc);
};