/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 22:23:31 by eterman           #+#    #+#             */
/*   Updated: 2017/07/21 22:23:31 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human {
public:
	const Brain& getBrain (void) const;

	Human (void);
	~Human (void);

	std::string identify (void) const;

private:
	const Brain* _myBrain;
};

#endif