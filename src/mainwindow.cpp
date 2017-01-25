#include "mainwindow.h"

MainWindow::MainWindow()
{
	set_title("AimTux Launcher");
	property_resizable() = false;
	set_border_width(10);

	box.set_spacing(10);
	add(box);

	logo.set("assets/logo.png");
	box.pack_start(logo);
	logo.show();

	btnLoad.add_label("Load");
	btnLoad.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::load));
	box.pack_start(btnLoad);
	btnLoad.show();

	btnUnload.add_label("Unload");
	btnUnload.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::unload));
	box.pack_start(btnUnload);
	btnUnload.show();

	btnReload.add_label("Reload");
	btnReload.signal_pressed().connect(sigc::mem_fun(*this, &MainWindow::reload));
	box.pack_start(btnReload);
	btnReload.show();

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
