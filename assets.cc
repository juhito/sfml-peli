#include "headers/assets.h"

assets::assets() {}

assets::~assets() {}

void assets::init() {
    m_bg_t.loadFromFile("assets/bg.png");
    m_tree_t.loadFromFile("assets/tree_upper.png");
    m_tree_bt.loadFromFile("assets/tree_base.png");
    m_log_t.loadFromFile("assets/log.png");
    m_branch_t.loadFromFile("assets/branch.png");
    m_bg.setTexture(m_bg_t);
    m_bg.setPosition(0, 0);
    
    for(int i = 0; i < 6; i++) {
        m_tree_u[i].setTexture(m_tree_t);
        if(i == 0)
            m_tree_u[i].setPosition(50, 900);
        else
            m_tree_u[i].setPosition(50, m_tree_u[i-1].getPosition().y - 200);
        
        m_branches[i].setTexture(m_branch_t);
        m_branches[i].setPosition(-2000, -2000);
        m_branch_position[i] = side::NONE;
    }
    
    m_tree_b.setTexture(m_tree_bt);
    m_tree_b.setPosition(50, 1100);

    m_log.setTexture(m_log_t);
    m_log.setPosition(394, 1250);
    m_log.setScale({.56, .56});
    m_log_active = false;
    m_input = true;
}

void assets::update(sf::Time& dt) {
    if(m_log_active) {
        if(m_log_side == side::LEFT) {
            m_log.setPosition(m_log.getPosition().x + (4000 * dt.asSeconds()),
                              m_log.getPosition().y + (-2500 * dt.asSeconds()));
            //std::cout << m_log.getPosition().x << "\n";
        }
        else if(m_log_side == side::RIGHT) {
            m_log.setPosition(m_log.getPosition().x + (-4000 * dt.asSeconds()),
                              m_log.getPosition().y + (-2500 * dt.asSeconds()));
            //std::cout << m_log.getPosition().x << "\n";
        }

        if(m_log.getPosition().x < -100 ||
           m_log.getPosition().x > 1000) {
            std::cout << "LOG OUT OF VIEW!!\n";
            m_log_active = false;
            m_log.setPosition(394, 1250);
        }
    }
    
    for(int i = 0; i < 6; i++) {
        float height = i * 200;

        if(m_branch_position[i] == side::LEFT) {
            // move the sprite to left
            m_branches[i].setPosition(360, height);
            m_branches[i].setOrigin(300, 40);
            m_branches[i].setRotation(0);
        }
        else if(m_branch_position[i] == side::RIGHT) {
            // move the sprite to right
            m_branches[i].setPosition(470, height);

            m_branches[i].setOrigin(400, 170);
            m_branches[i].setRotation(180);
        }
        else
            m_branches[i].setPosition(4000, height);
    }

}

void assets::handle_input(Player& player, Text& text, sf::Event& event) {
    if(event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Left && m_input && !m_log_active) {
            m_log_active = true;
            m_log_side = side::LEFT;
            this->update_branches(player.get_score());
            text.add("Score: " + std::to_string(player.get_score()), 2);
        }
        else if(event.key.code == sf::Keyboard::Right && m_input && !m_log_active) {
            m_log_side = side::RIGHT;
            m_log_active = true;
            this->update_branches(player.get_score());
            text.add("Score: " + std::to_string(player.get_score()), 2);
        }

        m_input = false;
    }

    if(event.type == sf::Event::KeyReleased)
        m_input = true;
}

void assets::draw(sf::RenderWindow& window) {
    window.draw(m_bg);
    for(int i = 0; i < 6; i++)   
        window.draw(m_tree_u[i]);
    
    window.draw(m_tree_b);

    for(int i = 0; i < 6; i++)
        window.draw(m_branches[i]);
    
    if(m_log_active)
        window.draw(m_log);
}

void assets::update_branches(int seed) {    
    // moving all branches down one
    for(int i = 6; i > 0; i--) 
        m_branch_position[i] = m_branch_position[i - 1];

    // spawn a new branch at position 0
    // left right or none
    srand((int)time(0) + seed);
    int r = (rand() % 15);

    std::cout << r << "\n";


    if(r > 0 && r <= 5) {
        m_branch_position[0] = side::LEFT;
    }
    else if(r > 5 && r <= 10) {
        m_branch_position[0] = side::RIGHT;
    }
    else {
        m_branch_position[0] = side::NONE;
    }
}

sf::FloatRect assets::get_branch_bounds() {
    return(m_branches[5].getGlobalBounds());
}
