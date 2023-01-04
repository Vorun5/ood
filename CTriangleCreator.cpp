#include "CTriangleCreator.h"
#include "CTriangleDecorator.h"
#include "CColorUtil.h"
#include <sstream>

CTriangleCreator* CTriangleCreator::GetInstance()
{
    if (!m_self)
    {
        m_self = new CTriangleCreator();
    }
    return m_self;
}

std::shared_ptr<IShape> CTriangleCreator::FactoryMethod(std::string& str) const
{
    std::istringstream stream(str);
    sf::Vector2f p1, p2, p3;
    stream >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
   
    return std::make_shared<CTriangleDecorator>(CTriangleDecorator::CreateConvexShape(p1, p2, p3, CColorUtil::ReadColorFromStream(stream)));
}
