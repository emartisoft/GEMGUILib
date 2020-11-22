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
 
#ifndef GEMFORM_H
#define GEMFORM_H

#include "gemcommon.h"
#include <iostream>
#include <nana/gui.hpp>
#include <nana/gui/screen.hpp>
#include <nana/gui/dragger.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>

#define	BUTTON_EDGE	22

using namespace nana;
using namespace std;

class GEMForm : public form
{
	public:
		GEMForm();
		void setTitle(string title);
		bool active;
		void setActive();
		void setPreventResize();
		void setPreventZoom();
		label dragBar;
		void setFont(paint::font &ft){ f = ft; }
	private:
		paint::font f;
		paint::image img;
		
		button sizingGadget;
		button closeGadget;
		button zoomGadget;		
		button leftGadget;
		button rightGadget;
		button upGadget;
		button downGadget;
		
		void OnResized();
		void OnPaint();
		void OnMouseEnter(const arg_mouse& e);
		void OnMouseLeave(const arg_mouse& e);
		void sizingGadgetOnMouseMove(const arg_mouse& e);
		
		void closeGadgetOnClicked();
		void zoomGadgetOnClicked();
		void rightGadgetOnClicked();
		void leftGadgetOnClicked();
		void upGadgetOnClicked();
		void downGadgetOnClicked();

		element::bground getBground(unsigned char index);
		bool is_zoomed;
		unsigned int w, h, pre_w, pre_h, pre_x, pre_y;
};
#endif // GEMFORM_H
