#define _USE_MATH_DEFINES
#include "CCircleDecorator.h"

CCircleDecorator::CCircleDecorator(const float radius, const sf::Vector2f center, const sf::Color color)
{
	if (!(radius > 0))
	{
		throw std::logic_error("circle: radius cannot be negative or zero");
	}
	sf::CircleShape shape(radius);
	shape.setPosition(center.x, center.y);
	shape.setFillColor(color);

	m_shape = std::make_shared<sf::CircleShape>(shape);
}

float CCircleDecorator::GetRadius() const
{
	return m_shape->getRadius();
}

sf::Vector2f CCircleDecorator::GetCenter() const
{
	auto position = m_shape->getPosition();
	const auto radius = this->GetRadius();
	position.x += radius / 2;
	position.y += radius / 2;

	return position;
}

std::shared_ptr<sf::Shape> CCircleDecorator::GetShapeInstance() const
{
	return m_shape;
}

sf::Color CCircleDecorator::GetFillColor() const
{
	return m_shape->getFillColor();
}

void CCircleDecorator::Accept(IShapeVisitor& visitor) const
{
	visitor.Visit(*this);
}

float CCircleDecorator::GetPerimeter() const
{
	return this->GetRadius() * 2.0f * M_PI;
}

float CCircleDecorator::GetSquare() const
{
	return std::pow(this->GetRadius(), 2) * M_PI;
}
