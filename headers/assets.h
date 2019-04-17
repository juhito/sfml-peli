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
     assets.h

 2.  DESCRIPTION
      Header file for Assets class

 3.  VERSIONS
       Original:
         14/4  @Jussi Perälä

       Version history:

**********************************************************************/

#if !defined(ASSETS_H)
#define ASSETS_H

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "player.h"
#include "text.h"

enum class side { LEFT, RIGHT, NONE };

class Player;

class Assets {
public:

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
    
    Assets();
    ~Assets();
    
    void init();
    void update(sf::Time& dt);
    void update_branches(int seed);

    void draw(sf::RenderWindow& window);
    void handle_input(Player& player, Text& text, sf::Event& event);
    
    sf::FloatRect get_branch_bounds();
private:
    sf::Texture m_bg_t;
    sf::Texture m_tree_t;
    sf::Texture m_tree_bt;
    sf::Texture m_log_t;
    sf::Texture m_branch_t;
    
    sf::Sprite m_bg;
    sf::Sprite m_tree_u[6];
    sf::Sprite m_branches[6];
    sf::Sprite m_tree_b;
    sf::Sprite m_log;

    bool m_input;
    bool m_log_active;
    side m_log_side;
    side m_branch_position[6];
};

#endif
