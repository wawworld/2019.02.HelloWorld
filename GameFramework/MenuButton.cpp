#include "SDLGameObject.h"
#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}


void MenuButton::draw()
{
	SDLGameObject::draw(); // use the base class drawing
}


void MenuButton::clean()
{
	SDLGameObject::clean();
}