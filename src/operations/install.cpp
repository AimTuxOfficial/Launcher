#include "install.h"

void Install::installDependencies()
{
	system("sudo apt-get install cmake g++ gdb git libsdl2-dev zlib1g-dev"); // Debian
	system("sudo pacman -S base-devel cmake gdb git sdl2"); // Arch
	system("sudo dnf install cmake gcc-c++ gdb git libstdc++-static mesa-libGL-devel SDL2-devel zlib-devel"); // Fedora
	system("sudo yum install cmake gcc-c++ gdb git libstdc++-static mesa-libGL-devel SDL2-devel zlib-devel"); // Redhat
	system("sudo emerge cmake dev-vcs/git gdb libsdl2 mesa"); // Gentoo
	printf("Done installing dependencies\n");
}
