#pragma once
#include "SFML/Graphics/Color.hpp"
#include <fstream>
#include <iomanip>

class CColorUtil
{
public:
	~CColorUtil() = default;

	static sf::Color ReadColorFromStream(std::istream& stream)
	{
		char ch;
		if (uint32_t hex; stream >> ch && ch == '#' && stream >> std::hex >> hex && hex <= 16777215)
		{
			std::uint8_t r = (hex & 0xff0000) >> 16;
			std::uint8_t g = (hex & 0x00ff00) >> 8;
			std::uint8_t b = hex & 0x0000ff;
			return {r, g, b};
		}
		throw std::invalid_argument("color util: is not hex color");
	}

	static std::string ColorToRGBString(const sf::Color color)
	{
		return "RGB(" + std::to_string(color.r) + ", " + std::to_string(color.g) + ", " +  std::to_string(color.b) + ")";
	}
};
