#include "SFML/Window/Event.hpp"
#include "CCanvas.h"

CCanvas::CCanvas(const unsigned int width, const unsigned int height, const sf::Color backgroundColor)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	m_canvas = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height), "Canvas", sf::Style::Close, settings);
	m_canvas->setFramerateLimit(60);
	m_backgroundColor = backgroundColor;
}

void CCanvas::DrawShapes(const std::vector<std::shared_ptr<IShape>>& shapes) const
{
	while (m_canvas->isOpen())
	{
		sf::Event event{};
		while (m_canvas->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_canvas->close();
		}

		m_canvas->clear(m_backgroundColor);
		for (const auto& shape : shapes)
		{
			m_canvas->draw(*shape->GetShapeInstance());
		}
		m_canvas->display();
	}
}
