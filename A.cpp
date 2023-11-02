#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "A.h"
int WIDTH = 720;
int HEIGHT = 720;
int TAILLE = HEIGHT / 4;


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

void Window::Update()
{
	SDL_RenderPresent(Window::GetRenderer());
}

void Window::Clear()
{
	SDL_SetRenderDrawColor(Window::GetRenderer(), 80, 80, 80, 0);

	SDL_RenderClear(Window::GetRenderer());
}

GameObject::GameObject(int x, int y, int w, int h) {
	cases = { x, y, w, h };
}

void GameObject::Grille(SDL_Renderer* renderer) //crée la grille de jeu
{
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

	SDL_RenderDrawRects(renderer, cases, 16);
}


void GameObject::Image(SDL_Renderer* renderer, SDL_Window* fenetre)
{
	SDL_Surface* pSurface = SDL_LoadBMP("IMG/2.bmp");
	if (pSurface == NULL)
	{
		std::cout << "Error SDL_LoadBMP :" << SDL_GetError();
		exit(1);
	}

	//On crée une Texture (SDL_Texture) à partir de notre Image (SDL_Surface)
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(renderer, pSurface);
	if (pTexture == NULL)
	{
		std::cout << "Error SDL_CreateTextureFromSurface :" << SDL_GetError();
		exit(1);
	}

	//On libère l'Image (SDL_Surface) car on utilise que la Texture (SDL_Texture) pour dessiner
	SDL_FreeSurface(pSurface);


	SDL_Rect oPosition; 
	oPosition.x = 0; 
	oPosition.y = 0; 
	//On récupérer la taille de la Texture (SDL_Texture) 
	SDL_QueryTexture(pTexture, NULL, NULL, &oPosition.w, &oPosition.h); 

	//On dessine la Texture (SDL_Texture) sur le Canvas (Renderer) en position 0,0 (SDL_Rect)
	SDL_RenderCopy(renderer, pTexture, NULL, &oPosition); 

	SDL_RenderPresent(renderer); 

}