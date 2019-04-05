#if !defined(ENGINE_H)
#define ENGINE_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "assets.h"

class engine {
public:
    engine();
    ~engine();

    bool event_poll();
    void draw();
    bool init();
    void update();
    sf::RenderWindow window;
    
    sf::Time dt;
    sf::Clock clock;
    bool paused = true;
    bool accept_input = true;
private:
    int score = 0;
    assets asset;
};



#endif
