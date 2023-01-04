#pragma once
#include "IShape.h"

class CTriangleDecorator final : public IShape
{
public:
	CTriangleDecorator(std::shared_ptr<sf::ConvexShape>);
	~CTriangleDecorator() override = default;

	float side1() const;
	float side2() const;
	float side3() const;
	static std::shared_ptr<sf::ConvexShape> CreateConvexShape(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color color);

	// IShape
	float GetPerimeter() const override;
	float GetSquare() const override;
	std::shared_ptr<sf::Shape> GetShapeInstance() const override;
	sf::Color GetFillColor() const override;
	void Accept(IShapeVisitor& visitor) const override;

private:
	std::shared_ptr<sf::ConvexShape> m_shape;
	static float GetDistance(sf::Vector2f p1, sf::Vector2f p2);
};
