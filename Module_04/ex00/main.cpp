/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:53:13 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 14:20:02 by fadzejli         ###   ########.fr       */
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
    std::cout << "=== Test 1: Subject's Main (Correct Polymorphism) ===" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        std::cout << "\nTypes:" << std::endl;
        std::cout << "j type: " << j->getType() << std::endl;
        std::cout << "i type: " << i->getType() << std::endl;
        
        std::cout << "\nSounds:" << std::endl;
        i->makeSound(); // Cat sound!
        j->makeSound(); // Dog sound!
        meta->makeSound(); // Animal sound
        
        std::cout << "\nDeleting objects:" << std::endl;
        delete meta;
        delete j;
        delete i;
    }
    
    std::cout << "\n=== Test 2: Wrong Implementation (No Polymorphism) ===" << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        
        std::cout << "\nTypes:" << std::endl;
        std::cout << "i type: " << i->getType() << std::endl;
        
        std::cout << "\nSounds (WRONG - no virtual):" << std::endl;
        i->makeSound(); // Will output WrongAnimal sound, NOT WrongCat!
        meta->makeSound();
        
        std::cout << "\nDeleting objects:" << std::endl;
        delete meta;
        delete i;
    }
    
    std::cout << "\n=== Test 3: Direct Object Creation ===" << std::endl;
    {
        Animal animal;
        Dog dog;
        Cat cat;
        
        std::cout << "\nDirect sounds:" << std::endl;
        animal.makeSound();
        dog.makeSound();
        cat.makeSound();
        
        std::cout << "\nDestruction will happen automatically:" << std::endl;
    }
    
    std::cout << "\n=== Test 4: Copy Constructors ===" << std::endl;
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
    
    std::cout << "\n=== Test 6: Array of Animals (Polymorphism) ===" << std::endl;
    {
        const Animal* animals[4];
        
        std::cout << "Creating array:" << std::endl;
        animals[0] = new Animal();
        animals[1] = new Dog();
        animals[2] = new Cat();
        animals[3] = new Dog();
        
        std::cout << "\nMaking sounds:" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
            animals[i]->makeSound();
        }
        
        std::cout << "\nDeleting array:" << std::endl;
        for (int i = 0; i < 4; i++) {
            delete animals[i];
        }
    }
    
    std::cout << "\n=== Test 7: Demonstrating Virtual Destructor Importance ===" << std::endl;
    {
        std::cout << "With virtual destructor (Animal):" << std::endl;
        Animal* ptr1 = new Dog();
        delete ptr1; // Calls Dog destructor then Animal destructor
        
        std::cout << "\nWithout virtual destructor (WrongAnimal):" << std::endl;
        WrongAnimal* ptr2 = new WrongCat();
        delete ptr2; // Only calls WrongAnimal destructor (if not virtual)
    }
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}