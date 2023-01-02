#include <SFML/Graphics.hpp>

#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1000, 800), "ood", sf::Style::Close, settings);
    window.setFramerateLimit(60);

    CCircleDecorator circle(200, 0, 0);
    CTriangleDecorator  triangle(0, 0, 100, 100, 0, 100);
    CRectangleDecorator rectangle(100, 100, 200, 200);

    std::vector<IShapeDecorator*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(&triangle);
    shapes.push_back(&rectangle);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color( 255, 255, 255));
        for (auto& shape : shapes)
        {
            window.draw(*shape->GetShapeInstance());
        }
        window.display();
    }

    return 0;
}
