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
    log_active = false;
}

void assets::update(sf::Time& dt) {
    if(log_active) {
        m_log.setPosition(m_log.getPosition().x + (2000 * dt.asSeconds()),
                         m_log.getPosition().y + (-1500 * dt.asSeconds()));
        std::cout << m_log.getPosition().x << "\n";
        

        if(m_log.getPosition().x < -100 ||
           m_log.getPosition().x > 1000) {
            std::cout << "LOG OUT OF VIEW!!\n";
            log_active = false;
            m_log.setPosition(394, 1250);
        }
    }
}

void assets::draw(sf::RenderWindow& window) {
    window.draw(m_bg);
    for(int i = 0; i < 6; i++)   
        window.draw(m_tree_u[i]);
    
    window.draw(m_tree_b);

    for(int i = 0; i < 6; i++)
        window.draw(m_branches[i]);
    
    if(log_active)
        window.draw(m_log);
}

void assets::update_branches(int seed) {

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
    
    // moving all branches down one
    for(int i = 6; i > 0; i--) 
        m_branch_position[i] = m_branch_position[i - 1];
    

    // spawn a new branch at position 0
    // left right or none
    srand((int)time(0) + seed);
    int r = (rand() % 5);

    switch(r) {
        case 0:
            m_branch_position[0] = side::LEFT;
            break;
        case 1:
            m_branch_position[0] = side::RIGHT;
            break;
        default:
            m_branch_position[0] = side::NONE;
            break;
    }
}
