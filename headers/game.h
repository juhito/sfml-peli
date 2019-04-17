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
     game.h

 2.  DESCRIPTION
      Header file for Game class

 3.  VERSIONS
       Original:
         14/4  @Jussi Perälä

       Version history:

**********************************************************************/

#if !defined(GAME_H)
#define GAME_H

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include <SFML/Graphics.hpp>

#include <iostream>
#include "window.h"
#include "assets.h"
#include "player.h"
#include "text.h"

class Game {
public:
    
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
    
    Game();
    ~Game();

    sf::Time get_elapsed();
    void restart_clock();
    
    void update();

    void handle_input(sf::Event event);
    void handle_events();
    
    void render();
    Window* get_window();
private:
    Window m_window;
    Assets m_asset;
    Player m_player;
    Text m_text;

    sf::Texture m_texture;
    sf::Sprite m_sprite; 

    sf::Clock m_clock;
    sf::Time m_elapsed;

    float m_time_left;
};

#endif
