#pragma once
#include <string>

/// <summary>
/// Loads a given file, passed into filename, and returns its contents as a string.
/// If the file fails to load, it will return an empty string and a message in the console.
/// </summary>
/// <param name="filename">The filename and path of the file you wish to open. Filepath is relative to the executable.</param>
/// <returns>The contents of the file passed into filename.</returns>
std::string LoadFileAsString(std::string filename);