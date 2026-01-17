/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:36:09 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 16:23:24 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"
#include <iostream>

class Brain{
	public:
		Brain();
		~Brain();
		Brain(Brain const & src);

		Brain & operator=(Brain const & other);
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
	private:
		std::string ideas[100];
};

#endif