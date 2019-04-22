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

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/

/* Global constants */

// positions
#define PLAYER_POS_LX 100
#define PLAYER_POS_RX 500
#define PLAYER_POS_Y 1050
#define PLAYER_ORIGIN_RX 300

class Assets;
enum class side;

class Player {
public:
        
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

    Player();
    ~Player();

    /**
     * \fn void init()
     * \brief Function to init textures and positions for this class
     * \return void
     */
    void init();

    /**
     * \fn int get_score()
     * \brief Function to get player's score
     * \return current score
     */
    int get_score();

    /**
     * \fn side get_side()
     * \brief Function to get player's side
     * \return player's side which is an enum
     */
    side get_side();

    /**
     * \fn void increment_score()
     * \brief Function to increment player's score
     * \return void
     */
    void increment_score();

    /**
     * \fn void lose()
     * \brief Function to make player lose
     * \return void
     */
    void lose();

    /**
     * \fn bool has_lost()
     * \brief Function to check if you've lost
     * \return true if lost, false otherwise
     */
    bool has_lost();

    /**
     * \fn void draw(sf::RenderWindow& window)
     * \brief Function to draw everything to screen
     * \param window Drawable window
     * \return void
     */
    void draw(sf::RenderWindow& window);

    /**
     * \fn void update(Assets& asset, sf::Time& dt)
     * \brief Function to animate player and check if you've lost
     * \param asset For getting bounds of the last branch
     * \param dt Calculated delta time
     * \return void
     */
    void update(Assets& asset, sf::Time& dt);

    /**
     * \fn void handle_input(sf::Event& event)
     * \brief Function to handle player input
     * \param event Event class by reference for getting the current event
     * \return void
     */
    void handle_input(sf::Event& event);
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
