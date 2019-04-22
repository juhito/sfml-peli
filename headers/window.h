/***************************************************************************
 *   Copyright (C) 2019 by Jussi Perälä                                    *
 *   https://github.com/juhito                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   (at your option) any later version.                                   *
 *   the Free Software Foundation; either version 2 of the License, or     *
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
#include <SFML/Graphics.hpp>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/

/* Global constants */

// original texture sizes needed for scaling
#define M_VIEW_X 900.0
#define M_VIEW_Y 1600.0

class Window {
public:
        
/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/

    /**
     * \fn Window()
     * \brief Default constructor for window
     */
    Window();

    /**
     * \fn Window(const std::string& title, const sf::Vector2u& size)
     * \brief Constructor with parameters for calling the setup method
     * \param title Window title
     * \param size Window size
     */
    Window(const std::string& title, const sf::Vector2u& size);
    ~Window();

    /**
     * \fn void begin_draw()
     * \brief Function to start drawing (clears the screen)
     * \return void
     */
    void begin_draw();

    /**
     * \fn void end_draw()
     * \brief Function to end drawing (displays everything that's been drawed)
     * \return void
     */
    void end_draw();

    /**
     * \fn void handle_events(sf::Event& event)
     * \brief Function to poll events and handle them
     * \param event Current event to handle
     * \return void
     */
    void handle_events(sf::Event& event);

    /**
     * \fn bool is_done()
     * \brief Function to check if we should close the window
     * \return true if we should close, false otherwise
     */
    bool is_done();

    /**
     * \fn sf::Event get_event()
     * \brief Function to get the event member variable
     * \return Reference to the event member variable
     */
    sf::Event& get_event();

    /**
     * \fn sf::RenderWindow* get_render_window()
     * \brief Function to get the current window
     * \return Pointer to the window
     */
    sf::RenderWindow* get_render_window();

    /**
     * \fn sf::Vector2u get_window_size()
     * \brief Function to get the window size
     * \return Returns the dimensions of the window as Vector2u
     */
    sf::Vector2u get_window_size();

    /**
     * \fn void draw(sf::Drawable& asset)
     * \brief Function to draw everything to the screen
     * \param asset Any asset that is child of Drawable
     * \return void
     */
    void draw(sf::Drawable& asset);
private:
    /**
     * \fn void setup(const std::string& title, const sf::Vector2u& size)
     * \brief Function to initialize properties for window and call private create method
     * \param title Window title
     * \param size Window size
     * \return void
     */
    void setup(const std::string& title, const sf::Vector2u& size);

    /**
     * \fn void destroy()
     * \brief Function to destroy window
     * \return void
     */
    void destroy();

    /**
     * \fn void create()
     * \brief Function to create window with properties
     * \return void
     */
    void create();

    sf::RenderWindow m_window;
    sf::View m_view;
    sf::Event m_event;
    sf::Vector2u m_wsize;
    std::string m_wtitle;

    bool m_done;
};

#endif
