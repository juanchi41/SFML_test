#include "Window.h"

Window::Window()
{
	Setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string& l_title, const sf::Vector2u& l_size)
{
	Setup(l_title, l_size);
}

void Window::Update()
{
	while (std::optional<sf::Event> event = m_window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			m_isDone = true;
		}
		else if (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::F5)
		{
			ToggleFullscreen();
		}
	}
}

void Window::ToggleFullscreen()
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size)
{
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isFullscreen = false;
	m_isDone = false;
	Create();
}

void Window::Create()
{
	sf::State state = (m_isFullscreen ? sf::State::Fullscreen : sf::State::Windowed);
	sf::VideoMode mode;

	mode.size = { m_windowSize.x, m_windowSize.y };
	mode.bitsPerPixel = 32;
	m_window.reset(new sf::RenderWindow(mode, m_windowTitle, state));
}

