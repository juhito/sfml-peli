#include "headers/assets.h"

Assets::Assets() {}

Assets::~Assets() {}

void Assets::init() {
    m_bg_t.loadFromFile("assets/bg.png");
    m_tree_t.loadFromFile("assets/tree_upper.png");
    m_tree_bt.loadFromFile("assets/tree_base.png");
    m_log_t.loadFromFile("assets/log.png");
    m_branch_t.loadFromFile("assets/branch.png");
    m_bg.setTexture(m_bg_t);
    m_bg.setPosition(0, 0);
    
    for(int i = 0; i < TREE_COUNT; i++) {
        m_tree_u[i].setTexture(m_tree_t);

        if(i == 0)
            m_tree_u[i].setPosition(TREE_POS_X, TREE_DEFAULT_Y);
        else
            m_tree_u[i].setPosition(TREE_POS_X, m_tree_u[i-1].getPosition().y - TREE_SIZE_STUMP);
        
        m_branches[i].setTexture(m_branch_t);
        m_branches[i].setPosition(OUT_OF_VIEW, OUT_OF_VIEW);
        m_branch_position[i] = side::NONE;
    }
    
    m_tree_b.setTexture(m_tree_bt);
    m_tree_b.setPosition(TREE_POS_X, TREE_POS_STUMP);

    m_log.setTexture(m_log_t);
    m_log.setPosition(LOG_DEFAULT_X, LOG_DEFAULT_Y);
    m_log.setScale({LOG_SCALE_W, LOG_SCALE_H});
    m_log_active = false;
    m_input = true;
}

void Assets::update(sf::Time& dt) {
    if(m_log_active) {
        if(m_log_side == side::LEFT) {
            // if log side is left, shoot to right
            m_log.setPosition(m_log.getPosition().x + (LOG_SPEED_X * dt.asSeconds()),
                              m_log.getPosition().y + (LOG_SPEED_Y * dt.asSeconds()));
        }
        else if(m_log_side == side::RIGHT) {
            // if log side is right, shoot to left
            m_log.setPosition(m_log.getPosition().x + (-LOG_SPEED_X * dt.asSeconds()),
                              m_log.getPosition().y + (LOG_SPEED_Y * dt.asSeconds()));
        }

        if(m_log.getPosition().x < LOG_MIN_X ||
           m_log.getPosition().x > LOG_MAX_X) {
            // log gets out of view, reset to default
            m_log_active = false;
            m_log.setPosition(LOG_DEFAULT_X, LOG_DEFAULT_Y);
        }
    }
    
    for(int i = 0; i < 6; i++) {
        float height = i * BRANCH_POS_GAP;

        if(m_branch_position[i] == side::LEFT) {
            // move the sprite to left
            m_branches[i].setPosition(BRANCH_POS_LEFT_X, height);
            m_branches[i].setOrigin(BRANCH_ORIGIN_LEFT_X, BRANCH_ORIGIN_LEFT_Y);
            m_branches[i].setRotation(0);
        }
        else if(m_branch_position[i] == side::RIGHT) {
            // move the sprite to right
            m_branches[i].setPosition(BRANCH_POS_RIGHT_X, height);

            m_branches[i].setOrigin(BRANCH_ORIGIN_RIGHT_X, BRANCH_ORIGIN_RIGHT_Y);
            m_branches[i].setRotation(180);
        }
        else
            m_branches[i].setPosition(OUT_OF_VIEW, height); // if side::none, set out of view
    }
}

void Assets::handle_input(Player& player, Text& text, sf::Event& event) {
    if(event.type == sf::Event::KeyPressed) {
        text.add("Score: " + std::to_string(player.get_score()));
        if(event.key.code == sf::Keyboard::Left && m_input && !m_log_active) {
            m_log_active = true;
            m_log_side = side::LEFT;
            this->update_branches(player.get_score());
        }
        else if(event.key.code == sf::Keyboard::Right && m_input && !m_log_active) {
            m_log_side = side::RIGHT;
            m_log_active = true;
            this->update_branches(player.get_score());
        }
        m_input = false;
    }
    
    if(event.type == sf::Event::KeyReleased)
        m_input = true;
}

void Assets::draw(sf::RenderWindow& window) {
    window.draw(m_bg);
    for(int i = 0; i < TREE_COUNT; i++)   
        window.draw(m_tree_u[i]);
    
    window.draw(m_tree_b);

    for(int i = 0; i < BRANCH_COUNT; i++)
        window.draw(m_branches[i]);
    
    if(m_log_active)
        window.draw(m_log);
}

void Assets::update_branches(int seed) {    
    // moving all branches down one
    for(int i = BRANCH_COUNT; i > 0; i--) 
        m_branch_position[i] = m_branch_position[i - 1];

    // spawn a new branch at position 0
    // left right or none
    srand((int)time(0) + seed);
    int r = (rand() % 15);

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

sf::FloatRect Assets::get_branch_bounds() {
    return(m_branches[BRANCH_COUNT - 1].getGlobalBounds());
}
