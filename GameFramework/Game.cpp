#include "Game.h"
#include <iostream>

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

	return true;
}

void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer); // draw color로 render 지우기
	SDL_RenderPresent(m_pRenderer); // 화면 제시하기
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}
