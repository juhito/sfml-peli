#include <iostream>
#include "engine.h"

/*

  Made by : Jussi Perälä (www.github.com/juhito)

  Clone of the steam game named Timberman.

  Become a Timberman, chop wood and avoid the branches. Sounds like an
  easy task? It's easy to play but hard to master.

  ALL ASSETS USED IN THIS GAME ARE FROM THE INTERWEB
  
*/

int main(void) {

    engine game;

    if(!game.init()) {
        std::cout << "Something went wrong..\n";
    }
    else {
        while(game.window.isOpen()) {
            game.dt = game.clock.restart();
           
            if(!game.event_poll()){
                std::cout << "Thanks for playing!\n";
            }
            
            game.draw();
        }
    }

    return(0);
}
