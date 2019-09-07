#pragma once
#include <string>
#include"GameState.h"


class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }
private:
	static const std::string s_menuID;

	static void s_menuToPlay();
	static void s_exitFromMenu();
};
