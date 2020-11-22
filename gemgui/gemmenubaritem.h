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
 
#ifndef GEMMENUBARITEM_H
#define GEMMENUBARITEM_H

#include "gemcommon.h"
#include "gemform.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>

using namespace nana;

class GEMMenubarItem : public label
{
	public:
		GEMMenubarItem(GEMForm&, const rectangle&);
		void setFont(paint::font &ft){ f = ft; }
	private:
		paint::font f;
		bool entered;
		void OnPaint();
		void OnMouseEnter(const arg_mouse& e);
		void OnMouseLeave(const arg_mouse& e);
	
};
#endif // GEMMENUBARITEM_H
