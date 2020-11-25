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
 
#include "gembutton.h"

GEMButton::GEMButton(GEMForm& af, string text, const rectangle& r) : button(af, r), f{12, FONT}
{
	caption(text);
	Set();
}

GEMButton::GEMButton(GEMDialog& af, string text, const rectangle& r) : button(af, r), f{12, FONT}
{
	caption(text);
	Set();
}

void GEMButton::Set()
{
	typeface(f);
	enable_focus_color(false);
	edge_effects(false);
	OnPaint();
	events().mouse_down([&](const arg_mouse& mp) {GEMButton::OnMouseDown(mp); });
	events().mouse_up([&](const arg_mouse& mp) {GEMButton::OnMouseUp(mp); });
	pressed = false;
}

void GEMButton::OnPaint()
{
	drawing dw(*this);
	dw.clear();
	dw.draw([this](paint::graphics& g)
	{	
		unsigned int w = g.size().width;
		unsigned int h = g.size().height;
		unsigned int p = (pressed) ? 1 : 0;		
		nana::size captionSize = g.bidi_extent_size(caption());
		
		g.rectangle(rectangle{ 0, 0, w, h }, true, BLACK);
		g.rectangle(rectangle{ 2, 2, w-4, h-4 }, true, HIGHLIGHT);
		g.rectangle(rectangle{ 2, 2, w-5, h-5 }, true, (pressed)?BLACK:WHITE);
		g.rectangle(rectangle{ 3, 3, w-5, h-5 }, true, (pressed)?WHITE:LIGHT);
		g.rectangle(rectangle{ 3, 3, w-6, h-6 }, true, HIGHLIGHT);
		g.string({static_cast <int>((w - captionSize.width)/2+p), static_cast <int>((h - captionSize.height)/2+p)}, caption(), BLACK);
		
	});
	dw.update();
}

void GEMButton::OnMouseDown(const arg_mouse& e)
{
	pressed = true;
	OnPaint();
}

void GEMButton::OnMouseUp(const arg_mouse& e)
{
	pressed = false;
	OnPaint();
}

