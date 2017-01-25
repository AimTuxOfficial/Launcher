#include "button.h"

Button::Button(const Glib::ustring& name)
{
	set_label(name);
	set_can_focus(false);
}
