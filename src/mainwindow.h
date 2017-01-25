#pragma once

#include <gtkmm.h>
#include "button.h"
#include "link.h"

class MainWindow : public Gtk::Window
{
public:
	MainWindow();
	virtual ~MainWindow();

protected:
	void install();
	void load();
	void unload();
	void reload();

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
