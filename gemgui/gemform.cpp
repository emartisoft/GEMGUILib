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
 
#include "gemform.h"

GEMForm::GEMForm() : form(API::make_center(640, 480), appear::optional<false,appear::sizable,appear::taskbar,appear::floating>() ),
	f{ 12, FONT}
{
	bgcolor(BLACK);
	typeface(f);
	
	w = this->size().width;
	h = this->size().height; 
	
	if (!img.open(GEMACTIVE))
			throw std::runtime_error("File not found [gemactive.bmp]");
	
	// dragBar
	dragBar.create(*this, rectangle(BUTTON_EDGE + 2, 1, w - 2*BUTTON_EDGE - 6 ,20));	
	dragBar.bgcolor(WHITE);
	dragBar.typeface(f);
	dragBar.text_align(align::center, align_v::center);
	dragBar.events().mouse_enter([&](const arg_mouse& mp) {GEMForm::OnMouseEnter(mp); });
	dragBar.events().mouse_leave([&](const arg_mouse& mp) {GEMForm::OnMouseLeave(mp); });

	// sizingGadget
	sizingGadget.create(*this, rectangle(w - BUTTON_EDGE - 2, h - BUTTON_EDGE - 2, BUTTON_EDGE, BUTTON_EDGE));
	sizingGadget.set_bground(getBground(6));
	sizingGadget.enable_focus_color(false);
	sizingGadget.cursor(cursor::size_bottom_right);
	sizingGadget.edge_effects(false);

	sizingGadget.events().mouse_move([&](const arg_mouse& mp) {GEMForm::sizingGadgetOnMouseMove(mp); });
	sizingGadget.events().mouse_enter([&](const arg_mouse& mp) {GEMForm::OnMouseEnter(mp); });
	sizingGadget.events().mouse_leave([&](const arg_mouse& mp) {GEMForm::OnMouseLeave(mp); });

	// closeGadget
	closeGadget.create(*this, rectangle(1, 1, BUTTON_EDGE, BUTTON_EDGE));
	closeGadget.set_bground(getBground(0));
	closeGadget.enable_focus_color(false);
	closeGadget.edge_effects(false);

	closeGadget.events().click([this]() {GEMForm::closeGadgetOnClicked(); });
	closeGadget.events().mouse_enter([&](const arg_mouse& mp) {GEMForm::OnMouseEnter(mp); });
	closeGadget.events().mouse_leave([&](const arg_mouse& mp) {GEMForm::OnMouseLeave(mp); });

	// zoomGadget
	zoomGadget.create(*this, rectangle(w - BUTTON_EDGE - 2, 1, BUTTON_EDGE, BUTTON_EDGE));
	zoomGadget.set_bground(getBground(1));
	zoomGadget.enable_focus_color(false);
	zoomGadget.edge_effects(false);

	zoomGadget.events().click([this]() {GEMForm::zoomGadgetOnClicked(); });
	zoomGadget.events().mouse_enter([&](const arg_mouse& mp) {GEMForm::OnMouseEnter(mp); });
	zoomGadget.events().mouse_leave([&](const arg_mouse& mp) {GEMForm::OnMouseLeave(mp); });
	
	// upGadget
	upGadget.create(*this, rectangle(w - BUTTON_EDGE - 2, 43, BUTTON_EDGE, BUTTON_EDGE));
	upGadget.set_bground(getBground(2));
	upGadget.enable_focus_color(false);
	upGadget.edge_effects(false);

	upGadget.events().click([this]() {GEMForm::upGadgetOnClicked(); });
	upGadget.events().mouse_enter([&](const arg_mouse& mp) {GEMForm::OnMouseEnter(mp); });
	upGadget.events().mouse_leave([&](const arg_mouse& mp) {GEMForm::OnMouseLeave(mp); });
	
	// downGadget
	downGadget.create(*this, rectangle(w-BUTTON_EDGE-2, h - 2*BUTTON_EDGE - 3, BUTTON_EDGE, BUTTON_EDGE));
	downGadget.set_bground(getBground(3));
	downGadget.enable_focus_color(false);
	downGadget.edge_effects(false);

	downGadget.events().click([this]() {GEMForm::downGadgetOnClicked(); });
	downGadget.events().mouse_enter([&](const arg_mouse& mp) {GEMForm::OnMouseEnter(mp); });
	downGadget.events().mouse_leave([&](const arg_mouse& mp) {GEMForm::OnMouseLeave(mp); });
	
	// leftGadget
	leftGadget.create(*this, rectangle(1, h-2-BUTTON_EDGE, BUTTON_EDGE, BUTTON_EDGE));
	leftGadget.set_bground(getBground(5));
	leftGadget.enable_focus_color(false);
	leftGadget.edge_effects(false);

	leftGadget.events().click([this]() {GEMForm::leftGadgetOnClicked(); });
	leftGadget.events().mouse_enter([&](const arg_mouse& mp) {GEMForm::OnMouseEnter(mp); });
	leftGadget.events().mouse_leave([&](const arg_mouse& mp) {GEMForm::OnMouseLeave(mp); });
	
	// rightGadget
	rightGadget.create(*this, rectangle(w - 2*BUTTON_EDGE - 3, h-2-BUTTON_EDGE, BUTTON_EDGE, BUTTON_EDGE));
	rightGadget.set_bground(getBground(4));
	rightGadget.enable_focus_color(false);
	rightGadget.edge_effects(false);

	rightGadget.events().click([this]() {GEMForm::rightGadgetOnClicked(); });
	rightGadget.events().mouse_enter([&](const arg_mouse& mp) {GEMForm::OnMouseEnter(mp); });
	rightGadget.events().mouse_leave([&](const arg_mouse& mp) {GEMForm::OnMouseLeave(mp); });
	
	// form events
	events().resized([this]() {GEMForm::OnResized(); });
	events().mouse_enter([&](const arg_mouse& mp) {GEMForm::OnMouseEnter(mp); });
	events().mouse_leave([&](const arg_mouse& mp) {GEMForm::OnMouseLeave(mp); });

	// paint
	OnPaint();
	active=true;
	is_zoomed=false;
}

