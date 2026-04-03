/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:29:30 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 14:40:06 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include "Brain.hpp"
#include <iostream>
#include <string>

class AAnimal {
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal const & src);
		virtual ~AAnimal();

		AAnimal & 				operator=(AAnimal const & other);
		std::string 			getType() const;
		void					setType(std::string type);
		virtual void			makeSound() const = 0;
	protected:
		std::string _type;
};

#endif