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
 
#ifndef GEMCOMBOX_H
#define GEMCOMBOX_H

#include "gemcommon.h"
#include "gemform.h"
#include "gemdialog.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/layout_utility.hpp>

using namespace nana;

class GEMComboxRenderer : public combox::item_renderer
{  
	public:
		void setFont(paint::font &ft){ f = ft; }
	private:
		void image(bool enb, unsigned px){}    
		paint::font f ;	
		void render(widget_reference, graph_reference graph, const rectangle& r, const item_interface* item, state_t state)
		{
			graph.rectangle(r, true, (state == StateHighlighted) ? BLACK : WHITE);
			graph.typeface(f);
			graph.string({r.x + 2, r.y + 2}, item->text(), (state == StateHighlighted) ? WHITE : BLACK );
		}

		unsigned item_pixels(graph_reference graph) const
		{
			unsigned ascent, descent, ileading;
			graph.typeface(f);
			graph.text_metrics(ascent, descent, ileading);
			return ascent + descent + 4;
		}
};

class GEMCombox : public combox
{
	public:
		GEMCombox(GEMForm&, const rectangle&);
		GEMCombox(GEMDialog&, const rectangle&);
		void setFont(paint::font &ft){ f = ft; }
	private:
		paint::font f;
		void OnPaint();
		GEMComboxRenderer rend;
		void Set();
};

#endif // GEMCOMBOX_H
