/*
    This source file is part of Rigs of Rods
    Copyright 2005-2012 Pierre-Michel Ricordel
    Copyright 2007-2012 Thomas Fischer
    Copyright 2013-2019 Petr Ohlidal & contributors

    For more information, see http://www.rigsofrods.org/

    Rigs of Rods is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 3, as
    published by the Free Software Foundation.

    Rigs of Rods is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Rigs of Rods. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file


#pragma once

#include "RoRPrerequisites.h"

#include "Application.h"
#include "Console.h"
#include "OgreImGui.h"


namespace RoR {
namespace GUI {

class ConsoleView
{
public:
    static const size_t MSG_DISP_LIMIT = 100u; // Quick and dirty performance trick

    ConsoleView() {}
    virtual ~ConsoleView() {}

    void DrawConsoleMessages();
    void DrawFilteringPopup(const char* name);

protected:

    bool MessageFilter(Console::Message const& m); //!< Returns true if message should be displayed

    // Filtering (true means allowed)
    bool  m_filter_expired = true;
    bool  m_filter_type_notice = true;
    bool  m_filter_type_warning = true;
    bool  m_filter_type_error = true;
    bool  m_filter_type_chat = true;
    bool  m_filter_area_echo = false; //!< Not the same thing as 'log' command!
    bool  m_filter_area_script = true;
    bool  m_filter_area_actor = true;
    bool  m_filter_area_terrn = true;
};

} // namespace GUI
} // namespace RoR
