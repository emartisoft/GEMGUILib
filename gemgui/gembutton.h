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
 
#ifndef GEMBUTTON_H
#define GEMBUTTON_H

#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include "gemcommon.h"
#include "gemform.h"
#include "gemdialog.h"

using namespace nana;
using namespace std;

class GEMButton : public button
{
	public:
		GEMButton(GEMForm&, string, const rectangle&);
		GEMButton(GEMDialog&, string, const rectangle&);
		void setFont(paint::font &ft){ f = ft; }
	private:
		paint::font f;
		bool pressed;
		void OnMouseDown(const arg_mouse& e);
		void OnMouseUp(const arg_mouse& e);
		void OnPaint();
		void Set();
};
#endif // GEMBUTTON_H
