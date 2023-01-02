#include "CTriangleDecorator.h"

CTriangleDecorator::CTriangleDecorator(const float y1, const float x1, const float y2, const float x2, const float y3, const float x3)
{
	sf::ConvexShape shape;
	shape.setPointCount(3);
	shape.setPoint(0, sf::Vector2(y1, x1));
	shape.setPoint(1, sf::Vector2(y2, x2));
	shape.setPoint(2, sf::Vector2(y3, x3));
	shape.setFillColor(sf::Color(76, 140, 255));

	m_shape = std::make_shared<sf::ConvexShape>(shape);
}

std::string CTriangleDecorator::ToString() const
{
	return "CTriangleDecorator ToString";
}

std::shared_ptr<sf::Shape> CTriangleDecorator::GetShapeInstance() const
{
	return m_shape;
}

float CTriangleDecorator::Perimeter() const
{
	return 0.0f;
}

float CTriangleDecorator::Square() const
{
	return 0.0f;
}
