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
 
#ifndef GEMMENU_H
#define GEMMENU_H

#include "gemcommon.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/menu.hpp>

using namespace nana;
using namespace std;

class GEMMenuRenderer : public menu::renderer_interface
{
	public:
		GEMMenuRenderer(const pat::cloneable<renderer_interface>& rd, paint::font font = {12, FONT})
		{
			font_ = font;
			reuse_= rd;
		}
		
	private:
		void background(graph_reference graph, window wd) override
		{
			if(graph.typeface() != font_) graph.typeface(font_);
			graph.rectangle(true, WHITE);
			graph.rectangle(false, BLACK);		
		}

		void item(graph_reference graph, const rectangle& r, const attr & atr) override
		{
			if ((state::active == atr.item_state)&(atr.enabled))
			{
				graph.rectangle(r, true, BLACK);
			}
			rect_ = r;
		}

		void item_image(graph_reference graph, const point& pos, unsigned image_px, const paint::image& img) override
		{
			reuse_->item_image(graph, pos, image_px, img);
		}

		void item_text(graph_reference graph, const point& pos, const string& text, unsigned pixels, const attr& atr) override
		{
			nana::size splitCharSize = graph.bidi_extent_size("-");
			string splitCharArray = "";
			splitCharArray.append( (unsigned int)(rect_.width/splitCharSize.width) , '-');
			
			point p0{4,pos.y+(int)splitCharSize.height/2};
			point p1{4+(int)splitCharSize.width/2,(int)splitCharSize.height+pos.y};
			point p2{4+(int)splitCharSize.width,pos.y};
						
			if (state::active == atr.item_state)
			{
				if(text=="---")
				{
					graph.rectangle(rect_, true, WHITE);
					graph.string({4,pos.y}, splitCharArray, LIGHT);
				}
				else
				{
					if(atr.checked) 
					{
						graph.line(p0, p1, WHITE);
						graph.line({p0.x+1, p0.y+1}, {p1.x+1, p1.y+1}, WHITE);
						
						graph.line(p1, p2, WHITE);
						graph.line({p1.x+1, p1.y+1}, {p2.x+1, p2.y+1}, WHITE);
					}
					graph.string({(int)splitCharSize.width*3,pos.y}, text, atr.enabled ? WHITE : HIGHLIGHT);
				}
			}
			else
			{
				if(text=="---") 
				{
					graph.string({4,pos.y}, splitCharArray, LIGHT);	
				}
				else
				{
					if(atr.checked)
					{
						graph.line(p0, p1, BLACK);
						graph.line({p0.x+1, p0.y+1}, {p1.x+1, p1.y+1}, BLACK);
						
						graph.line(p1, p2, BLACK);
						graph.line({p1.x+1, p1.y+1}, {p2.x+1, p2.y+1}, BLACK);
					}
					graph.string({(int)splitCharSize.width*3,pos.y}, text, atr.enabled ? BLACK : HIGHLIGHT);
				}
			}
		}

		void sub_arrow(graph_reference graph, const point& pos, unsigned pixels, const attr & atr) override
		{
			reuse_->sub_arrow(graph, pos, pixels, atr);
		}
	private:
		pat::cloneable<renderer_interface> reuse_;
		paint::font font_;
		rectangle rect_;
};

class GEMMenu : public menu
{
	public:
		GEMMenu();
		void setFont(paint::font &ft);
		void append_separator();
		

};
#endif // GEMMENU_H
