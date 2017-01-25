#include <gtkmm.h>
#include "mainwindow.h"

void CheckUpdate()
{
	printf("No new update for AimTux\n");
}

int main(int argc, char *argv[])
{
	CheckUpdate();

	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

	MainWindow mainWindow;

	return app->run(mainWindow);
}
