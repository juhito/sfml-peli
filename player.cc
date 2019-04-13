#include "headers/player.h"

Player::Player() {}

Player::~Player() {}

void Player::init() {
    m_texture.loadFromFile("assets/tm.png");
    m_texture.setSmooth(true);
    m_anim.loadFromFile("assets/tm2.png");
    m_anim.setSmooth(true);
    m_sprite.setTexture(m_texture);
    
    m_sprite.setPosition(100, 1050);
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

void Player::set_side(side s) {
    m_side = s;
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

void Player::handle_input(sf::Event event) {
    //std::cout << "debug input\n";
    if(event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Left && m_input) {
            m_side = side::LEFT;
            //std::cout << static_cast<std::underlying_type<side>::type>(m_side) << std::endl;
            this->increment_score();               
            if(m_side == side::LEFT) {
                //std::cout << "debug" << std::endl;
                m_sprite.setTexture(m_anim);
                m_sprite.setScale(1.f, 1.f);
                m_sprite.setOrigin(0, 0);
                m_sprite.setPosition(100, 1050);
            }
        }
        else if(event.key.code == sf::Keyboard::Right && m_input) {
            m_side = side::RIGHT;
            //std::cout << static_cast<std::underlying_type<side>::type>(m_side) << std::endl;
            this->increment_score();
            if(m_side == side::RIGHT) {
                //std::cout << "debug right" << std::endl;
                m_sprite.setTexture(m_anim);
                m_sprite.setScale(-1.f, 1.f);
                m_sprite.setOrigin(300, 0);
                m_sprite.setPosition(500, 1050);
            }
        }
        m_input = false;
    }

    if(event.type == sf::Event::KeyReleased)
        m_input = true;
}

void Player::update(assets& asset, sf::Time& dt) {

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
