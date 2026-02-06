#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Window
{
public:
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window() { Destroy(); }
	void BeginDraw() { m_window->clear(sf::Color::Black); } // Clear the window.
	void EndDraw() { m_window->display(); } // Display the changes.
	void Update();
	bool IsDone() const { return m_isDone; }
	bool IsFullscreen() const { return m_isFullscreen; }
	sf::Vector2u GetWindowSize() const { return m_windowSize; }
	void ToggleFullscreen();
	void Draw(sf::Drawable& l_drawable) { m_window->draw(l_drawable); }
	sf::RenderWindow& GetRenderWindow() { return *m_window.get(); }

private:
	void Setup(const std::string& l_title,
		const sf::Vector2u& l_size);
	void Destroy() { m_window->close(); }
	void Create();
	std::unique_ptr<sf::RenderWindow> m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
};
