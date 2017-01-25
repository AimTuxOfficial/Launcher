#pragma once

#include <gtkmm.h>

class MainWindow : public Gtk::Window
{
public:
	MainWindow();
	virtual ~MainWindow();

protected:
	void load();
	void unload();
	void reload();

	Gtk::Image logo;
	Gtk::Button btnLoad;
	Gtk::Button btnUnload;
	Gtk::Button btnReload;
	Gtk::VBox box;
};
