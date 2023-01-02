#pragma once
#include "IShapeDecorator.h"

class CRectangleDecorator : public IShapeDecorator
{
public:
	CRectangleDecorator(/*std::shared_ptr<sf::CircleShape> shape*/const float y1, const float x1, const float y2, const float x2);


	~CRectangleDecorator() override = default;

	std::string ToString() const override;
	std::shared_ptr<sf::Shape> GetShapeInstance() const override;


protected:
	float Perimeter() const override;
	float Square() const override;


private:
	std::shared_ptr<sf::RectangleShape> m_shape;
};
