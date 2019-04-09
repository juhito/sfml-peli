#if !defined(ASSETS_H)
#define ASSETS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

enum class side { LEFT, RIGHT, NONE };

class assets {
public:
    assets();
    ~assets();
    
    void init();
    void update(sf::Time& dt);
    void draw(sf::RenderWindow& window);

    bool log_active;
    void update_branches(int seed);

    side branch_position[6];
    
private:
    sf::Texture _bg_t;
    sf::Texture _tree_t;
    sf::Texture _tree_bt;
    sf::Texture _log_t;
    sf::Texture _branch_t;
    
    sf::Sprite _bg;
    sf::Sprite _tree_u[6];
    sf::Sprite _branches[6];
    sf::Sprite _tree_b;
    sf::Sprite _log;    
};

#endif
