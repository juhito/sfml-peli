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

#include <SFML/Graphics.hpp>

#include "player.h"
#include "text.h"

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/

/* Global constants */

// TREE CONSTANTS
#define TREE_COUNT 6
#define TREE_POS_X 50
#define TREE_POS_STUMP 1100
#define TREE_SIZE_STUMP 200
#define TREE_DEFAULT_Y 900

// LOG CONSTANTS
#define LOG_DEFAULT_X 394
#define LOG_DEFAULT_Y 1250
#define LOG_SCALE_W .56
#define LOG_SCALE_H .56
#define LOG_MIN_X -100
#define LOG_MAX_X 1000
#define LOG_SPEED_X 4000
#define LOG_SPEED_Y -2500

// BRANCH CONSTANTS
#define BRANCH_COUNT 6
#define BRANCH_ORIGIN_LEFT_X 300
#define BRANCH_ORIGIN_LEFT_Y 40
#define BRANCH_ORIGIN_RIGHT_X 400
#define BRANCH_ORIGIN_RIGHT_Y 170
#define BRANCH_POS_LEFT_X 360
#define BRANCH_POS_RIGHT_X 470
#define BRANCH_POS_GAP 200

// MISC
#define OUT_OF_VIEW 4000

enum class side { LEFT, RIGHT, NONE };
class Player;

class Assets {
public:

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
    
    Assets();
    ~Assets();

    /**
     * \fn void init()
     * \brief Function to initializes textures and positions for this class
     * \return void
     */
    void init();
    
    /**
     * \fn void update(sf::Time& dt)
     * \brief Function to update chopped log based on it's side and
              sets branch position based on it's side
     * \param dt Calculated delta time
     * \return void
     */
    void update(sf::Time& dt);
    
    /**
     * \fn void update_branches(int seed)
     * \brief Function to update branch position on the tree
     * \param seed Integer number for seeding (player's score)
     * \return void
     */
    void update_branches(int seed);

    /**
     * \fn void draw(sf::RenderWindow& window)
     * \brief Function to draw everything to the screen
     * \param window Drawable window
     * \return void
     */
    void draw(sf::RenderWindow& window);
    
    /**
     * \fn void handle_input(Player& player, Text& text, sf::Event& event)
     * \brief Function to update log, score and branches based on input
     * \param player Player class by reference for getting the score
     * \param text Text class by reference for updating score text
     * \param event Event class by reference for getting the current event
     * \return void
     */
    void handle_input(Player& player, Text& text, sf::Event& event);
    
    /**
     * \fn sf::FloatRect get_branch_bounds()
     * \brief Function for getting bounds of the lowest branch
     * \return "Rectangle" with global coordinates
     */
    sf::FloatRect get_branch_bounds();
private:
    sf::Texture m_bg_t;
    sf::Texture m_tree_t;
    sf::Texture m_tree_bt;
    sf::Texture m_log_t;
    sf::Texture m_branch_t;
    
    sf::Sprite m_bg;
    sf::Sprite m_tree_u[TREE_COUNT];
    sf::Sprite m_branches[BRANCH_COUNT];
    sf::Sprite m_tree_b;
    sf::Sprite m_log;

    bool m_input;
    bool m_log_active;
    side m_log_side;
    side m_branch_position[BRANCH_COUNT];
};

#endif
