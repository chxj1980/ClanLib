/*
**  ClanLib SDK
**  Copyright (c) 1997-2015 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
*/

#include "UI/precomp.h"
#include "API/UI/StandardViews/button_view.h"
#include "API/UI/StandardViews/image_view.h"

namespace clan
{
	class ButtonViewImpl
	{
	public:
		void on_pointer_press(PointerEvent &e);
		void on_pointer_release(PointerEvent &e);
		void on_pointer_enter(PointerEvent &e);
		void on_pointer_leave(PointerEvent &e);

		ButtonView *button = nullptr;
		bool _disabled = false;

		std::shared_ptr<LabelView> label;
		std::shared_ptr<ImageView> image_view;
	};

	ButtonView::ButtonView() : impl(new ButtonViewImpl())
	{
		impl->button = this;
		style()->set("flex-direction: row");

		impl->image_view = std::make_shared<ImageView>();
		impl->image_view->style()->set("flex: 0 0 main-size");
		add_subview(impl->image_view);

		impl->label = std::make_shared<LabelView>();
		impl->label->style()->set("margin: auto");
		impl->label->style()->set("flex: 1 1 main-size");
		add_subview(impl->label);

		slots.connect(sig_pointer_press(), impl.get(), &ButtonViewImpl::on_pointer_press);
		slots.connect(sig_pointer_release(), impl.get(), &ButtonViewImpl::on_pointer_release);

		slots.connect(sig_pointer_enter(), impl.get(), &ButtonViewImpl::on_pointer_enter);
		slots.connect(impl->label->sig_pointer_enter(), impl.get(), &ButtonViewImpl::on_pointer_enter);
		slots.connect(impl->image_view->sig_pointer_enter(), impl.get(), &ButtonViewImpl::on_pointer_enter);
		slots.connect(sig_pointer_leave(), impl.get(), &ButtonViewImpl::on_pointer_leave);
		slots.connect(impl->label->sig_pointer_leave(), impl.get(), &ButtonViewImpl::on_pointer_leave);
		slots.connect(impl->image_view->sig_pointer_leave(), impl.get(), &ButtonViewImpl::on_pointer_leave);
	}

	ButtonView::~ButtonView()
	{
	}

	void ButtonViewImpl::on_pointer_press(PointerEvent &e)
	{
		if (_disabled)
			return;
		button->set_state("pressed", true);
	}

	void ButtonViewImpl::on_pointer_release(PointerEvent &e)
	{
		if (_disabled)
			return;
		button->set_state("pressed", false);
	}

	void ButtonViewImpl::on_pointer_enter(PointerEvent &e)
	{
		if (_disabled)
			return;
		button->set_state("hot", true);
	}

	void ButtonViewImpl::on_pointer_leave(PointerEvent &e)
	{
		if (_disabled)
			return;
		button->set_state("hot", false);
	}

	void ButtonView::set_disabled()
	{
		if (!impl->_disabled)
		{
			impl->_disabled = true;
			set_state("hot", false);
			set_state("pressed", false);
			set_state("disabled", true);
		}
	}
	void ButtonView::set_enabled()
	{
		if (impl->_disabled)
		{
			impl->_disabled = false;
			set_state("hot", false);
			set_state("pressed", false);
			set_state("disabled", false);
		}
	}


	std::shared_ptr<LabelView> ButtonView::label()
	{
		return impl->label;
	}

	std::shared_ptr<ImageView> ButtonView::image_view()
	{
		return impl->image_view;
	}

	void ButtonView::move_label_before_image()
	{
		impl->label->remove_from_super();
		impl->image_view->remove_from_super();

		add_subview(impl->label);
		add_subview(impl->image_view);
	}

	void ButtonView::move_label_after_image()
	{
		impl->label->remove_from_super();
		impl->image_view->remove_from_super();

		add_subview(impl->image_view);
		add_subview(impl->label);
	}
}
