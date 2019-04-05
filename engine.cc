#include "engine.h"

engine::engine() {}

engine::~engine() {}

bool engine::init() {
    window.create(sf::VideoMode(900, 1600), "Timber");

    if(!window.isOpen()) {
        std::cout << "Couldn't create window\n";
        return(false);
    }
    else {
        window.setFramerateLimit(60);
        asset.init();
    }

    return(true);
}

bool engine::event_poll() {
    
    sf::Event event;
    while(window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                window.close();
                return(false);
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape) {
                    window.close();
                    return(false);
                }

                if(accept_input) {
                    if(event.key.code == sf::Keyboard::Right && !paused) {
                        score++;
                        asset.log_active = true;
                        asset.update_branches(score);
                        accept_input = false;
                    }
                }
                if(event.key.code == sf::Keyboard::Return && paused) {
                    paused = false;
                    accept_input = true;

                    for(int i = 0; i < 6; i++)
                        asset.branch_position[i] = side::NONE;
                    
                }
                
                break;
            case sf::Event::KeyReleased:
                if(!paused)
                    accept_input = true;
                break;
        }
    }
    return(true);
}

void engine::draw() {
    window.clear();
    // draw
    if(!paused)
        asset.update(dt);
    asset.draw(window);
    // update
    window.display();
}
