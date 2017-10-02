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

class Fixed {
public:
	Fixed (void);
	Fixed (Fixed & targetToCopy);
	~Fixed (void);

	int getRawBits (void) const;
	void setRawBits (int const raw);

	Fixed & operator=(Fixed const & targetToAssign);

private:
	static const int _nbOfFractionalBits;

	int _fixedValue;
};

#endif