void GEMForm::setTitle(string title)
{
	dragBar.caption(title);
	drawing dw(dragBar);
	dw.clear();
	dw.draw([&](paint::graphics& g)
	{	
		w = g.size().width;
		h = g.size().height;
		
		if (active)
		{ 
			for(int unsigned i=0;i<((unsigned int)(w/img.size().width) + 1);i++) img.paste(g, {static_cast <int>(1+img.size().width*i),2});
			nana::size captionSize = g.bidi_extent_size(dragBar.caption());
			g.rectangle(rectangle{ {static_cast <int>((w - captionSize.width)/2), 2}, captionSize }, true, WHITE);
			g.string({static_cast <int>((w - captionSize.width)/2), static_cast <int>((h - captionSize.height)/2)}, dragBar.caption(), BLACK);
		}
	});
	dw.update();
}

void GEMForm::setActive()
{
	active=true; 
	setTitle(dragBar.caption());
}

void GEMForm::setPreventResize()
{
	sizingGadget.enabled(false);
}

void GEMForm::setPreventZoom()
{
	zoomGadget.enabled(false);
}

void GEMForm::OnResized()
{
	w = this->size().width;
	h = this->size().height; 
	sizingGadget.move(rectangle( w - BUTTON_EDGE - 2, h - BUTTON_EDGE - 2, BUTTON_EDGE, BUTTON_EDGE));
	zoomGadget.move(rectangle(w - BUTTON_EDGE - 2, 1, BUTTON_EDGE, BUTTON_EDGE));
	upGadget.move(rectangle(w - BUTTON_EDGE - 2, 43, BUTTON_EDGE, BUTTON_EDGE));
	downGadget.move(rectangle(w - BUTTON_EDGE - 2, h - 2*BUTTON_EDGE - 3, BUTTON_EDGE, BUTTON_EDGE));
	rightGadget.move(rectangle(w - 2*BUTTON_EDGE - 3, h-2-BUTTON_EDGE, BUTTON_EDGE, BUTTON_EDGE));
	leftGadget.move(rectangle(1, h-2-BUTTON_EDGE, BUTTON_EDGE, BUTTON_EDGE));
	dragBar.size(nana::size(w - 2*BUTTON_EDGE - 6, 20));
	OnPaint();
}

