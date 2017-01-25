#include "mainwindow.h"

MainWindow::MainWindow()
{
	set_title("AimTux Launcher");
	//property_resizable() = false; -- do we need this?
	set_border_width(10);

	box.set_spacing(10);
	add(box);

	logo.set("assets/logo.png");
	box.pack_start(logo);
	logo.show();

	btnInstall.add_label("Install");
	btnInstall.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::install));
	box.pack_start(btnInstall);
	btnInstall.show();

	btnLoad.add_label("Load");
	btnLoad.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::load));
	btnLoad.set_can_focus(false);
	box.pack_start(btnLoad);
	btnLoad.show();

	btnUnload.add_label("Unload");
	btnUnload.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::unload));
	btnUnload.set_can_focus(false);
	box.pack_start(btnUnload);
	btnUnload.show();

	btnReload.add_label("Reload");
	btnReload.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::reload));
	btnReload.set_can_focus(false);
	box.pack_start(btnReload);
	btnReload.show();

	links.set_spacing(10);
	links.set_homogeneous(true); // makes all items the same size
	box.add(links);

	linkAimTux.add_label("AimTux Github");
	linkAimTux.set_uri("https://github.com/mcswaggens/aimtux");
	linkAimTux.set_size_request(-1, 20);
	linkAimTux.set_can_focus(false);
	links.pack_start(linkAimTux);
	linkAimTux.show();

	linkAimTuxLauncher.add_label("AimTux Launcher Github");
	linkAimTuxLauncher.set_uri("https://github.com/mcswaggens/aimtuxlauncher");
	linkAimTuxLauncher.set_size_request(-1, 20);
	linkAimTuxLauncher.set_can_focus(false);
	links.pack_start(linkAimTuxLauncher);
	linkAimTuxLauncher.show();

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
