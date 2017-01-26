#include "install.h"

Install::PackageManager Install::manager = {};

std::vector<Install::PackageManager> managers = {
		{ "apt-get", "install", "dpkg -l",            { "cmake", "g++", "gdb", "git", "libsdl2-dev", "zlib1g-dev" } },
		{ "pacman",  "-S",      "pacman -Q",          { "cmake", "gdb", "git", "sdl2" } },
		{ "dnf",     "install", "dnf list installed", { "cmake", "gcc-c++", "gdb", "git", "libstdc++-static", "mesa-libGL-devel", "SDL2-devel", "zlib-devel" } },
		{ "yum",     "install", "yum list installed", { "cmake", "gcc-c++", "gdb", "git", "libstdc++-static", "mesa-libGL-devel", "SDL2-devel", "zlib-devel" } },
		{ "emerge",  "",        "emerge -p",          { "cmake", "cmake", "dev-vcs/git", "gdb", "libsdl2 mesa" } },
};

std::string callCmd(std::string cmd)
{
	Logger::Log(Logger::DEBUG, "Calling %s", cmd.c_str());
	std::string data;
	FILE* stream;
	char buffer[256];
	cmd.append(" 2>&1");
	stream = popen(cmd.c_str(), "r");
	if (!stream)
		return data;
	while (!feof(stream))
		if (fgets(buffer, 256, stream) != NULL)
			data.append(buffer);
	pclose(stream);
	return data;
}

bool contains(std::string haystack, std::string needle)
{
	return haystack.find(needle) != std::string::npos;
}

std::string join(std::vector<std::string> vec)
{
	std::stringstream joined;
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(joined, " "));
	return joined.str();
}

bool exists(const char* file)
{
	std::ifstream f(file);
	return f.good();
}

Install::PackageManager Install::getPackageManager()
{
	for (auto& it : managers)
	{
		char* path;
		asprintf(&path, "/usr/bin/%s", it.name);
		if (exists(path))
		{
			Logger::Log(Logger::DEBUG, "%s package manager found", it.name);
			return it;
		}
	}

	return managers[0]; // idk
}

bool Install::checkDependencies()
{
	Logger::Log(Logger::DEBUG, "Checking dependencies");
	for (auto& it : Install::manager.packagesNeeded)
	{
		char* cmd;
		const char* pkg = it.c_str();
		asprintf(&cmd, "%s %s", Install::manager.check, pkg);
		std::string output = callCmd(cmd);
		if (contains(output, "error"))
		{
			Logger::Log(Logger::WARNING, "%s is missing", pkg);
			Logger::Log(Logger::WARNING, "Missing dependencies found");
			return false;
		}
		Logger::Log(Logger::DEBUG, "%s found", pkg);
	}

	Logger::Log(Logger::DEBUG, "All dependencies found");
	return true;
}

void Install::installDependencies()
{
	Logger::Log(Logger::DEBUG, "Installing dependencies");

	char* cmd;
	asprintf(&cmd, "sudo %s %s %s", Install::manager.name, Install::manager.install, join(Install::manager.packagesNeeded).c_str());
	system(cmd);
}
