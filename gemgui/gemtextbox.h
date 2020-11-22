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
 
#ifndef GEMTEXTBOX_H
#define GEMTEXTBOX_H

#include "gemcommon.h"
#include "gemform.h"
#include "gemdialog.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/panel.hpp>

using namespace nana;
using namespace std;

class GEMTextbox : public panel<true>
{
	public:
		GEMTextbox(GEMForm&, const rectangle&);
		GEMTextbox(GEMDialog&, const rectangle&);
		void setFont(paint::font &ft){ f = ft; }
		string caption();
		void caption(string);
		void tip_string(string);
	private:
		paint::font f;
		textbox tbox;
		void OnPaint();
		void Set();
	
};
#endif // GEMTEXTBOX_H
