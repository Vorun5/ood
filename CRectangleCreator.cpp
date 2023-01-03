#include "CRectangleCreator.h"
#include "CRectangleDecorator.h"
#include "CColorUtil.h"
#include <sstream>

std::shared_ptr<IShape> CRectangleCreator::FactoryMethod(std::string& str) const
{
    std::istringstream stream(str);
    sf::Vector2f p1, p2;
    stream >> p1.x >> p1.y >> p2.x >> p2.y;
    CRectangleDecorator rectangle(p1, p2, CColorUtil::ReadColorFromStream(stream));
    return std::make_shared<CRectangleDecorator>(rectangle);
}