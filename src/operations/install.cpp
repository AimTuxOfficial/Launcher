#include "install.h"

Install::PackageManager Install::manager = {};

enum
{
	APT_GET,
	PACMAN,
	DNF,
	YUM,
	EMERGE,
};

std::vector<Install::PackageManager> managers = {
		{ APT_GET, "apt-get", "install", "dpkg -l",   { "cmake", "g++", "gdb", "git", "libsdl2-dev", "zlib1g-dev" } },
		{ PACMAN,  "pacman",  "-S",      "pacman -Q", { "cmake", "gdb", "git", "sdl2" } },
		{ DNF,     "dnf",     "install", "rpm -q",    { "cmake", "gcc-c++", "gdb", "git", "libstdc++-static", "mesa-libGL-devel", "SDL2-devel", "zlib-devel" } },
		{ YUM,     "yum",     "install", "rpm -q",    { "cmake", "gcc-c++", "gdb", "git", "libstdc++-static", "mesa-libGL-devel", "SDL2-devel", "zlib-devel" } },
		{ EMERGE,  "emerge",  "",        "emerge -p", { "cmake", "cmake", "dev-vcs/git", "gdb", "libsdl2 mesa" } },
};

std::string CallCmd(std::string cmd)
{
	Logger::Info("Calling %s", cmd.c_str());
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
	Logger::Info("Output: %s", data.c_str());
	return data;
}

bool Contains(std::string haystack, std::string needle)
{
	return haystack.find(needle) != std::string::npos;
}

std::string Join(std::vector<std::string> vec)
{
	std::stringstream joined;
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(joined, " "));
	return joined.str();
}

bool Exists(const char* file)
{
	std::ifstream f(file);
	return f.good();
}

Install::PackageManager Install::GetPackageManager()
{
	for (auto& it : managers)
	{
		char* path;
		asprintf(&path, "/usr/bin/%s", it.name);
		if (Exists(path))
		{
			Logger::Info("%s package manager found", it.name);
			return it;
		}
	}

	Logger::Error("Didn't find a valid package manager");
	return managers[0]; // idk
}

bool Install::CheckDependencies()
{
	Logger::Info("Checking dependencies");
	for (auto& it : Install::manager.packagesNeeded)
	{
		char* cmd;
		const char* pkg = it.c_str();
		asprintf(&cmd, "%s %s", Install::manager.check, pkg);
		std::string output = CallCmd(cmd);
		if (Contains(output, "error") || Contains(output, "not found") || output == "")
		{
			Logger::Warning("%s is missing", pkg);
			Logger::Warning("Missing dependencies found");
			return false;
		}
		Logger::Info("%s found", pkg);
	}

	Logger::Info("All dependencies found");
	return true;
}

void Install::InstallDependencies()
{
	Logger::Info("Installing dependencies");

	char* cmd;
	std::vector<std::string> packages = Install::manager.packagesNeeded;

	// special cases
	if (manager.id == PACMAN)
	{
		// This is for base-devel, as you can't check if it's installed or not the regular way.
		// I guess 99% of arch users already have it installed but whatever
		packages.push_back("base-devel");
	}

	asprintf(&cmd, "sudo %s %s %s", Install::manager.name, Install::manager.install, Join(packages).c_str());
	system(cmd);
}
