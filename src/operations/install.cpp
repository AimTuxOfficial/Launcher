#include "install.h"

enum
{
	UNKNOWN = 0,
	APT_GET,
	PACMAN,
	DNF,
	YUM,
	EMERGE,
};

bool exists(const char* file)
{
	std::ifstream f(file);
	return f.good();
}

int getPackageManager()
{
	std::vector<std::pair<const char*, int>> managers = {
			{ "apt-get", APT_GET },
			{ "pacman", PACMAN },
			{ "dnf", DNF },
			{ "yum", YUM },
			{ "emerge", EMERGE },
	};

	for (auto& it : managers)
	{
		char* path;
		asprintf(&path, "/usr/bin/%s", it.first);
		if (exists(path))
			return it.second;
	}

	return UNKNOWN;
}

void Install::installDependencies()
{
	printf("Installing dependencies\n");
	switch (getPackageManager())
	{
		case APT_GET:
			system("sudo apt-get install cmake g++ gdb git libsdl2-dev zlib1g-dev"); // Debian
			break;
		case PACMAN:
			system("sudo pacman -S base-devel cmake gdb git sdl2"); // Arch
			break;
		case DNF:
			system("sudo dnf install cmake gcc-c++ gdb git libstdc++-static mesa-libGL-devel SDL2-devel zlib-devel"); // Fedora
			break;
		case YUM:
			system("sudo yum install cmake gcc-c++ gdb git libstdc++-static mesa-libGL-devel SDL2-devel zlib-devel"); // Redhat
			break;
		case EMERGE:
			system("sudo emerge cmake dev-vcs/git gdb libsdl2 mesa"); // Gentoo
			break;
	}
}
