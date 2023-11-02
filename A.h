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


	void Grille(SDL_Renderer* renderer); //affiche la grille
	void Image(SDL_Renderer* renderer, SDL_Window* fenetre); //affiche une image

};