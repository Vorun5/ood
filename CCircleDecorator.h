#pragma once
#include "IShapeDecorator.h"

class CCircleDecorator : public IShapeDecorator
{
public:
	CCircleDecorator(/*std::shared_ptr<sf::CircleShape> shape*/float radius, float y, float x);
	

	~CCircleDecorator() override = default;

	std::string ToString() const override;
	std::shared_ptr<sf::Shape> GetShapeInstance() const override;


protected:
	float Perimeter() const override;
	float Square() const override;


private:
	std::shared_ptr<sf::CircleShape> m_shape;
};

