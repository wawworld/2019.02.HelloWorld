#pragma once
#include "GameState.h"

class GameObject;
class PauseState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }
	static PauseState* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new PauseState();
		}
		return s_pInstance;
	}
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;
	// std::vector<GameObject*> m_gameObjects;

	PauseState() {}
	static PauseState* s_pInstance;
};
