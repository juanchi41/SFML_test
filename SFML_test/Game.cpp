#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game() : m_window("Snake", sf::Vector2u(800, 600)), m_world(sf::Vector2u(800, 600)), m_snake(m_world.GetBlockSize()), m_elapsed(0.0)
{
	m_clock.start();
}

void Game::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && m_snake.GetDirection() != Direction::Down)
	{
		m_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && m_snake.GetDirection() != Direction::Up)
	{
		m_snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && m_snake.GetDirection() != Direction::Right)
	{
		m_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && m_snake.GetDirection() != Direction::Left)
	{
		m_snake.SetDirection(Direction::Right);
	}
}

void Game::Update()
{
	float timestep = 1.0f / m_snake.GetSpeed();
	float elapsed = m_clock.getElapsedTime().asSeconds();

	if (m_elapsed + timestep <= elapsed)
	{
		m_snake.Tick();
		m_world.Update(m_snake);
		m_elapsed = elapsed;
		if (m_snake.HasLost())
		{
			m_snake.Reset();
		}
	}

	m_window.Update();
}

void Game::Render()
{
	m_window.BeginDraw();
	// Render here.
	m_world.Render(m_window.GetRenderWindow());
	m_snake.Render(m_window.GetRenderWindow());
	m_window.EndDraw();
}
