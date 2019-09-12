#include "Game.h"

//void GameStateMachine::pushState(GameState *pState)
//{
//	m_gameStates.push_back(pState);
//	m_gameStates.back()->onEnter();
//}

void GameStateMachine::popState()
{
	//if (!m_gameStates.empty()) {
	//	if (m_gameStates.back()->onExit()) {
	//		delete m_gameStates.back();
	//		m_gameStates.pop_back();
	//	}
	//}
	changeState(m_prevState);
}

void GameStateMachine::changeState(GameState *pState)
{
	//if (!m_gameStates.empty())
	//{
	//	if (m_gameStates.back()->getStateID() == pState->getStateID()) {
	//		return; // do nothing
	//	}
	//	if (m_gameStates.back()->onExit()) {
	//		delete m_gameStates.back();
	//		m_gameStates.pop_back();
	//	}
	//}
	//m_gameStates.push_back(pState);  // push back our new state
	//m_gameStates.back()->onEnter();   // initialise it
	if (pState != NULL)
	{
		if (m_currentState != NULL) {
			m_prevState = m_currentState;
			m_currentState->onExit();
		}
		m_currentState = pState;
		m_currentState->onEnter();
	}
}


void GameStateMachine::update()
{
	//if (!m_gameStates.empty())
	//{
	//	m_gameStates.back()->update();
	//}
	if (m_currentState != NULL)
		m_currentState->update();
}

void GameStateMachine::render()
{
	/*if (!m_gameStates.empty())
	{
		m_gameStates.back()->render();
	}*/
	if (m_currentState != NULL)
		m_currentState->render();
}
