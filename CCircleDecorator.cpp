#include "CCircleDecorator.h"

CCircleDecorator::CCircleDecorator(const float radius, const float y, const float x)
{
	sf::CircleShape shape(radius);
	shape.setPosition(y, x);
	shape.setFillColor(sf::Color(143, 0, 255));

	m_shape = std::make_shared<sf::CircleShape>(shape);
}

std::string CCircleDecorator::ToString() const
{
	return "CCircleDecorator ToString";
}

std::shared_ptr<sf::Shape> CCircleDecorator::GetShapeInstance() const
{
	return m_shape;
}


float CCircleDecorator::Perimeter() const
{
	return 0.0f;
}

float CCircleDecorator::Square() const
{
	return 0.0f;
}
