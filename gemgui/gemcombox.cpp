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
 
#include "gemcombox.h"

GEMCombox::GEMCombox(GEMForm& af, const rectangle& r) : combox(af, r),f{12, FONT}
{
	Set();
}

GEMCombox::GEMCombox(GEMDialog& af, const rectangle& r) : combox(af, r),f{12, FONT}
{
	Set();
}

void GEMCombox::Set()
{
	bgcolor(WHITE);
	typeface(f);	
	OnPaint();
	rend.setFont(f);
	renderer(&rend);
	events().selected ( [this](const arg_combox &){ OnPaint(); });
}

void GEMCombox::OnPaint()
{
	drawing dw(*this);
	dw.clear();
	dw.draw([this](paint::graphics& g)
	{	
		unsigned int w = g.size().width;
		unsigned int h = g.size().height;		
		nana::size captionSize = g.bidi_extent_size(caption());
		
		g.rectangle(rectangle{ 0, 0, w, h }, true, BLACK);
		g.rectangle(rectangle{ 2, 2, w-4, h-4 }, true, WHITE);
		g.string({static_cast <int>((w - captionSize.width)/2), static_cast <int>((h - captionSize.height)/2)}, caption(), BLACK);
		
	});
	dw.update();
}

