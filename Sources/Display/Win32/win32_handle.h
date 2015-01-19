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
**    Chu Chin Kuan
*/

#pragma once

#include "API/Display/Window/display_window_description.h"

#if !defined(WIN32)
#error This file should only be included on Windows builds.
#else

namespace clan
{

/** Platform-specific display window handle container.
 *  This is the implementation for Win32 display windows.
 */
/*
class DisplayWindowHandle
{
public:
	HWND hwnd;

	DisplayWindowHandle() = delete;
	DisplayWindowHandle(DisplayWindowHandle const &other) : DisplayWindowHandle(other.hwnd) { }
	DisplayWindowHandle(HWND _hwnd) : hwnd(_hwnd) { }

	operator HWND() const { return hwnd; }
};
*/
}

#endif
