#pragma once
#include "IShape.h"

class CRectangleDecorator : public IShape
{
public:
	CRectangleDecorator(sf::Vector2f p1, sf::Vector2f p2, sf::Color color);
	~CRectangleDecorator() override = default;

	float GetWidth() const;
	float GetHeight() const;

	// IShape
	float GetPerimeter() const override;
	float GetSquare() const override;
	std::shared_ptr<sf::Shape> GetShapeInstance() const override;
	sf::Color GetFillColor() const override;
	void Accept(IShapeVisitor& visitor) const override;

private:
	std::shared_ptr<sf::RectangleShape> m_shape;
};
