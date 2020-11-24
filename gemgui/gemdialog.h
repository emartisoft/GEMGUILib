/*
 * GEMGUILib
 *
 * Copyright (C) 2020 emartisoft. All rights reserved.
 * Author: emarti, Murat Ozdemir <dtemarti@gmail.com>
 *
 * This file is distributed under the GNU General Public License, version 2
 * or at your option any later version. See <http://www.gnu.org/licenses/>.
 *
 */
 
#ifndef GEMDIALOG_H
#define GEMDIALOG_H

#include "gemcommon.h"
#include <iostream>
#include "gemform.h"
#include <nana/gui.hpp>

using namespace nana;

class GEMDialog : public form
{
	public:
		GEMDialog(GEMForm&);
		void setFont(paint::font &ft){ f = ft; }
		int result;
	private:
		paint::font f;	
		nana::size ownersize;
		void OnPaint();
		void OnResized();
};
#endif // GEMDIALOG_H
