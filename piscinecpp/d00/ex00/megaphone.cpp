/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 11:11:57 by eterman           #+#    #+#             */
/*   Updated: 2017/07/20 13:25:52 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	print_upper(char *str) {
	while (*str) {
		std::cout << std::string(1, toupper(*str));
		str++;
	}
}

int		main(int argc, char **argv) {
	int	i;

	for (i = 1; i < argc; i++) {
		print_upper(argv[i]);
	}

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}

	std::cout << std::endl;
	return (0);
}
