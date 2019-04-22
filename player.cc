#include "headers/player.h"

Player::Player() {}

Player::~Player() {}

void Player::init() {
    m_texture.loadFromFile("assets/tm.png");
    m_texture.setSmooth(true);
    m_anim.loadFromFile("assets/tm2.png");
    m_anim.setSmooth(true);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(PLAYER_POS_LX, PLAYER_POS_Y);
    m_side = side::LEFT;
    m_score = 0;
    m_lost = false;
    m_duration = 0;
    m_input = true;
}

int Player::get_score() {
    return(m_score);
}

side Player::get_side() {
    return(m_side);
}

void Player::increment_score() {
    m_score++;
}

void Player::lose() {
    m_lost = true;
}

bool Player::has_lost() {
    return(m_lost);
}

void Player::handle_input(sf::Event& event) {
    if(event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Left && m_input) {
            m_side = side::LEFT;
            this->increment_score();               
            if(m_side == side::LEFT) {
                m_sprite.setTexture(m_anim);
                m_sprite.setScale(1.f, 1.f); // change orientation to normal
                m_sprite.setOrigin(0, 0);
                m_sprite.setPosition(PLAYER_POS_LX, PLAYER_POS_Y);
            }
        }
        else if(event.key.code == sf::Keyboard::Right && m_input) {
            m_side = side::RIGHT;
            this->increment_score();
            if(m_side == side::RIGHT) {
                m_sprite.setTexture(m_anim);
                m_sprite.setScale(-1.f, 1.f); // change orientation
                m_sprite.setOrigin(PLAYER_ORIGIN_RX, 0);
                m_sprite.setPosition(PLAYER_POS_RX, PLAYER_POS_Y);
            }
        }
        m_input = false;
    }

    if(event.type == sf::Event::KeyReleased)
        m_input = true;
}

void Player::update(Assets& asset, sf::Time& dt) {
    /*
     * NOTE:
     * The implementation of animating is awful but it was probably /
     * the only way of doing this without creating a whole animation manager system.
     */
    if(m_side != side::NONE) {
        m_duration += dt.asSeconds();
        if(m_duration > 0.2f) {
            m_duration = 0;
            m_sprite.setTexture(m_texture);
        }
    }
    
    if(m_sprite.getGlobalBounds().intersects(asset.get_branch_bounds())) {
        this->lose();
    }
}
        
void Player::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}
