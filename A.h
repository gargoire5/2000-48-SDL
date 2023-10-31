class Window {
public:
	SDL_Window* fenetre = NULL;
	SDL_Renderer* renderer = NULL;

	Window();

	SDL_Renderer* GetRenderer();
	SDL_Window* GetWindow();

	void window();
};

class GameObject {

	SDL_Rect cases;

public:

	GameObject(int x, int y, int w, int h);

	void Draw(SDL_Renderer* renderer, SDL_Window* fenetre);

};