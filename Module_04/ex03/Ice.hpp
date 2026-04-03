/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:19:43 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 15:20:11 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

class Ice : public AMateria {
	private:
		std::string _type;
	public:
		Ice();
		Ice(const Ice & src);
		virtual ~Ice();
		
		const Ice & operator=(const Ice &rhs);
		Ice * clone(const Ice & rhs) const;
		void use(ICharacter& target);
};

#endif