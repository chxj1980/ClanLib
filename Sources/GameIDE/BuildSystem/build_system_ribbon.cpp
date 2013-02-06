/*
**  ClanLib SDK
**  Copyright (c) 1997-2012 The ClanLib Team
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
#include "GameIDE/precomp.h"
#include "build_system_ribbon.h"
#include "build_system.h"
#include "UIController/document_editor.h"
#include "UIController/ui_controller.h"

namespace clan
{

BuildSystemRibbon::BuildSystemRibbon(UIController *controller)
	: UIControllerListener(controller)
{
	build_section = controller->get_ribbon_section("Home", "Build");

	ResourceManager resources = build_section->get_resources();
	Canvas canvas = build_section->get_canvas();

	RibbonGroup *build_group1 = new RibbonGroup(build_section);
	RibbonGroup *build_group2 = new RibbonGroup(build_section);

	button_build = new PushButton(build_group1);
	button_build->set_text("Build");
	button_build->func_clicked().set(this, &BuildSystemRibbon::on_button_build);

	button_rebuild = new PushButton(build_group1);
	button_rebuild->set_text("Rebuild");
	button_rebuild->func_clicked().set(this, &BuildSystemRibbon::on_button_build);

	button_clean = new PushButton(build_group1);
	button_clean->set_text("Clean");
	button_clean->func_clicked().set(this, &BuildSystemRibbon::on_button_clean);

	button_show_output = new PushButton(build_group2);
	button_show_output->set_text("Output");
	button_show_output->func_clicked().set(this, &BuildSystemRibbon::on_button_show_output);

	// Always show the build section
	get_controller()->show_ribbon_section("Home", "Build");
}

void BuildSystemRibbon::set_active(DocumentEditor *doc_editor)
{
}

void BuildSystemRibbon::editor_destroyed(DocumentEditor *doc_editor)
{
}

void BuildSystemRibbon::on_button_build()
{
}

void BuildSystemRibbon::on_button_rebuild()
{
}

void BuildSystemRibbon::on_button_clean()
{
}

void BuildSystemRibbon::on_button_show_output()
{
}

}