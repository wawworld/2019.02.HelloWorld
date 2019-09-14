#include "Game.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed) : SDLGameObject(pParams), m_animSpeed(animSpeed)
{
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() /
		(1000 / m_animSpeed)) % m_numFrames));
}
