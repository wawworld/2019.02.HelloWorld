#include "Game.h"


void GameStateMachine::popState()
{
	changeState(m_prevState);
}

void GameStateMachine::changeState(GameState *pState)
{
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
	if (m_currentState != NULL)
		m_currentState->update();
}

void GameStateMachine::render()
{
	if (m_currentState != NULL)
		m_currentState->render();
}
