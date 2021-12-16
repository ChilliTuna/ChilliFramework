#pragma once
#include <string>
#include <fstream>

std::string LoadFileAsString(std::string filename)
{
	std::fstream fileReader;
	fileReader.open(filename, std::ios::in);
	if (!fileReader.is_open())
	{
		return "";
	}
	std::string returnString = "";
	std::string readString;
	while (!fileReader.eof())
	{
		fileReader.getline(fileReader, readString);
		returnString.append(readString);
	}
	fileReader.close();
	return returnString;
}