#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "A.h"

int main(int argc, char* argv[])
{
	Window w;

	GameObject go(0, 0, 10, 10);

	GameObject go2(180, 0, 10, 10);

	GameObject go3(360, 0, 10, 10);

	GameObject go4(540, 0, 10, 10);

	GameObject go5(0, 180, 10, 10);

	GameObject go6(180, 180, 10, 10);

	GameObject go7(360, 180, 10, 10);

	GameObject go8(540, 180, 10, 10);

	GameObject go9(0, 360, 10, 10);

	GameObject go10(180, 360, 10, 10);

	GameObject go11(360, 360, 10, 10);

	GameObject go12(540, 360, 10, 10);

	GameObject go13(0, 540, 10, 10);

	GameObject go14(180, 540, 10, 10);

	GameObject go15(360, 540, 10, 10);

	GameObject go16(540, 540, 10, 10);


    SDL_Event events;
    bool isOpen = true ;
	bool isAction = false;
    while (isOpen)
    {
		//EVENT
		while (SDL_PollEvent(&events))
		{
			isAction = false;
			switch (events.type)
			{
			case SDL_QUIT:
				isOpen = false;
				break;

			case SDL_KEYUP:
				switch (events.key.keysym.sym)
				{
				case SDLK_f:
					SDL_SetWindowFullscreen(w.GetWindow(), SDL_WINDOW_FULLSCREEN_DESKTOP);
					break;
				case SDLK_ESCAPE:
					SDL_SetWindowFullscreen(w.GetWindow(), 0);
					break;
				case SDLK_a:
					isOpen = false;
					break;

				case SDLK_z:
					std::cout << "Z" << std::endl;
					isAction = true;
					go.MoveUp();
					break;

				case SDLK_q:
					std::cout << "Q" << std::endl;
					isAction = true;
					break;

				case SDLK_s:
					std::cout << "S" << std::endl;
					isAction = true;
					break;

				case SDLK_d:
					std::cout << "D" << std::endl;
					go.MoveRight();
					isAction = true;
					break;

				default:
					continue;
				}
			}
			go.AddRandomTile();

		}

		//UPDATE

		w.Clear();

		//DRAW
		 
		SDL_SetRenderDrawColor(w.GetRenderer(), 0, 0, 0, 0); 
		go.Grille(w.GetRenderer()); 
		go2.Grille(w.GetRenderer()); 
		go3.Grille(w.GetRenderer()); 
		go4.Grille(w.GetRenderer()); 
		go5.Grille(w.GetRenderer()); 
		go6.Grille(w.GetRenderer()); 
		go7.Grille(w.GetRenderer()); 
		go8.Grille(w.GetRenderer()); 
		go9.Grille(w.GetRenderer()); 
		go10.Grille(w.GetRenderer()); 
		go11.Grille(w.GetRenderer()); 
		go12.Grille(w.GetRenderer()); 
		go13.Grille(w.GetRenderer()); 
		go14.Grille(w.GetRenderer()); 
		go15.Grille(w.GetRenderer()); 
		go16.Grille(w.GetRenderer()); 



		go.AddImage(w.GetRenderer(), go.rect); 
		go2.AddImage(w.GetRenderer(), go2.rect); 
		go3.AddImage(w.GetRenderer(), go3.rect); 
		go4.AddImage(w.GetRenderer(), go4.rect); 
		go5.AddImage(w.GetRenderer(), go5.rect); 
		go6.AddImage(w.GetRenderer(), go6.rect); 
		go7.AddImage(w.GetRenderer(), go7.rect); 
		go8.AddImage(w.GetRenderer(), go8.rect); 
		go9.AddImage(w.GetRenderer(), go9.rect); 
		go10.AddImage(w.GetRenderer(), go10.rect); 
		go11.AddImage(w.GetRenderer(), go11.rect); 
		go12.AddImage(w.GetRenderer(), go12.rect); 
		go13.AddImage(w.GetRenderer(), go13.rect); 
		go14.AddImage(w.GetRenderer(), go14.rect); 
		go15.AddImage(w.GetRenderer(), go15.rect); 
		go16.AddImage(w.GetRenderer(), go16.rect);

		w.Update();
    }

    SDL_Quit();
    return 0;
}

