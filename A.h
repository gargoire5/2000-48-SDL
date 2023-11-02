class Window {
public:

	SDL_Window* fenetre = NULL;
	SDL_Renderer* renderer = NULL;


	Window(); //Constructeur
	~Window(); //Destructeur

	SDL_Renderer* GetRenderer();
	SDL_Window* GetWindow();

	void Update();
	void Clear();
};

class GameObject {

public:

	SDL_Rect cases;

	GameObject(int x, int y, int w, int h); //Constructeur
	//~GameObject(); //Destructeur


	void Draw(SDL_Renderer* renderer);
	void Image(SDL_Renderer* renderer, SDL_Window* fenetre);

};