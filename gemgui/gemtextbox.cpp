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
 
#include "gemtextbox.h"

GEMTextbox::GEMTextbox(GEMForm& af, const rectangle& r) : panel<true>(af, r), f {12, FONT}
{
	Set();
}

GEMTextbox::GEMTextbox(GEMDialog& af, const rectangle& r) : panel<true>(af, r), f {12, FONT}
{
	Set();
}

void GEMTextbox::Set()
{
	tbox.create(*this, rectangle(2,2,size().width-4, size().height-4), true);
	tbox.typeface(f);	
	tbox.multi_lines(false);
	tbox.borderless(true);
	tbox.bgcolor(WHITE);
	OnPaint();
}

std::string GEMTextbox::caption()
{
	return tbox.caption();
}

void GEMTextbox::caption(string text)
{
	tbox.caption(text);
}

void GEMTextbox::tip_string(string text)
{
	tbox.tip_string(text);
}

void GEMTextbox::OnPaint()
{
	drawing dw(*this);
	dw.clear();
	dw.draw([this](paint::graphics& g)
	{	
		unsigned int w = g.size().width;
		unsigned int h = g.size().height;
		
		g.rectangle(rectangle{ 0, 0, w, h }, true, BLACK);
		g.rectangle(rectangle{ 2, 2, w-4, h-4 }, true, WHITE);
		
	});
	dw.update();
}

