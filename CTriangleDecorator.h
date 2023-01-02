#pragma once
#include "IShapeDecorator.h"

class CTriangleDecorator : public IShapeDecorator
{
public:
	CTriangleDecorator(/*std::shared_ptr<sf::CircleShape> shape*/ float y1, float x1, float y2, float x2, float y3, float x3);


	~CTriangleDecorator() override = default;

	std::string ToString() const override;
	std::shared_ptr<sf::Shape> GetShapeInstance() const override;


protected:
	float Perimeter() const override;
	float Square() const override;


private:
	std::shared_ptr<sf::ConvexShape> m_shape;
};
