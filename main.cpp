/*
 * GEMGUILib Sample
 *
 * Copyright (C) 2020 emartisoft. All rights reserved.
 * Author: emarti, Murat Ozdemir <dtemarti@gmail.com>
 *
 * This file is distributed under the GNU General Public License, version 2
 * or at your option any later version. See <http://www.gnu.org/licenses/>.
 *
 */
 
#include <iostream>
#include <gemform.h>	
#include <gemlabel.h>
#include <gembutton.h>
#include <gemcommon.h>
#include <gemcombox.h>
#include <gemmenu.h>
#include <gemmenubaritem.h>
#include <gemtextbox.h>
#include <gemdialog.h>

using namespace nana;
using namespace std;

void on_menuitem_click(menu::item_proxy& itemproxy)
{	
    	switch (itemproxy.index())
    	{
    		case 7: API::exit_all(); break;
    	}
}

int main()
{
	//window
	GEMForm af;
	af.size(nana::size(640,480));
	af.setTitle("GEM Skin Demo - Nana C++ GUI Project");
	af.events().unload([&](const nana::arg_unload& ei)
			{
				GEMDialog m(af);
				m.size(nana::size(240,140));
				GEMButton bNo(m, "No", rectangle(140, 105, 90, 25));
				bNo.events().click([&m](){ m.close(); });
				
				GEMButton bYes(m, "Yes", rectangle(40, 105, 90, 25));
				bYes.events().click([&m](){ m.result=1; m.close(); });
				
				GEMLabel lInfo(m, rectangle(20,20,200,50));
				lInfo.caption("Are you sure you wanna exit?");
				m.show();
				m.modality();
				ei.cancel = {m.result==0};
			}
	);
	//af.setPreventResize();
	//af.setPreventZoom();
	
	//label
	GEMLabel lmerhaba(af, rectangle(20, 80, 350, 24));
	lmerhaba.caption("Hi, I am ATARI GUI App.");
	lmerhaba.events().mouse_enter([&]() {af.setActive();});
	
	//button
	GEMButton bAbout(af, "About", rectangle(20, 110, 90, 24));
	bAbout.events().mouse_enter([&]() {af.setActive();});
	bAbout.events().click([&](){ 
	
		//dialog
		GEMDialog d(af);
		d.size(nana::size(240,240));
		GEMButton bClose(d, "Close", rectangle(140, 205, 90, 25));
		bClose.events().click([&d](){ d.close(); });
		GEMLabel lInfo(d, rectangle(20,20,200,24));
		lInfo.caption("This is about dialog");
		d.show();
		d.modality();
	});
	
	//combox
	GEMCombox child ( af, nana::rectangle ( 20, 150, 180, 24) );
	child.push_back("Item 1");
	child.push_back("Item 2");
	child.push_back("Item 3");
	child.push_back("Item 4");
	child.push_back("Item 5");
	child.option(2);
	child.events().mouse_enter([&]() {af.setActive();});
	
	//menu
	GEMMenu mobj;
	//nana::paint::font mf{14, FONT};
	//mobj.setFont(mf);
	mobj.item_pixels(16);
	
	mobj.append ( "Open", &on_menuitem_click);
	mobj.append_separator();
	mobj.append ( "Save", &on_menuitem_click);
	mobj.append ( "Save as", &on_menuitem_click);
	mobj.append_separator();
	mobj.append ( "Atari GEM Style", &on_menuitem_click);
	mobj.append_separator();
	mobj.append ( "Exit", &on_menuitem_click);
	
	mobj.checked(5, true);
	mobj.enabled(3, false);

	//menubaritem
	GEMMenubarItem mb(af, rectangle(2, 42, 70, 24));
	mb.caption("Desk");
	mb.events().mouse_down( menu_popuper( mobj, mb, nana::point(0, 24), mouse::left_button ));
	mb.events().mouse_enter([&]() {af.setActive();});
	
	GEMMenubarItem mb2(af, rectangle(72, 42, 70, 24));
	mb2.caption("File");
	mb2.events().mouse_down( menu_popuper( mobj, mb2, nana::point(0, 24), mouse::left_button ));
	mb2.events().mouse_enter([&]() {af.setActive();});
	
	//textbox
	GEMTextbox tb(af, rectangle(20, 200, 180, 24));
	//tb.caption("test");
	tb.tip_string("enter type your name");
	tb.events().mouse_enter([&]() {af.setActive();});
	
	//show
	af.show();
	
	//drag
	dragger dg;
	dg.trigger(af.dragBar);
	dg.target(af);
	
	exec();
}

