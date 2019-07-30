#pragma once
#include "SDLGameObject.h"
#include "TextureManager.h"

#include <vector>
#include <SDL.h>

class Game
{
private:
	Game() {}
	static Game* s_pInstance;
	// create the typedef
public:

	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update(); // chpark
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	// Ãß°¡
	std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;

