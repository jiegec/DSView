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


#ifndef DSLOGIC_PV_SEARCH_H
#define DSLOGIC_PV_SEARCH_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include "../sigsession.h"
#include <libsigrok4DSLogic/libsigrok.h>

namespace Ui {
class Search;
}

namespace pv {
namespace dialogs {

class Search : public QDialog
{
    Q_OBJECT

public:

    Search(QWidget *parent = 0, sr_dev_inst *sdi = 0, QString pattern = "");
    ~Search();

    QString get_pattern();

protected:
    void accept();

signals:
    
public slots:
    
private:
    Ui::Search *ui;
    sr_dev_inst *_sdi;
};

} // namespace decoder
} // namespace pv

#endif // DSLOGIC_PV_SEARCH_H
