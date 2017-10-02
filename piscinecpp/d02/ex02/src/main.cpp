/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 14:25:43 by eterman           #+#    #+#             */
/*   Updated: 2017/07/23 14:25:43 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "Emil tests:" << std::endl;

	Fixed const emilA(Fixed(3) / Fixed(2));

	std::cout << emilA << std::endl; // 1.5
	std::cout << Fixed::min( a, b ) << std::endl; 

	Fixed n1;
	n1.setRawBits(1);
	Fixed n2 = ++n1;
	Fixed n3 = ++ ++n1;
	Fixed n4 = n1++;

    std::cout << "n1 = " << n1.getRawBits() << std::endl  // 5
              << "n2 = " << n2.getRawBits() << std::endl  // 2
              << "n3 = " << n3.getRawBits() << std::endl  // 4
              << "n4 = " << n4.getRawBits() << std::endl; // 4

	std::cout << (n1 > n2) << std::endl;	//1
	std::cout << (n1 < n2) << std::endl;	//0
	std::cout << (n3 > n4) << std::endl;	//0
	std::cout << (n3 >= n4) << std::endl;	//1
	std::cout << (n3 < n4) << std::endl;	//0
	std::cout << (n3 <= n4) << std::endl;	//1
}