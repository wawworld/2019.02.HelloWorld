#pragma once
#include <iostream>
#include "GameObject.h"
#include "Vector2D.h"

class LoaderParams;
class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update()=0;
	virtual void clean() {};

	Vector2D getPosition() const { return m_position; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }

protected:

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	int m_width;
	int m_height;

	int m_numFrames;
	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;
};
