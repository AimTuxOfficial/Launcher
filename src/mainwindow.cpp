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

void MainWindow::load()
{
	printf("load\n");
}

void MainWindow::unload()
{
	printf("unload\n");
}

void MainWindow::reload()
{
	printf("reload\n");
}
