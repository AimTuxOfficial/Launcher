#include "install.h"

struct PackageManager
{
	const char* name;
	const char* install;
	const char* check;
	std::vector<std::string> packagesNeeded;
};

std::vector<PackageManager> managers = {
		{ "apt-get", "install", "dpkg -l",            { "cmake", "g++", "gdb", "git", "libsdl2-dev", "zlib1g-dev" } },
		{ "pacman",  "-S",      "pacman -Q",          { "cmake", "gdb", "git", "sdl2" } },
		{ "dnf",     "install", "dnf list installed", { "cmake", "gcc-c++", "gdb", "git", "libstdc++-static", "mesa-libGL-devel", "SDL2-devel", "zlib-devel" } },
		{ "yum",     "install", "yum list installed", { "cmake", "gcc-c++", "gdb", "git", "libstdc++-static", "mesa-libGL-devel", "SDL2-devel", "zlib-devel" } },
		{ "emerge",  "",        "emerge -p",          { "cmake", "cmake", "dev-vcs/git", "gdb", "libsdl2 mesa" } },
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

std::string callCmd(std::string cmd)
{
	std::string data;
	FILE* stream;
	char buffer[256];
	cmd.append(" 2>&1");
	stream = popen(cmd.c_str(), "r");
	if (stream)
	{
		while (!feof(stream))
			if (fgets(buffer, 256, stream) != NULL)
				data.append(buffer);
		pclose(stream);
	}
	return data;
}

bool contains(std::string haystack, std::string needle)
{
	return haystack.find(needle) != std::string::npos;
}

bool Install::checkDependencies()
{
	PackageManager manager = getPackageManager();
	for (auto& it : manager.packagesNeeded)
	{
		char* cmd;
		asprintf(&cmd, "%s %s", manager.check, it.c_str());
		printf("found %s", callCmd(cmd).c_str());
		if (contains(callCmd(cmd), "error"))
			return false;
	}

	return true;
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
