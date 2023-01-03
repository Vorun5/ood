#pragma once
#include <memory>
#include "IShape.h"

class IShapeCreator
{
public:
	virtual ~IShapeCreator() = default;

	virtual std::shared_ptr<IShape> FactoryMethod(std::string&) const = 0;
};
