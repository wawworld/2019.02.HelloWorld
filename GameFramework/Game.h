#pragma once
#include <SDL.h>

#include "GameObject.h"
#include "SDLGameObject.h"

#include "TextureManager.h"
#include "InputHandler.h"

#include "LoaderParams.h"
#include "Vector2D.h"

#include "GameStateMachine.h"
#include "GameState.h"
#include "MenuState.h"
#include "PlayState.h"

#include "MenuButton.h"
#include "Player.h"
#include "Enemy.h"


class GameStateMachine;

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

	void quit() { m_bRunning = false;  }
	void  pushBack(GameObject* obj) { 
		//m_gameObjects.push_back(obj);
	}
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	GameStateMachine* m_pGameStateMachine;
	// Ãß°¡
	//std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;

