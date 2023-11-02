#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "A.h"

int main(int argc, char* argv[])
{
    std::cout << " main";
    Window w;
    std::cout << " demain";

    w.window();

    std::cout << " main";

    GameObject go(50, 50, 10, 10);
    std::cout << " go";
    go.Draw(w.GetRenderer(),w.GetWindow());
    std::cout << "changement";

    
    
    return 0;
}