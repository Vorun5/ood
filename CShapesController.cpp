#include "CShapesController.h"
#include "CCircleCreator.h"
#include "CRectangleCreator.h"
#include "CTriangleCreator.h"
#include "CShapePrinter.h"
#include <fstream>
#include <iostream>

CShapesController::CShapesController(std::ifstream& in, std::ofstream& out)
	: m_factory({
		  {"circle", CCircleCreator::GetInstance()},
		  {"triangle", CTriangleCreator::GetInstance()},
		  {"rectangle", CRectangleCreator::GetInstance()},
		}),
		m_in(in),
		m_out(out),
		m_end(false)
{
}

bool CShapesController::ReadShape()
{
	std::string command;
	m_in >> command;

	if (command == "end")
	{
		m_end = true;
		return true;
	}
	if (const auto it = m_factory.find(command); it != m_factory.end())
	{
		try
		{
			std::string shapeData;
			std::getline(m_in, shapeData);
			m_shapes.push_back(it->second->FactoryMethod(shapeData));
			return true;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
			return false;
		}
	}
	std::cout << "unknown command" << std::endl;
	return false;
}

void CShapesController::PrintShapes() const
{
	const auto printer = new CShapePrinter(m_out);
	for(const auto& shape : m_shapes)
	{
		shape->Accept(*printer);
	}
}

bool CShapesController::End() const
{
	return m_end;
}

std::vector<std::shared_ptr<IShape>> CShapesController::GetShapes() const
{
	return m_shapes;
}
