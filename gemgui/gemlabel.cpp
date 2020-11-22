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
 
#include "gemlabel.h"

GEMLabel::GEMLabel(GEMForm& af, const rectangle& r) : label(af, r, true), f {12, FONT}
{
	Set();
}

GEMLabel::GEMLabel(GEMDialog& af, const rectangle& r) : label(af, r, true), f {12, FONT}
{
	Set();
}

void GEMLabel::Set()
{
	bgcolor(WHITE);
	typeface(f);
	transparent(true);
}
