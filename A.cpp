#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "A.h"
int WIDTH = 720;
int HEIGHT = 720;
int TAILLE = HEIGHT/4;


Window::Window() 
{

	if (0 != SDL_Init(SDL_INIT_VIDEO))
	{
		fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
	}

	Window::fenetre = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	if (Window::fenetre == NULL)
	{
		fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
	}

	Window::renderer = SDL_CreateRenderer(Window::fenetre, -1, 0);

	if (Window::renderer == NULL)//gestion des erreurs
	{
		fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
	}
}

Window::~Window() {
	SDL_DestroyWindow(Window::fenetre);
	SDL_DestroyRenderer(Window::renderer);
}


SDL_Renderer* Window::GetRenderer()
{
	return  Window::renderer;
}

SDL_Window* Window::GetWindow()
{
	return  Window::fenetre;
}

GameObject::GameObject(int x, int y, int w, int h) {
	cases = { x, y, w, h };
}

void GameObject::Draw(SDL_Renderer* renderer, SDL_Window* fenetre, SDL_Rect cases)
{
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
					SDL_SetWindowFullscreen(fenetre, SDL_WINDOW_FULLSCREEN_DESKTOP);
					break;
				case SDLK_ESCAPE:
					SDL_SetWindowFullscreen(fenetre, 0);
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
		SDL_SetRenderDrawColor(renderer, 80, 80, 80, 0);

		SDL_RenderClear(renderer);


		SDL_Rect cases[16];


		cases[0].x = cases[0].y = 0;
		cases[0].w = cases[0].h = TAILLE;

		for (int i = 1; i != 16; i++)
		{
			cases[i].x = cases[i - 1].x + TAILLE;
			cases[i].y = cases[i - 1].y;

			if (i % 4 == 0) //retour à la ligne
			{
				cases[i].x = 0;
				cases[i].y = cases[i - 1].y + TAILLE;
			}
			cases[i].w = cases[i].h = TAILLE; //taille d'une case : 100 x 100
		}



		//DRAW

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

		SDL_RenderDrawRects(renderer, cases, 16);


		SDL_RenderPresent(renderer);


	}

}