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
 
#include "gemmenubaritem.h"

GEMMenubarItem::GEMMenubarItem(GEMForm& af, const rectangle& r) : label(af, r, true), f{12, FONT}
{
	bgcolor(WHITE);
	fgcolor(BLACK);
	typeface(f);
	entered = false;
	events().mouse_enter([&](const arg_mouse& mp) {GEMMenubarItem::OnMouseEnter(mp); });
	events().mouse_leave([&](const arg_mouse& mp) {GEMMenubarItem::OnMouseLeave(mp); });
	OnPaint();
}

void GEMMenubarItem::OnPaint()
{
	drawing dw(*this);
	dw.clear();
	dw.draw([this](paint::graphics& g)
	{	
		unsigned int w = g.size().width;
		unsigned int h = g.size().height;		
		nana::size captionSize = g.bidi_extent_size(caption());
		
		g.rectangle(rectangle{ 0, 0, w, h }, true, (entered)? BLACK : WHITE);
		g.string({ (int)((w - captionSize.width)/2), (int)((h - captionSize.height)/2)}, caption(), (entered)? WHITE : BLACK);
		
	});
	dw.update();
}

void GEMMenubarItem::OnMouseEnter(const arg_mouse& e)
{
	entered = true;
	OnPaint();
}

void GEMMenubarItem::OnMouseLeave(const arg_mouse& e)
{
	entered = false;
	OnPaint();
}



