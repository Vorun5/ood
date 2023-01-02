#include "CRectangleDecorator.h"


CRectangleDecorator::CRectangleDecorator(const float y1, const float x1, const float y2, const float x2)
{
	sf::RectangleShape shape;
	shape.setPosition(sf::Vector2(y1, x1));
	shape.setSize(sf::Vector2f(x2 - x1, y2 - y1));
	shape.setFillColor(sf::Color(255, 92, 3));

	m_shape = std::make_shared<sf::RectangleShape>(shape);
}

std::string CRectangleDecorator::ToString() const
{
	return "CRectangleDecorator ToString";
}

std::shared_ptr<sf::Shape> CRectangleDecorator::GetShapeInstance() const
{
	return m_shape;
}

float CRectangleDecorator::Perimeter() const
{
	return 0.0f;
}

float CRectangleDecorator::Square() const
{
	return 0.0f;
}
