#pragma once
#include "IShape.h"

class CCircleDecorator final : public IShape
{
public:
	CCircleDecorator(std::shared_ptr<sf::CircleShape>);
	~CCircleDecorator() override = default;

	float GetRadius() const;
	sf::Vector2f GetCenter() const;
	static  std::shared_ptr<sf::CircleShape> CreateCircleShape(float radius, sf::Vector2f center, sf::Color color);

	// IShape
	float GetPerimeter() const override;
	float GetSquare() const override;
	std::shared_ptr<sf::Shape> GetShapeInstance() const override;
	sf::Color GetFillColor() const override;
	void Accept(IShapeVisitor& visitor) const override;

private:
	std::shared_ptr<sf::CircleShape> m_shape;
};
