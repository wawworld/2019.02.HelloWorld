#pragma once
#include <vector>
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update(); // chpark
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	// Ãß°¡
	std::vector<GameObject*> m_gameObjects;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
};
