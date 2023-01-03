#include "CShapePrinter.h"
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"
#include "CColorUtil.h"
#include <iomanip>

CShapePrinter::CShapePrinter(std::ostream& out)
	: m_out(out)
{
}

void CShapePrinter::Visit(CCircleDecorator const& shape)
{
	m_out << "circle p=" << shape.GetPerimeter() << " s=" << shape.GetSquare() << std::setw(2) << " " << CColorUtil::ColorToRGBString(shape.GetFillColor()) << std::endl;
}

void CShapePrinter::Visit(CRectangleDecorator const& shape)
{
	const auto color = shape.GetFillColor();
	m_out << "rectangle p=" << shape.GetPerimeter() << " s=" << shape.GetSquare() << std::setw(2) << " " << CColorUtil::ColorToRGBString(shape.GetFillColor()) << std::endl;
}

void CShapePrinter::Visit(CTriangleDecorator const& shape)
{
	const auto color = shape.GetFillColor();
	m_out << "triangle p=" << shape.GetPerimeter() << " s=" << shape.GetSquare() << std::setw(2) << " " << CColorUtil::ColorToRGBString(shape.GetFillColor()) << std::endl;
}
