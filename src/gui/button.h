#pragma once

#include <gtkmm.h>

class Button : public Gtk::Button
{
public:
	Button(const Glib::ustring& name);
};
