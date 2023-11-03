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
	SDL_Rect rect;

	int icases[16];


	GameObject(int x, int y, int w, int h); //Constructeur
	~GameObject(); //Destructeur


	void Grille(SDL_Renderer* renderer); //affiche la grille

	int unto2D(int case1D);
	int deuxto1D(int x, int y);
 
	void AddImage(SDL_Renderer* renderer, SDL_Rect rect);

	void AddRandomTile();

	void MoveUp();

	void MoveDown();

	void MoveLeft();

	void MoveRight();
};
