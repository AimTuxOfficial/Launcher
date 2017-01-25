#pragma once

#include <gtkmm.h>

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
	Gtk::Button btnInstall;
	Gtk::Button btnLoad;
	Gtk::Button btnUnload;
	Gtk::Button btnReload;
	Gtk::LinkButton linkAimTux;
	Gtk::LinkButton linkAimTuxLauncher;
	Gtk::VBox box;
	Gtk::HBox links;
};
