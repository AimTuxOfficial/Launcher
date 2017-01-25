#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>

namespace Install
{
	void installDependencies();

	namespace Git
	{
		void clone();
		void pull();
	}
}
