/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:50:21 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 12:50:21 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <string>

class Pony {

public:
	std::string getName(void) const;
	
	Pony (std::string newName);
	~Pony (void);

	void jump(void) const;

private:
	std::string _name;
};

#endif