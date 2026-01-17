/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:53:13 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 15:03:18 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	return 0;
}*/

int main()
{

    std::cout << "=== Test 4: Copy Constructors ===" << std::endl;
    {
        Dog original("Buddy");
        Dog copy(original);
        
        std::cout << "\nOriginal and copy:" << std::endl;
        original.makeSound();
        copy.makeSound();
        
        std::cout << "\nDestruction:" << std::endl;
    }
    
    std::cout << "\n=== Test 5: Assignment Operator ===" << std::endl;
    {
        Cat cat1("Whiskers");
        Cat cat2("Mittens");
        
        std::cout << "\nBefore assignment:" << std::endl;
        std::cout << "cat1 type: " << cat1.getType() << std::endl;
        std::cout << "cat2 type: " << cat2.getType() << std::endl;
        
        cat2 = cat1;
        
        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << "cat2 type: " << cat2.getType() << std::endl;
        
        std::cout << "\nDestruction:" << std::endl;
    }
    
    std::cout << "\n=== All tests completed ===";
    return 0;
}