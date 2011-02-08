/*
 * TbxAppGen tbx RISC OS toolbox library Application generator
 *
 * Copyright (C) 2010 Alan Buckley   All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
/*
 * AppInfoWindow.cc
 *
 *  Created on: 2 Jun 2010
 *      Author: alanb
 */

#include "AppInfoWnd.h"
#include "MainWnd.h"
#include "tbx/window.h"

AppInfoWnd::AppInfoWnd(tbx::Object object) :
   _view(tbx::Window(object), true)
{
	_view.window().add_about_to_be_shown_listener(this);
}

AppInfoWnd::~AppInfoWnd()
{
}

/**
 * Update view with text from select application in ancestor window
 */
void AppInfoWnd::about_to_be_shown(tbx::AboutToBeShownEvent &event)
{
	MainWnd *main_wnd = MainWnd::FromObject(event.id_block().ancestor_object());
	_view.text(main_wnd->GetAppTypeInfo());
	std::string title = "Information on application type ";
	title += main_wnd->GetAppType();
	_view.window().title(title);
}
