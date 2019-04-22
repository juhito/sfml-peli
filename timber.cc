#include "headers/game.h"

/*

  Made by : Jussi Perälä (www.github.com/juhito)

  Clone of the steam game named Timberman.

  Become a Timberman, chop wood and avoid the branches. Sounds like an
  easy task? It's easy to play but hard to master.
  
*/

int main(void) {

    Game game;

    while(!game.get_window()->is_done()) {
        game.handle_events();
        game.update();
        game.render();
        game.restart_clock();
    }
    return(0);
}
