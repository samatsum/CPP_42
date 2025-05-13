/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:41:09 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/12 20:25:02 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"
#include <iostream>

int main()
{
    
{
    // Basic test from subject PDF
    std::cout << "---- BASIC TEST FROM SUBJECT ----" << std::endl;
    IMateriaSource* original = new MateriaSource();
    std::cout << "----01----" << std::endl;
    original->learnMateria(new Ice());
    std::cout << "----02----" << std::endl;
    original->learnMateria(new Cure());
    std::cout << "----03----" << std::endl;
    
    ICharacter* me = new Character("me");
    std::cout << "----04----" << std::endl;
    AMateria* tmp;
    std::cout << "----05----" << std::endl;
    tmp = original->createMateria("ice");
    std::cout << "----06----" << std::endl;
    me->equip(tmp);
    std::cout << "----07----" << std::endl;
    tmp = original->createMateria("cure");
    std::cout << "----08----" << std::endl;
    me->equip(tmp);
    std::cout << "----09----" << std::endl;
    
    ICharacter* bob = new Character("bob");
    std::cout << "----10----" << std::endl;
    
    me->use(0, *bob);
    std::cout << "----11----" << std::endl;
    me->use(1, *bob);
    std::cout << "----12----" << std::endl;
    
    delete bob;
    delete me;
    delete original;
}
{    
    AMateria* tmp;
    // Additional tests
    std::cout << "\n---- ADDITIONAL TESTS ----" << std::endl;
    std::cout << "\n# Testing character copy:" << std::endl;
    Character original("Original");
    
    tmp = new Ice();
    original.equip(tmp);
    tmp = new Cure();
    original.equip(tmp);
    
    // Copy construction
    Character copy(original);
    std::cout << "Original character using materias:" << std::endl;
    original.use(0, original);
    original.use(1, original);
    
    std::cout << "Copied character using materias:" << std::endl;
    copy.use(0, copy);
    copy.use(1, copy);
    
    // Unequip test
    std::cout << "\n# Testing unequip:" << std::endl;
    original.unequip(0);
    std::cout << "Original after unequipping slot 0:" << std::endl;
    original.use(0, original);
    original.use(1, original);
    
    std::cout << "\n# Testing MateriaSource capacity:" << std::endl;
    MateriaSource ms;
    ms.learnMateria(new Ice());
    ms.learnMateria(new Cure());
    ms.learnMateria(new Ice());
    ms.learnMateria(new Cure());
    ms.learnMateria(new Ice());
    
    std::cout << "\n# Testing unknown materia creation:" << std::endl;
    tmp = ms.createMateria("unknown");
    if (tmp)
        delete tmp;
    
    return 0;
}
}
