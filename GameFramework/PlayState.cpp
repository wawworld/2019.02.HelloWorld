#include "Game.h"
#include <iostream>

const std::string PlayState::s_playID = "PLAY";
void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(
			new	PauseState());
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

}

bool PlayState::onEnter()
{
	std::cout << "entering PlayState\n";
	if (!TheTextureManager::Instance()->load(
		"assets/helicopter.png", "helicopter",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}


	GameObject* player = new Player(
		new LoaderParams(100, 100, 128, 55, "helicopter"));
	m_gameObjects.push_back(player);
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	return true;
}
