#include "mainwindow.h"

MainWindow::MainWindow()
{
	this->set_title("AimTux Launcher");
	this->property_resizable() = false;
	this->set_default_size(400, 500);

	logo.set("assets/logo.png");
	grid.attach(logo, 0, 0, 40, 18);

	btnLoad.add_label("Load");
	btnLoad.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::load));
	grid.attach(btnLoad, 1, 20, 38, 2);

	btnUnload.add_label("Unload");
	btnUnload.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::unload));
	grid.attach(btnUnload, 1, 26, 38, 2);

	btnReload.add_label("Reload");
	btnReload.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::reload));
	grid.attach(btnReload, 1, 32, 38, 2);

	grid.show_all();

	add(grid);
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