void GEMForm::OnMouseEnter(const arg_mouse& e)
{
	active=true;
	setTitle(dragBar.caption());
}

void GEMForm::OnMouseLeave(const arg_mouse& e)
{
	active=false;
	setTitle(dragBar.caption());
}

void GEMForm::OnPaint()
{
	drawing dw(*this);
	dw.clear();
	dw.draw([&](paint::graphics& g)
	{	
		w = g.size().width;
		h = g.size().height;
		
		// under dragBar
		g.line(point(BUTTON_EDGE+2, 21), point(w-BUTTON_EDGE-5, 21), LIGHT);		
		// top info rect
		g.rectangle(rectangle{ 1, 24, w-4, 17 }, true, WHITE);
		// client rect
		g.rectangle(rectangle{ 1, 42, w-BUTTON_EDGE-4, h- 3*BUTTON_EDGE - 1 }, true, WHITE);
		// right scroll bar
		g.rectangle(rectangle{static_cast <int>(w-BUTTON_EDGE-2), BUTTON_EDGE*3, BUTTON_EDGE-1, h- 5*BUTTON_EDGE - 5}, true, WHITE);
		g.line(point(w-4, BUTTON_EDGE*3+1), point(w-4, h- 2*BUTTON_EDGE - 6), LIGHT);
		g.line(point(w-4, h- 2*BUTTON_EDGE - 6), point(w-1-BUTTON_EDGE, h- 2*BUTTON_EDGE - 6), LIGHT);
		// bottom scroll bar
		g.rectangle(rectangle{ BUTTON_EDGE+2, static_cast <int>(h-2-BUTTON_EDGE), w-3*BUTTON_EDGE-7, BUTTON_EDGE-1}, true, WHITE);
		g.line(point(BUTTON_EDGE+3, h-4), point(w-2*BUTTON_EDGE-6, h-4), LIGHT);
		g.line(point(w-2*BUTTON_EDGE-6, h- BUTTON_EDGE - 1), point(w-2*BUTTON_EDGE-6, h-4), LIGHT);
	});
	dw.update();
}

void GEMForm::sizingGadgetOnMouseMove(const arg_mouse& e)
{
	if (e.is_left_button())
	{
		int nw, nh;
		nw = this->size().width + e.pos.x - sizingGadget.size().width;
		nh = this->size().height + e.pos.y - sizingGadget.size().height;
		if((nw>320)&&(nh>240))
			this->size(nana::size(nw,nh));
	}
}

void GEMForm::closeGadgetOnClicked()
{
	close();
}

void GEMForm::zoomGadgetOnClicked()
{
	is_zoomed = !is_zoomed;
	
	if(is_zoomed)
	{
		pre_w = this->size().width;
		pre_h = this->size().height; 
		pre_x = this->pos().x;
		pre_y = this->pos().y;
		auto workarea = screen().get_primary().workarea();
		move(0, 0);
		outline_size({workarea.width, workarea.height});
	}
	else
	{
		move(pre_x, pre_y);
		outline_size({pre_w, pre_h});
	}
}

void GEMForm::rightGadgetOnClicked()
{
	// not implemented
}

void GEMForm::leftGadgetOnClicked()
{
	// not implemented
}

void GEMForm::upGadgetOnClicked()
{
	// not implemented
}

void GEMForm::downGadgetOnClicked()
{
	// not implemented
}

// GEMBUTTON image
// index:value
// -----------
// 0:close
// 1:maximize
// 2:uparrow
// 3:downarrow
// 4:rightarrow
// 5:leftarrow
// 6:sizing

element::bground GEMForm::getBground(unsigned char index)
{
	element::bground bg;
	bg.states({element_state::normal, element_state::pressed});
	bg.join(element_state::normal, element_state::hovered);
	bg.join(element_state::normal, element_state::focus_normal);
	bg.join(element_state::normal, element_state::focus_hovered);
	bg.join(element_state::normal, element_state::disabled);
	bg.image(paint::image(GEMBUTTON), true, rectangle{index*BUTTON_EDGE,0,BUTTON_EDGE,44});
	return bg;
}

