#pragma once

#include <gtkmm.h>
#include "button.h"
#include "link.h"
#include "../operations/install.h"
#include "../operations/load.h"

class MainWindow : public Gtk::Window
{
public:
	MainWindow();
	virtual ~MainWindow();

protected:
	Gtk::Image logo;
	Button btnInstall;
	Button btnLoad;
	Button btnUnload;
	Button btnReload;
	Link lnkAimtux;
	Link lnkAimtuxLauncher;
	Gtk::VBox box;
	Gtk::HBox links;
};
