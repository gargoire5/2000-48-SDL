#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "A.h"
int WIDTH = 1080;
int HEIGHT = 720;

Window::Window() {  
}

    void Window::window() {
        SDL_Window* window = NULL;

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


        SDL_Event events;
        bool isOpen{ true };
        while (isOpen)
        {
            while (SDL_PollEvent(&events))
            {
                switch (events.type)
                {
                case SDL_KEYDOWN:
                    switch (events.key.keysym.sym) {
                    case SDLK_f:
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                        break;
                    case SDLK_ESCAPE:
                        SDL_SetWindowFullscreen(window, 0);
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
