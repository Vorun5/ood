#pragma once
#include "SFML/Graphics.hpp"
#include <memory>
#include <string>


class IShapeDecorator
{
public:
	virtual ~IShapeDecorator() = default;

	virtual std::string ToString() const = 0;
	virtual std::shared_ptr<sf::Shape> GetShapeInstance() const = 0;


protected:
	virtual float Perimeter() const = 0;
	virtual float Square() const = 0;
};
