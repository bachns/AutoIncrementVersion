/*------------------------------------------------------------------------------
   Copyright (C) 2019 by Bach Nguyen Sy
   Unauthorized copying of this file via any medium is strictly prohibited
   bachns.dev@gmail.com | github.com/bachns.dev
--------------------------------------------------------------------------------
 File name:    AutoIncrementVersion/main.cpp
 Date created: Saturday, November 02, 2019
 Written by Bach Nguyen Sy
*/

#include "IncrementVersion.h"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cerr << argv[0] << " [--build|--revision|--minor|--major] <source_directory>";
		return -1;
	}

	std::string opt = argv[1];
	std::string dir = argv[2];
	IncrementVersion incrementVersion(dir);
	incrementVersion.readAllLines();
	
	if (opt == "--build")
		incrementVersion.incrementBuild();
	else if (opt == "--revision")
		incrementVersion.incrementRevision();
	else if (opt == "--minor")
		incrementVersion.incrementMinor();
	else if (opt == "--major")
		incrementVersion.incrementMajor();

	incrementVersion.writeAllLines();
	
	return 0;
}
