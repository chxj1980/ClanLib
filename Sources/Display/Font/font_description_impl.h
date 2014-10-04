/*
**  ClanLib SDK
**  Copyright (c) 1997-2013 The ClanLib Team
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
**    Mark Page
*/

#pragma once

namespace clan
{

class FontDescription_Impl
{
/// \name Construction
/// \{
public:
	virtual ~FontDescription_Impl() { }
/// \}

/// \name Attributes
/// \{
public:
	std::string typeface_name;
	int height = 0;
	float line_height = 0.0f;
	int average_width = 0;
	float escapement = 0.0f;
	float orientation = 0.0f;
	int weight = 0;
	bool italic = false;
	bool underline = false;
	bool strikeout = false;
	bool fixed_pitch = false;
	bool anti_alias = true;
	bool subpixel = true;
	FontDescription::Charset charset = FontDescription::charset_default;
/// \}
};

}
