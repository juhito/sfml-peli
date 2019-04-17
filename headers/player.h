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
     player.h

 2.  DESCRIPTION
      Header file for Player class

 3.  VERSIONS
       Original:
         14/4  @Jussi Perälä

       Version history:

**********************************************************************/

#if !defined(PLAYER_H)
#define PLAYER_H

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include <SFML/Graphics.hpp>

#include "assets.h"

class Assets;
enum class side;

class Player {
public:
        
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

    Player();
    ~Player();

    void init();

    int get_score();
    side get_side();

    void set_side(side s);
    void increment_score();

    void lose();
    bool has_lost();

    void draw(sf::RenderWindow& window);
    void update(Assets& asset, sf::Time& dt);

    void handle_input(sf::Event event);
private:
    sf::Texture m_texture;
    sf::Texture m_anim;
    sf::Sprite m_sprite;

    int m_score;
    side m_side;
    bool m_lost;
    bool m_input;
    float m_duration;
};

#endif
