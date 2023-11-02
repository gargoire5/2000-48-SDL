#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "A.h"
int WIDTH = 720;
int HEIGHT = 720;
int TAILLE = HEIGHT / 4;

Window::Window() {
}

void Window::window() {

        if (0 != SDL_Init(SDL_INIT_VIDEO))
        {
            fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        }
        window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
        if (NULL == window)
        {
            fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        }

    renderer = SDL_CreateRenderer(Window::fenetre, -1, 0);

    if (renderer == NULL)//gestion des erreurs
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
    }



    SDL_DestroyWindow(fenetre);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();


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

void GameObject::Draw(SDL_Renderer* renderer, SDL_Window* fenetre)
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
                }
                break;
            case SDL_QUIT:
                isOpen = false;
                break;

                }
            }
        }

        SDL_Quit();
    }
