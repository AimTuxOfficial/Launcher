#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>

namespace Install
{
	bool checkDependencies();
	void installDependencies();
	void compile();

	namespace Git
	{
		void clone();
		void pull();
	}
}
