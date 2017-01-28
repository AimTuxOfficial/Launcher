#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include "../logger.h"

namespace Install
{
	struct PackageManager
	{
		int id;
		const char* name;
		const char* install;
		const char* check;
		std::vector<std::string> packagesNeeded;
	};

	extern PackageManager manager;

	PackageManager GetPackageManager();
	bool CheckDependencies();
	void InstallDependencies();
	void Compile();

	namespace Git
	{
		void Clone();
		void Pull();
	}
}
