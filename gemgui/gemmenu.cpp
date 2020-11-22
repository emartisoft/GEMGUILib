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
 
#include "gemmenu.h"

using namespace nana;

GEMMenu::GEMMenu()
{
	renderer(GEMMenuRenderer{renderer()});
}

void GEMMenu::setFont(paint::font &ft)
{ 
	renderer(GEMMenuRenderer{renderer(), ft}); 
}

void GEMMenu::append_separator()
{
	append("---");
}
