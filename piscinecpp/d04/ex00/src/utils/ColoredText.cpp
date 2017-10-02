#include "ColoredText.hpp"

ColoredText::ColoredText (void) {
	std::cout << C_WHITE;
}

ColoredText::ColoredText (std::string const & color) {
	std::cout << color;
}

ColoredText::~ColoredText (void) {
	std::cout << C_EOC << std::endl;
}