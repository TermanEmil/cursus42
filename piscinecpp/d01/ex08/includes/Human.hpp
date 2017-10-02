/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 00:46:30 by eterman           #+#    #+#             */
/*   Updated: 2017/07/23 00:46:30 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>

class Human
{
private:
	void meleeAttack(std::string const & target);
	void rangedAttack(std::string const & target);
	void intimidatingShout(std::string const & target);
	
public:
	void action(std::string const & action_name, std::string const & target);
};

#endif
