#include "mainwindow.h"

MainWindow::MainWindow()
:
		btnInstall("Install"),
		btnLoad("Load"),
		btnUnload("Unload"),
		btnReload("Reload"),
		lnkAimtux("AimTux on Github", "https://github.com/mcswaggens/aimtux"),
		lnkAimtuxLauncher("AimTux Launcher on Github", "https://github.com/mcswaggens/aimtuxlauncher")
{
	set_title("AimTux Launcher");
	//property_resizable() = false; -- do we need this?
	set_border_width(10);

	box.set_spacing(10);
	add(box);

	logo.set("assets/logo.png");
	box.pack_start(logo);
	logo.show();

	btnInstall.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::install));
	box.pack_start(btnInstall);
	btnInstall.show();

	btnLoad.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::load));
	box.pack_start(btnLoad);
	btnLoad.show();

	btnUnload.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::unload));
	box.pack_start(btnUnload);
	btnUnload.show();

	btnReload.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::reload));
	box.pack_start(btnReload);
	btnReload.show();

	links.set_spacing(10);
	links.set_homogeneous(true); // makes all items the same size
	box.add(links);

	links.pack_start(lnkAimtux);
	lnkAimtux.show();

	links.pack_start(lnkAimtuxLauncher);
	lnkAimtuxLauncher.show();

	links.show();

	box.show();
}

MainWindow::~MainWindow()
{

}

void MainWindow::install()
{
	system("sudo apt-get install cmake g++ gdb git libsdl2-dev zlib1g-dev"); // Debian
	system("sudo pacman -S base-devel cmake gdb git sdl2"); // Arch
	system("sudo dnf install cmake gcc-c++ gdb git libstdc++-static mesa-libGL-devel SDL2-devel zlib-devel"); // Fedora
	system("sudo yum install cmake gcc-c++ gdb git libstdc++-static mesa-libGL-devel SDL2-devel zlib-devel"); // Redhat
	system("sudo emerge cmake dev-vcs/git gdb libsdl2 mesa"); // Gentoo
	system("git clone https://github.com/McSwaggens/AimTux; cd AimTux; cmake .; make -j 4; cd ..");
	printf("Done installing.\n");
}

void MainWindow::load()
{
	system("cd AimTux; ./load; cd ..");
}

void MainWindow::unload()
{
	system("cd AimTux; ./uload; cd ..");
}

void MainWindow::reload()
{
	system("cd AimTux; ./rload; cd ..");
}
