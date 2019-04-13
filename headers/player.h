#if !defined(PLAYER_H)
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "assets.h"

class assets;
enum class side;

class Player {
public:
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
    void update(assets& asset, sf::Time& dt);

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
