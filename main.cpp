#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "A.h"

int main(int argc, char* argv[])
{
    Window w;

    GameObject go(50, 50, 10, 10);

    go.Draw(w.GetRenderer(),w.GetWindow(), go.cases);
    

	SDL_Quit();
    return 0;
}

