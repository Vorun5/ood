#pragma once
#include <ostream>
#include "IShapeVisitor.h"

class CShapePrinter final : public IShapeVisitor
{
public:
	CShapePrinter(std::ostream& out);
	~CShapePrinter() override = default;

	// IShapeVisitor
	void Visit(CCircleDecorator const& shape) override;
	void Visit(CRectangleDecorator const& shape) override;
	void Visit(CTriangleDecorator const& shape) override;

private:
	std::ostream& m_out;
};
