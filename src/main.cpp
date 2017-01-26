#include <gtkmm.h>
#include "gui/mainwindow.h"
#include "operations/install.h"

int main(int argc, char *argv[])
{
	Install::manager = Install::GetPackageManager();

	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

	MainWindow mainWindow;

	return app->run(mainWindow);
}
