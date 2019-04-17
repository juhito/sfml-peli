/***************************************************************************
 *   Copyright (C) 2019 by Jussi Perälä                                    *
 *   https://github.com/juhito                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
     window.h

 2.  DESCRIPTION
      Header file for Window class

 3.  VERSIONS
       Original:
         14/4  @Jussi Perälä

       Version history:

**********************************************************************/

#if !defined(WINDOW_H)
#define WINDOW_H

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Window {
public:
        
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

    Window();
    Window(const std::string& title, const sf::Vector2u& size);
    ~Window();

    void begin_draw();
    void end_draw();

    void listen_events(sf::Event event);

    bool is_done();
    bool is_fullscreen();

    void toggle_fullscreen();
    void toggle_done();

    sf::Event& get_event();
    sf::RenderWindow* get_render_window();
    sf::Vector2u get_window_size();

    void draw(sf::Drawable& asset);
private:
    void setup(const std::string& title, const sf::Vector2u& size);
    void destroy();
    void create();

    sf::RenderWindow m_window;
    sf::View m_view;
    sf::Event m_event;
    sf::Vector2u m_wsize;
    std::string m_wtitle;

    bool m_done;
    bool m_fullscreen;
};

#endif
