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

	if (Install::checkDependencies())
	{
		btnLoad.signal_pressed().connect(sigc::ptr_fun(&Load::load));
		box.pack_start(btnLoad);
		btnLoad.show();

		btnUnload.signal_pressed().connect(sigc::ptr_fun(&Load::unload));
		box.pack_start(btnUnload);
		btnUnload.show();

		btnReload.signal_pressed().connect(sigc::ptr_fun(&Load::reload));
		box.pack_start(btnReload);
		btnReload.show();
	}
	else
	{
		btnInstall.signal_pressed().connect(sigc::ptr_fun(&Install::installDependencies));
		box.pack_start(btnInstall);
		btnInstall.show();
	}

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
