#include"Game.h"
#include <SDL3/SDL_main.h>
#include"tools.h"
int main(int argc, char* argv[]) {
    InitGame();
    CreateWindowAndRender();
    Shape::addPrototype(make_unique<Cycle>(0, 0));
    Shape::addPrototype(make_unique<Triangle>(0, 0));
    Game game;
    game.Run();
    TTF_Quit();
    SDL_Quit();
    return 0;
}


