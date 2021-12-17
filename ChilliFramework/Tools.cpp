#include <fstream>
#include <iostream>
#include "Tools.h"

std::string LoadFileAsString(std::string filename)
{
	//Create and open the file reader
	std::fstream fileReader;
	fileReader.open(filename, std::ios::in);
	//If file fails to load, print in console and return an empty string
	if (!fileReader.is_open())
	{
		std::cout << "Unable to open file \"" << filename << "\"." << std::endl;
		return "";
	}
	std::string returnString = "";
	std::string readString;
	//Go through each line of the file and add it to returnString
	while (!fileReader.eof())
	{
		std::getline(fileReader, readString);
		returnString.append(readString + "\n");
	}
	fileReader.close();
	//Get rid of the extra line
	returnString.pop_back();
	if (returnString == "")
	{
		std::cout << "File \"" << filename << "\" is empty." << std::endl;
	}
	return returnString;
}