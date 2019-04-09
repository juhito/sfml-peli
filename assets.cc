#include "headers/assets.h"

assets::assets() {}

assets::~assets() {}

void assets::init() {
    _bg_t.loadFromFile("assets/bg.png");
    _tree_t.loadFromFile("assets/tree_upper.png");
    _tree_bt.loadFromFile("assets/tree_base.png");
    _log_t.loadFromFile("assets/log.png");
    _branch_t.loadFromFile("assets/branch.png");
    _bg.setTexture(_bg_t);
    _bg.setPosition(0, 0);
    
    for(int i = 0; i < 6; i++) {
        _tree_u[i].setTexture(_tree_t);
        if(i == 0)
            _tree_u[i].setPosition(50, 900);
        else
            _tree_u[i].setPosition(50, _tree_u[i-1].getPosition().y - 200);
    }

    for(int i = 0; i < 6; i++) {
        _branches[i].setTexture(_branch_t);
        _branches[i].setPosition(-2000, -2000);
        branch_position[i] = side::NONE;
    }
    
    _tree_b.setTexture(_tree_bt);
    _tree_b.setPosition(50, 1100);

    _log.setTexture(_log_t);
    _log.setPosition(394, 1250);
    _log.setScale({.56, .56});
    log_active = false;
}

void assets::update(sf::Time& dt) {
    if(log_active) {
        _log.setPosition(_log.getPosition().x + (2000 * dt.asSeconds()),
                         _log.getPosition().y + (-1500 * dt.asSeconds()));
        std::cout << _log.getPosition().x << "\n";
        

        if(_log.getPosition().x < -100 ||
           _log.getPosition().x > 1000) {
            std::cout << "LOG OUT OF VIEW!!\n";
            log_active = false;
            _log.setPosition(394, 1250);
        }
    }
}

void assets::draw(sf::RenderWindow& window) {
    window.draw(_bg);
    for(int i = 0; i < 6; i++)   
        window.draw(_tree_u[i]);
    
    window.draw(_tree_b);

    for(int i = 0; i < 6; i++)
        window.draw(_branches[i]);
    
    if(log_active)
        window.draw(_log);
}

void assets::update_branches(int seed) {

    for(int i = 0; i < 6; i++) {
        float height = i * 150;

        if(branch_position[i] == side::LEFT) {
            // move the sprite to left
            _branches[i].setPosition(360, height);
            _branches[i].setOrigin(300, 40);
            _branches[i].setRotation(0);
        }
        else if(branch_position[i] == side::RIGHT) {
            // move the sprite to right
            _branches[i].setPosition(470, height);

            _branches[i].setOrigin(400, 40);
            _branches[i].setRotation(180);
        }
        else
            _branches[i].setPosition(4000, height);
    }
    
    // moving all branches down one
    for(int i = 5; i > 0; i--) 
        branch_position[i] = branch_position[i - 1];
    

    // spawn a new branch at position 0
    // left right or none
    srand((int)time(0) + seed);
    int r = (rand() % 5);

    switch(r) {
        case 0:
            branch_position[0] = side::LEFT;
            break;
        case 1:
            branch_position[0] = side::RIGHT;
            break;
        default:
            branch_position[0] = side::NONE;
            break;
    }
}
