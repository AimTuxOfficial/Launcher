#include "link.h"

Link::Link(const Glib::ustring& name, const Glib::ustring& uri)
{
	add_label(name);
	set_uri(uri);
	set_can_focus(false);
}
