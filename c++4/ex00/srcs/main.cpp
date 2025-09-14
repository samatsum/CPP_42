/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:13:58 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/09 16:38:12 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    // 正常な多態性のテスト
    std::cout << "=== Animal Polymorphism Tests ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    
    i->makeSound(); // 猫の鳴き声を出力！
    j->makeSound(); // 犬の鳴き声を出力！
    meta->makeSound(); // 動物の鳴き声を出力
    
    // メモリリークを防ぐために削除
    delete meta;
    delete j;
    delete i;
    
    // WrongAnimalとWrongCatのテスト - 多態性が機能しないことを示す
    std::cout << "\n=== WrongAnimal Tests (No Polymorphism) ===" << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    
    std::cout << wrong_cat->getType() << " " << std::endl;
    std::cout << wrong_meta->getType() << " " << std::endl;
    
    wrong_cat->makeSound(); // WrongCatのmakeSoundではなく、WrongAnimalのmakeSoundが呼ばれる
    wrong_meta->makeSound();

    delete wrong_meta;
    delete wrong_cat;
    
    return 0;
}
