#ifndef COLOREDTEXT_HPP
# define COLOREDTEXT_HPP

# include <string>
# include <iostream>
# include "ft_colors.h"

class ColoredText
{
public:
	ColoredText (void);
	ColoredText (std::string const & color);
	~ColoredText (void);
};

#endif