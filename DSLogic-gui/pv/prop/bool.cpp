/*
 * This file is part of the DSLogic-gui project.
 * DSLogic-gui is based on PulseView.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 * Copyright (C) 2013 DreamSourceLab <dreamsourcelab@dreamsourcelab.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */


#include <assert.h>

#include <QCheckBox>

#include "bool.h"

using namespace std;
using namespace boost;

namespace pv {
namespace prop {

Bool::Bool(QString name, Getter getter, Setter setter) :
	Property(name, getter, setter),
	_check_box(NULL)
{
}

Bool::~Bool()
{
}

QWidget* Bool::get_widget(QWidget *parent)
{
	if (_check_box)
		return _check_box;

	_check_box = new QCheckBox(name(), parent);

	GVariant *const value = _getter ? _getter() : NULL;

	if (value) {
		_check_box->setCheckState(g_variant_get_boolean(value) ?
			Qt::Checked : Qt::Unchecked);
		g_variant_unref(value);
	}

	return _check_box;
}

bool Bool::labeled_widget() const
{
	return true;
}

void Bool::commit()
{
	assert(_setter);

	if (!_check_box)
		return;

	_setter(g_variant_new_boolean(
		_check_box->checkState() == Qt::Checked));
}

} // prop
} // pv
