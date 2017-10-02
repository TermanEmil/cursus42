/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 13:28:41 by eterman           #+#    #+#             */
/*   Updated: 2017/07/23 14:25:32 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
public:
	static int fracNb();

	Fixed (void);
	Fixed (Fixed const & targetToCopy);
	Fixed (int const nb);
	Fixed (float const nb);
	~Fixed (void);

	int getRawBits (void) const;
	void setRawBits (int const raw);
	float toFloat (void) const;
	int toInt (void) const;

	Fixed & operator = (Fixed const & targetToAssign);


	//Boolean operators
	bool operator > (Fixed const & target) const;
	bool operator < (Fixed const & target) const;
	bool operator >= (Fixed const & target) const;
	bool operator <= (Fixed const & target) const;
	bool operator == (Fixed const & target) const;
	bool operator != (Fixed const & target) const;


	//Arithmetic operators
	Fixed operator + (Fixed const & target) const;
	Fixed operator - (Fixed const & target) const;
	Fixed operator * (Fixed const & target) const;
	Fixed operator / (Fixed const & target) const;


	//Pre
	Fixed & operator ++ (void);
	Fixed & operator -- (void);

	//Post
	Fixed operator ++ (int);
	Fixed operator -- (int);

	//Min Max

	static const Fixed & max(Fixed const & target1, Fixed const & target2);
	static const Fixed & min(Fixed const & target1, Fixed const & target2);

private:
	static const int _nbOfFractionalBits;

	int _fixedValue;
};

std::ostream & operator<<(std::ostream & o, Fixed const & fixed);


#endif
