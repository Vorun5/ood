#include "CCircleCreator.h"
#include "CCircleDecorator.h"
#include <sstream>

#include "CColorUtil.h"

std::shared_ptr<IShape> CCircleCreator::FactoryMethod(std::string& str) const
{
    std::istringstream stream(str);
    sf::Vector2f center;
    float radius;
    stream >> center.x >> center.y >> radius;
    return std::make_shared<CCircleDecorator>(CCircleDecorator::CreateCircleShape(radius, center, CColorUtil::ReadColorFromStream(stream)));
}
