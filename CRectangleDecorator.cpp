#include "CRectangleDecorator.h"

CRectangleDecorator::CRectangleDecorator(const sf::Vector2f p1, const sf::Vector2f p2, const sf::Color color)
{
	if (p1.x == p2.x && p1.y == p2.y)
	{
		throw std::logic_error("rectangle: top-left and bottom-right coordinates cannot be the same");
	}
	sf::RectangleShape shape;
	if (p1.x > p2.x) 
	{
		shape.setPosition(p2);
		shape.setSize(sf::Vector2f(p1.x - p2.x, p1.y - p2.y));
	}
	else 
	{
		shape.setPosition(p1);
		shape.setSize(sf::Vector2f(p2.x - p1.x, p2.y - p1.y));
	}
	shape.setFillColor(color);

	m_shape = std::make_shared<sf::RectangleShape>(shape);
}

float CRectangleDecorator::GetWidth() const
{
	return m_shape->getSize().x;
}

float CRectangleDecorator::GetHeight() const
{
	return m_shape->getSize().y;
}

std::shared_ptr<sf::Shape> CRectangleDecorator::GetShapeInstance() const
{
	return m_shape;
}

sf::Color CRectangleDecorator::GetFillColor() const
{
	return m_shape->getFillColor();
}

void CRectangleDecorator::Accept(IShapeVisitor& visitor) const
{
	visitor.Visit(*this);
}

float CRectangleDecorator::GetPerimeter() const
{
	return 2 * std::abs(this->GetHeight()) + 2 * std::abs(this->GetWidth());
}

float CRectangleDecorator::GetSquare() const
{
	return std::abs(this->GetHeight()) * std::abs(this->GetWidth());
}
