#if !defined(GAME_H)
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "window.h"
#include "assets.h"
#include "player.h"

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
    Player m_player;

    bool m_input;
    int m_score;

    sf::Texture m_texture;
    sf::Sprite m_sprite; 

    sf::Clock m_clock;
    sf::Time m_elapsed;
};

#endif
