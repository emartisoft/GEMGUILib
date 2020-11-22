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
 
#include "gemdialog.h"

GEMDialog::GEMDialog(GEMForm& owner) : form(owner, {300, 200}, appear::optional<false,appear::sizable,appear::taskbar,appear::floating>()), f{12, FONT}
{
	bgcolor(HIGHLIGHT);
	typeface(f);
	OnPaint();
	result=0;
}

void GEMDialog::OnPaint()
{
	drawing dw(*this);
	dw.clear();
	dw.draw([&](paint::graphics& g)
	{	
		int w = (int)g.size().width;
		int h = (int)g.size().height;
				
		g.rectangle(rectangle( 1, 1, (unsigned int)w-2, (unsigned int)h-2 ), false, WHITE);
		g.rectangle(rectangle( 2, 2, (unsigned int)w-4, (unsigned int)h-4 ), false, WHITE);
		g.rectangle(rectangle{ 3, 3, (unsigned int)w-6, (unsigned int)h-6 }, false, BLACK);
		g.rectangle(rectangle{ 4, 4, (unsigned int)w-8, (unsigned int)h-8 }, false, BLACK);
		g.line({1,h-1}, {w,h-1}, LIGHT);
		g.line({2,h-2}, {w,h-2}, LIGHT);
		g.line({3,h-3}, {w,h-3}, LIGHT);
		g.line({w-1,1}, {w-1,h}, LIGHT);
		g.line({w-2,2}, {w-2,h}, LIGHT);
		g.line({w-3,3}, {w-3,h}, LIGHT);
		
	});
	dw.update();
}


