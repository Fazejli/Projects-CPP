/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:53:13 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 17:13:06 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    int index(0);
    const int SIZE = 4;

    std::cout << "=== Subject test (no leak) ===" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j; // should not create a leak
    delete i;
    
    std::cout << "\n=== Creating array test (half Dog, half Cat) ===" << std::endl;
    AAnimal* Aanimals[SIZE];
    // Dogs
    while (index < SIZE / 2)
    {
        Aanimals[index] = new Dog();
        index++;
    }
    // Cats
    while (index < SIZE)
    {
        Aanimals[index] = new Cat();
        index++;
    }
    std::cout << "\n=== Deleting array test ===" << std::endl;
    index = 0;
    while (index < SIZE)
    {
        delete Aanimals[index];
        index++;
    }
    std::cout << "\n=== Check the ideas ===" << std::endl;
    Dog basic("Tom");
    Brain *brain;

    brain = basic.getBrain();
    brain->setIdea(0, "I have to eat!");
    brain->setIdea(1, "Let's play!");
    brain->setIdea(2, "I need to go out :/");
    for (int i = 0; i < 100; i++)
        std::cout << basic.getBrain()->getIdea(i) << std::endl;
    std::cout << "\n=== Dog class: Testing deep copy using copy constructor ===" << std::endl;
    {
        Dog *dogA = new Dog;
        Dog *dogB = new Dog(*dogA);

        delete dogA;
        delete dogB;
    }
    std::cout << "\n=== Dog class: Testing deep copy using assignment operator ===" << std::endl;
    {
        Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		*dogA = *dogB;
		delete dogA;
		delete dogB;
    }
    std::cout << "\n=== Cat class: Testing deep copy using copy constructor ===" << std::endl;
    {
        Cat *catA = new Cat;
        Cat *catB = new Cat(*catA);

        delete catA;
        delete catB;
    }
    std::cout << "\n=== Cat class: Testing deep copy using assignment operator ===" << std::endl;
    {
        Cat *catA = new Cat;
		Cat *catB = new Cat;

		*catA = *catB;
		delete catA;
		delete catB;
    }
    return 0;
}