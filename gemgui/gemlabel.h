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
 
#ifndef GEMLABEL_H
#define GEMLABEL_H

#include "gemcommon.h"
#include "gemform.h"
#include "gemdialog.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>

using namespace nana;

class GEMLabel : public label
{
	public:
		GEMLabel(GEMForm&, const rectangle&);
		GEMLabel(GEMDialog&, const rectangle&);
		void setFont(paint::font &ft){ f = ft; }
	private:
		paint::font f;
		void Set();
	
};
#endif // GEMLABEL_H
