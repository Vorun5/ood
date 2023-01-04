#pragma once
#include "IShapeCreator.h"

class CRectangleCreator final : public IShapeCreator
{
public:
	CRectangleCreator(CRectangleCreator&) = delete;
	void operator=(const CRectangleCreator&) = delete;
	static CRectangleCreator* GetInstance();

	// IShapeCreator
	std::shared_ptr<IShape> FactoryMethod(std::string& str) const override;

protected:
	CRectangleCreator() = default;
	static CRectangleCreator* m_self;
};

inline CRectangleCreator* CRectangleCreator::m_self = nullptr;