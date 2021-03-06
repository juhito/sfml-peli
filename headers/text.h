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
     Text.h

 2.  DESCRIPTION
      Header file for Text class

 3.  VERSIONS
       Original:
         14/4  @Jussi Perälä

       Version history:

**********************************************************************/

#if !defined(TEXT_H)
#define TEXT_H

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include <string>
#include <SFML/Graphics.hpp>

class Text {
public:
    
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
    
    Text();

    /**
     * \fn Text(int csize, sf::Vector2f pos)
     * \brief Constructor with parameters for calling the setup method
     * \param csize Font size
     * \param pos Font position on the window
     */
    Text(int csize, sf::Vector2f pos);
    
    ~Text();

    /**
     * \fn void setup(int csize, sf::Vector2f pos)
     * \brief Function to setup text class for drawing
     * \param csize Font size
     * \param pos Position on the window
     * \return void
     */
    void setup(int csize, sf::Vector2f pos);

    /**
     * \fn void add(const std::string& message)
     * \brief Function to change the current message
     * \param message Message you want to display
     * \return void
     */
    void add(std::string message);

    /**
     * \fn void clear()
     * \brief Function to clear the current message buffer
     * \return void
     */
    void clear();

    /**
     * \fn void draw(sf::RenderWindow& window)
     * \brief Function to draw everything to the screen
     * \param window Drawable window
     * \return void
     */
    void draw(sf::RenderWindow& window);
private:
    sf::Font m_font;
    sf::Text m_content;

    std::string m_string;
};

#endif
