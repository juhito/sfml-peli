#if !defined(GAME_H)
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "window.h"
#include "assets.h"

class Game {
public:
    Game();
    ~Game();

    sf::Time get_elapsed();
    void restart_clock();
    
    void handle_events();
    void handle_input(sf::Event event);
    void update();
    void render();

    Window* get_window();
private:
    Window m_window;
    assets m_asset;

    int score;
    bool m_input;

    sf::Texture m_texture;
    sf::Sprite m_sprite; 

    sf::Clock m_clock;
    sf::Time m_elapsed;
};

#endif
