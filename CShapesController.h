#pragma once
#include "IShapeCreator.h"
#include <map>

class CShapesController
{
public:
	CShapesController(std::ifstream& in, std::ofstream& out);
	~CShapesController() = default;

	bool ReadShape();
	void PrintShapes() const;
	bool End() const;
	std::vector<std::shared_ptr<IShape>> GetShapes() const;

private:
	const std::map<std::string, IShapeCreator*> m_factory;
	std::istream& m_in;
	std::ostream& m_out;
	std::vector<std::shared_ptr<IShape>> m_shapes;
	bool m_end;
};
