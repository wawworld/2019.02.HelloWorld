#pragma once

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	bool isKeyDown(SDL_Scancode key);
	void update();
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear 
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
	const Uint8* m_keystates;

};


typedef InputHandler TheInputHandler;