#pragma once
#include "IShapeCreator.h"

class CCircleCreator final : public IShapeCreator
{
public:
	CCircleCreator(CCircleCreator&) = delete;
	void operator=(const CCircleCreator&) = delete;
	static CCircleCreator* GetInstance();
	
	// IShapeCreator
	std::shared_ptr<IShape> FactoryMethod(std::string& str) const override;

protected:
	CCircleCreator() = default;
	static CCircleCreator* m_self;
};

inline CCircleCreator* CCircleCreator::m_self = nullptr;