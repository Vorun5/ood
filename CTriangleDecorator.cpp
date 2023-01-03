#include "CTriangleDecorator.h"

CTriangleDecorator::CTriangleDecorator(const sf::Vector2f p1, const sf::Vector2f p2, const sf::Vector2f p3, const sf::Color color)
{
	const auto a = GetDistance(p1, p2);
	const auto b = GetDistance(p1, p3);
	const auto c = GetDistance(p2, p3);
	if (!(a < b + c && b < a + c && c < a + b))
	{
		throw std::logic_error("triangle: the sum of any two sides of a triangle must be greater than the third side");
	}

	sf::ConvexShape shape;
	shape.setPointCount(3);
	shape.setPoint(0, p1);
	shape.setPoint(1, p2);
	shape.setPoint(2, p3);
	shape.setFillColor(color);

	m_shape = std::make_shared<sf::ConvexShape>(shape);
}

float CTriangleDecorator::side1() const
{
	return this->GetDistance(m_shape->getPoint(0), m_shape->getPoint(1));
}

float CTriangleDecorator::side2() const
{
	return this->GetDistance(m_shape->getPoint(0), m_shape->getPoint(2));
}

float CTriangleDecorator::side3() const
{
	return this->GetDistance(m_shape->getPoint(1), m_shape->getPoint(2));
}

std::shared_ptr<sf::Shape> CTriangleDecorator::GetShapeInstance() const
{
	return m_shape;
}

sf::Color CTriangleDecorator::GetFillColor() const
{
	return m_shape->getFillColor();
}

void CTriangleDecorator::Accept(IShapeVisitor& visitor) const
{
	visitor.Visit(*this);
}

float CTriangleDecorator::GetPerimeter() const
{
	return side1() + side2() + side3();
}

float CTriangleDecorator::GetSquare() const
{
	const float d = this->GetPerimeter() / 2;
	return std::sqrt(d * (d - side1()) * (d - side2()) * (d - side3()));
}

float CTriangleDecorator::GetDistance(const sf::Vector2f p1, const sf::Vector2f p2) const
{
	return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
