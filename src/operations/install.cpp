#include "install.h"

struct PackageManager
{
	const char* name;
	const char* install;
	std::vector<std::string> packagesNeeded;
};

std::vector<PackageManager> managers = {
		{ "apt-get", "install", { "cmake", "g++", "gdb", "git", "libsdl2-dev", "zlib1g-dev" } },
		{ "pacman",  "-S",      { "base-devel", "cmake", "gdb", "git", "sdl2" } },
		{ "dnf",     "install", { "cmake", "gcc-c++", "gdb", "git", "libstdc++-static", "mesa-libGL-devel", "SDL2-devel", "zlib-devel" } },
		{ "yum",     "install", { "cmake", "gcc-c++", "gdb", "git", "libstdc++-static", "mesa-libGL-devel", "SDL2-devel", "zlib-devel" } },
		{ "emerge",  "",        { "cmake", "cmake", "dev-vcs/git", "gdb", "libsdl2 mesa" } },
};

bool exists(const char* file)
{
	std::ifstream f(file);
	return f.good();
}

PackageManager getPackageManager()
{
	for (auto& it : managers)
	{
		char* path;
		asprintf(&path, "/usr/bin/%s", it.name);
		if (exists(path))
			return it;
	}

	return managers[0]; // idk
}

bool checkDependencies()
{
	for (auto& it : getPackageManager().packagesNeeded)
	{
		// check if it's installed
	}
}

std::string join(std::vector<std::string> vec)
{
	std::stringstream joined;
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(joined, " "));
	return joined.str();
}

void Install::installDependencies()
{
	printf("Installing dependencies\n");
	PackageManager manager = getPackageManager();

	char* cmd;
	asprintf(&cmd, "sudo %s %s %s", manager.name, manager.install, join(manager.packagesNeeded).c_str());
	system(cmd);
}
