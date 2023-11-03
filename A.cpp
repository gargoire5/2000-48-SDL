#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
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


void GameObject::AddImage(SDL_Renderer* renderer, SDL_Rect rect) {
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;



	rect.x = cases.x;
	rect.y = cases.y;





	for (int i = 0; i <= 15; i++)
	{
		icases[i] = 0;

	}
	icases[5] = 2;

	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			if (icases[(GameObject::deuxto1D(col, row))] == 0)
			{
				surface = SDL_LoadBMP("IMG/0.bmp");
				texture = SDL_CreateTextureFromSurface(renderer, surface);

				//On r�cup�rer la taille de la Texture (SDL_Texture) 
				SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);


				//On dessine la Texture (SDL_Texture) sur le Canvas (Renderer) 
				SDL_RenderCopy(renderer, texture, NULL, &rect);

			}
			else if (icases[(GameObject::deuxto1D(col, row))] == 2)
			{
				surface = SDL_LoadBMP("IMG/2.bmp");
				texture = SDL_CreateTextureFromSurface(renderer, surface);
				//On r�cup�rer la taille de la Texture (SDL_Texture) 
				SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);



				//On dessine la Texture (SDL_Texture) sur le Canvas (Renderer) 
				SDL_RenderCopy(renderer, texture, NULL, &rect);

			}
			else if (icases[(GameObject::deuxto1D(col, row))] == 4)
			{
				surface = SDL_LoadBMP("IMG/4.bmp");
				texture = SDL_CreateTextureFromSurface(renderer, surface);

				//On r�cup�rer la taille de la Texture (SDL_Texture) 
				SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);



				//On dessine la Texture (SDL_Texture) sur le Canvas (Renderer) 
				SDL_RenderCopy(renderer, texture, NULL, &rect);
			}
			else if (icases[(GameObject::deuxto1D(col, row))] == 8)
			{
				surface = SDL_LoadBMP("IMG/8.bmp");
				texture = SDL_CreateTextureFromSurface(renderer, surface);

				//On r�cup�rer la taille de la Texture (SDL_Texture) 
				SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);



				//On dessine la Texture (SDL_Texture) sur le Canvas (Renderer) 
				SDL_RenderCopy(renderer, texture, NULL, &rect);
			}
			else if (icases[(GameObject::deuxto1D(col, row))] == 16)
			{
				surface = SDL_LoadBMP("IMG/16.bmp");
				texture = SDL_CreateTextureFromSurface(renderer, surface);

				//On r�cup�rer la taille de la Texture (SDL_Texture) 
				SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);



				//On dessine la Texture (SDL_Texture) sur le Canvas (Renderer) 
				SDL_RenderCopy(renderer, texture, NULL, &rect);
			}
			else if (icases[(GameObject::deuxto1D(col, row))] == 32)
			{
				surface = SDL_LoadBMP("IMG/32.bmp");
				texture = SDL_CreateTextureFromSurface(renderer, surface);

				//On r�cup�rer la taille de la Texture (SDL_Texture) 
				SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);



				//On dessine la Texture (SDL_Texture) sur le Canvas (Renderer) 
				SDL_RenderCopy(renderer, texture, NULL, &rect);
			}
			else if (icases[(GameObject::deuxto1D(col, row))] == 64)
			{
				surface = SDL_LoadBMP("IMG/64.bmp");
				texture = SDL_CreateTextureFromSurface(renderer, surface);

				//On r�cup�rer la taille de la Texture (SDL_Texture) 
				SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);



				//On dessine la Texture (SDL_Texture) sur le Canvas (Renderer) 
				SDL_RenderCopy(renderer, texture, NULL, &rect);
			}
			else if (icases[(GameObject::deuxto1D(col, row))] == 128)
			{
				surface = SDL_LoadBMP("IMG/128.bmp");
				texture = SDL_CreateTextureFromSurface(renderer, surface);

				//On r�cup�rer la taille de la Texture (SDL_Texture) 
				SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);



				//On dessine la Texture (SDL_Texture) sur le Canvas (Renderer) 
				SDL_RenderCopy(renderer, texture, NULL, &rect);
			}
		}
	}

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);

}



GameObject::GameObject(int x, int y, int w, int h) {
	cases = { x, y, w, h };
}

GameObject::~GameObject()
{

}


void GameObject::Grille(SDL_Renderer* renderer) //cr�e la grille de jeu
{

	SDL_Rect cases[16];

	cases[0].x = cases[0].y = 0;
	cases[0].w = cases[0].h = TAILLE;

	for (int i = 1; i != 16; i++)
	{
		cases[i].x = cases[i - 1].x + TAILLE;
		cases[i].y = cases[i - 1].y;

		if (i % 4 == 0) //retour � la ligne
		{
			cases[i].x = 0;
			cases[i].y = cases[i - 1].y + TAILLE;
		}
		cases[i].w = cases[i].h = TAILLE;
	}

	SDL_RenderDrawRects(renderer, cases, 16);

}

int GameObject::unto2D(int case1D) //recupere la coordon�e d'une case a 1 dimension et renvoie la meme case sur 2 dimension
{
	int x = 0;
	int y = 0;

	if (case1D == 4 || case1D == 5 || case1D == 6 || case1D == 7)
	{
		x = 1;
	}
	else if (case1D == 8 || case1D == 9 || case1D == 10 || case1D == 11)
	{
		x = 2;
	}
	else if (case1D == 12 || case1D == 13 || case1D == 14 || case1D == 15)
	{
		x = 3;
	}
	if (case1D == 1 || case1D == 5 || case1D == 9 || case1D == 13)
	{
		y = 1;
	}
	else if (case1D == 2 || case1D == 6 || case1D == 10 || case1D == 14)
	{
		y = 2;
	}
	else if (case1D == 3 || case1D == 7 || case1D == 11 || case1D == 15)
	{
		y = 3;
	}

	return x, y;
}

int GameObject::deuxto1D(int x, int y) //recupere la coordon�e d'une case a 2 dimension et renvoie la meme case sur 1 dimension    I * long + J
{
	return x * 4 + y;
}


void GameObject::AddRandomTile() {
	// Recherchez toutes les positions vides dans la grille
	std::vector<std::pair<int, int>> emptyCells;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (icases[GameObject::deuxto1D(i, j)] == 0) {
				emptyCells.push_back(std::make_pair(i, j));
			}
		}
	}

	// Si aucune case vide n'est trouv�e, ne fais rien
	if (emptyCells.empty()) {
		return;
	}

	// Choisissez une position vide al�atoire
	srand(static_cast<unsigned int>(time(nullptr)));
	int randomIndex = rand() % emptyCells.size();
	int value;
	int valeur = (rand() % 100 + 1);
	if (valeur < 80)  // G�n�re 2 (80%) ou 4 (20%)
	{
		value = 2;

	}
	else
	{
		value = 4;
	}

	int row = emptyCells[randomIndex].first;
	int col = emptyCells[randomIndex].second;
	icases[GameObject::deuxto1D(row, col)] = value;
}

