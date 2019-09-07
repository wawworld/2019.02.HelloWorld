#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"

#include <iostream>

TextureManager*		TextureManager::s_pInstance = 0;
Game*				Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);  // chpark m_pWindow, fullscreen
		if (m_pWindow != 0) // chpark m_pWindow
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0); // chpark 
		}
	}
	else {
		return false; // sdl could not initialize
	}

	m_bRunning = true; // chpark 


	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
		"animate", m_pRenderer))
	{
		return false;
	}

	//m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	//m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());

	return true;
}


void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	m_pGameStateMachine->update();
}

//
//void Game::render()
//{
//	SDL_RenderClear(m_pRenderer); // draw colour·Î Áö¿ò
//	for (std::vector<GameObject*>::size_type i = 0;
//		i != m_gameObjects.size(); i++)
//	{
//		m_gameObjects[i]->draw();
//	}
//	SDL_RenderPresent(m_pRenderer); // draw to the screen
//}
//
//void Game::update()
//{
//	for (std::vector<GameObject*>::size_type i = 0;
//		i != m_gameObjects.size(); i++)
//	{
//		m_gameObjects[i]->update();
//	}
//}

void Game::clean()
{
	TheInputHandler::Instance()->clean();

	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

//void Game::handleEvents()
//{
//	SDL_Event event;
//	if (SDL_PollEvent(&event))
//	{
//		switch (event.type)
//		{
//		case SDL_QUIT:
//			m_bRunning = false;
//			break;
//		default:
//			break;
//		}
//	}
//}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}
