#pragma once
#include "SFML/Graphics.hpp"
#include "IShapeVisitor.h"
#include <memory>

class IShape
{
public:
	virtual ~IShape() = default;

	virtual float GetPerimeter() const = 0;
	virtual float GetSquare() const = 0;
	virtual std::shared_ptr<sf::Shape> GetShapeInstance() const = 0;
	virtual sf::Color GetFillColor() const = 0;
	virtual void Accept(IShapeVisitor& visitor) const = 0;
};
