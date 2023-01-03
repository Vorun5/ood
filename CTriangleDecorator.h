#pragma once
#include "IShape.h"

class CTriangleDecorator final : public IShape
{
public:
	CTriangleDecorator(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color color);
	~CTriangleDecorator() override = default;

	float side1() const;
	float side2() const;
	float side3() const;

	// IShape
	float GetPerimeter() const override;
	float GetSquare() const override;
	std::shared_ptr<sf::Shape> GetShapeInstance() const override;
	sf::Color GetFillColor() const override;
	void Accept(IShapeVisitor& visitor) const override;

private:
	std::shared_ptr<sf::ConvexShape> m_shape;
	float GetDistance(sf::Vector2f p1, sf::Vector2f p2) const;
};
