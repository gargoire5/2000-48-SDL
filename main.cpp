#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "A.h"

int main(int argc, char* argv[])
{
    Window w;

    GameObject go(50, 50, 10, 10);


    SDL_Event events;
    bool isOpen{ true };
    while (isOpen)
    {
		
		//EVENT
		while (SDL_PollEvent(&events))
		{
			switch (events.type) 
			{
			case SDL_KEYDOWN: 
				switch (events.key.keysym.sym) { 
				case SDLK_f:
					SDL_SetWindowFullscreen(w.GetWindow(), SDL_WINDOW_FULLSCREEN_DESKTOP);
					break;
				case SDLK_ESCAPE: 
					SDL_SetWindowFullscreen(w.GetWindow(), 0);
					break;
				case SDLK_a: 
					isOpen = false; 
					break;
				}
				break;
			case SDL_QUIT: 
				isOpen = false; 
				break;

			}
		}

		//UPDATE

		w.Clear();

		//DRAW

		go.Draw(w.GetRenderer());
				

		SDL_SetRenderDrawColor(w.GetRenderer(), 0, 0, 0, 0);


		//go.Image(w.GetRenderer(), w.GetWindow());

		w.Update();

    }

    SDL_Quit();
    return 0;
}

