#pragma once
#include "IShape.h"
#include "SFML/Graphics/RenderWindow.hpp"

class CCanvas
{
public:
	CCanvas(unsigned int width, unsigned int height, sf::Color backgroundColor);
	~CCanvas() = default;

	void DrawShapes(const std::vector<std::shared_ptr<IShape>>& shapes) const;

private:
	std::shared_ptr<sf::RenderWindow> m_canvas;
	sf::Color m_backgroundColor;
};
