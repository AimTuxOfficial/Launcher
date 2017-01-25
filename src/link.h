#pragma once

#include <gtkmm.h>

class Link : public Gtk::LinkButton
{
public:
	Link(const Glib::ustring& name, const Glib::ustring& uri);
};
