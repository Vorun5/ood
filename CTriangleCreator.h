#pragma once
#include "IShapeCreator.h"

class CTriangleCreator final : public IShapeCreator
{
public:
	CTriangleCreator(CTriangleCreator&) = delete;
	void operator=(const CTriangleCreator&) = delete;
	static CTriangleCreator* GetInstance();
	
	// IShapeCreator
	std::shared_ptr<IShape> FactoryMethod(std::string&) const override;

protected:
	CTriangleCreator() = default;
	static CTriangleCreator* m_self;
};

inline CTriangleCreator* CTriangleCreator::m_self = nullptr;