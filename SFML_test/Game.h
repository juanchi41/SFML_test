#pragma once

#include "Window.h"
#include "World.h"
#include "Snake.h"

class Game {
public:
	Game();
	~Game() = default;
	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow() { return &m_window; }

private:
	sf::Clock m_clock;
	float m_elapsed;
	Window m_window;
	World m_world;
	Snake m_snake;
};
