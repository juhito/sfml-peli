#if !defined(ASSETS_H)
#define ASSETS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "player.h"

enum class side { LEFT, RIGHT, NONE };

class Player;

class assets {
public:
    assets();
    ~assets();
    
    void init();
    void update(sf::Time& dt);
    void draw(sf::RenderWindow& window);
    void handle_input(Player& player, sf::Event& event);
    void update_branches(int seed);

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
