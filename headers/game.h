
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

#include "window.h"
#include "assets.h"
#include "player.h"
#include "text.h"

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/

/* Global constants */

// window stuff
#define FRAMES_PER_SECOND 60.0
#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 1024

// gameplay constants
#define DEFAULT_GAME_TIME 8.0
#define TIME_INCREMENT 0.15

class Game {
public:
    
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
    
    Game();
    ~Game();

    /**
     * \fn sf::Time get_elapsed()
     * \brief Function to get elapsed time
     * \return Elapsed time since clock restart
     */
    sf::Time get_elapsed();

    /**
     * \fn void restart_clock()
     * \brief Function to restart the clock
     * \return void
     */
    void restart_clock();

    /**
     * \fn void update()
     * \brief Function to update game logic
     * \return void
     */
    void update();

    /**
     * \fn void handle_input(sf::Event event)
     * \brief Function to handle input
     * \param event Current event to handle
     * \return void
     */
    void handle_input(sf::Event event);

    /**
     * \fn void handle_events()
     * \brief Function to poll events and handle them around
     * \return void
     */
    void handle_events();

    /**
     * \fn void render()
     * \brief Function to draw everything to the screen
     * \return void
     */
    void render();

    /**
     * \fn Window* get_window()
     * \brief Function to get private member variable
     * \return Pointer to the window class
     */
    Window* get_window();
private:
    Window m_window;
    Assets m_asset;
    Player m_player;
    Text m_score;
    Text m_time;

    sf::Texture m_texture;
    sf::Sprite m_sprite; 

    sf::Clock m_clock;
    sf::Time m_elapsed;

    float m_time_left;
};

#endif
