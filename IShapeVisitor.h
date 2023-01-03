#pragma once
class CCircleDecorator;
class CTriangleDecorator;
class CRectangleDecorator;

class IShapeVisitor
{
public:
	virtual ~IShapeVisitor() = default;

	virtual void Visit(CCircleDecorator const& shape) = 0;
	virtual void Visit(CRectangleDecorator const& shape) = 0;
	virtual void Visit(CTriangleDecorator const& shape) = 0;
};
