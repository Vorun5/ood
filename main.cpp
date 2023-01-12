#include <SFML/Graphics.hpp>
#include "CShapePrinter.h"
#include "CShapesController.h"
#include <iostream>
#include <fstream>

#include "CCanvas.h"

int main()
{
	std::ifstream inFile("input.txt");
	std::ofstream outFile("output.txt");
	if (!inFile || !outFile)
	{
		std::cout << "file not found" << std::endl;
		return 1;
	}

	CShapesController controller(inFile, outFile);
	while (!controller.End())
	{
		controller.ReadShape();
	}
	controller.PrintShapes();

	CCanvas canvas(1000, 800, sf::Color(255, 255, 255));
	canvas.DrawShapes(controller.GetShapes());
	return 0;
	/*
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1000, 800), "ood", sf::Style::Close, settings);
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(255, 255, 255));
		for (auto& shape : controller.GetShapes())
		{
			window.draw(*shape->GetShapeInstance());
		}
		window.display();
	}

	return 0;
	*/
}

/*
auto circleCreator = CCircleCreator::GetInstance();
auto triangleCreator = CTriangleCreator::GetInstance();
auto rectangleCreator = CRectangleCreator::GetInstance();

std::string sT = "0 0 500 0 0 100 #4C8CFF";
std::string sC = "0 0 410 #FF5D02";
std::string sR = "0 100 100 0 #8F00FF";

auto circle = circleCreator->FactoryMethod(sC);
auto triangle = triangleCreator->FactoryMethod(sT);
auto rectangle = rectangleCreator->FactoryMethod(sR);

std::vector<std::shared_ptr<IShape>> shapes;
shapes.push_back(circle);
shapes.push_back(triangle);
shapes.push_back(rectangle);

CShapePrinter printer(std::cout);
*/