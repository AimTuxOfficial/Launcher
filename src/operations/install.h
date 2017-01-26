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
		const char* name;
		const char* install;
		const char* check;
		std::vector<std::string> packagesNeeded;
	};

	extern PackageManager manager;

	PackageManager getPackageManager();
	bool checkDependencies();
	void installDependencies();
	void compile();

	namespace Git
	{
		void clone();
		void pull();
	}
}
