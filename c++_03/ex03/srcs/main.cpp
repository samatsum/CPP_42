/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:13:58 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/07 02:44:28 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main()
{
    // ClapTrapのテスト
    std::cout << "===== ClapTrap Tests =====" << std::endl;
    ClapTrap Bob("Bob");
    Bob.attack("Target");
    Bob.takeDamage(5);
    Bob.beRepaired(3);
    std::cout << std::endl;
    
    // ScavTrapのテスト
    std::cout << "===== ScavTrap Tests =====" << std::endl;
    ScavTrap Jim("Jim");
    Jim.attack("Target");
    Jim.takeDamage(30);
    Jim.beRepaired(20);
    Jim.guardGate();
    std::cout << std::endl;
    
    // FragTrapのテスト
    std::cout << "===== FragTrap Tests =====" << std::endl;
    FragTrap Mike("Mike");
    
    // 攻撃力・HP・エネルギーポイントのテスト
    Mike.attack("Target");
    Mike.takeDamage(40);
    Mike.beRepaired(25);
    
    // highFiveGuys機能のテスト
    Mike.highFiveGuys();
    
    // エネルギーポイント使い果たしのテスト
    std::cout << "\n===== FragTrap Energy Point Test =====" << std::endl;
    // エネルギーポイントを使い果たす（attack + repairで合計100回のアクション）
    for (int i = 0; i < 49; i++) {
        Mike.attack("Target");
    }
    Mike.attack("Target");
    Mike.beRepaired(10);
    
    // HPが0以下になった場合のテスト
    std::cout << "\n===== FragTrap HP Depletion Test =====" << std::endl;
    FragTrap Henry("Henry");
    // HPが0以下になるまでダメージを与える
    Henry.takeDamage(80);
    Henry.takeDamage(50); // HP以上のダメージ
    
    // HP0以下後の動作確認
    Henry.attack("Target");
    Henry.beRepaired(10);
    
    // コピーコンストラクタとコピー代入演算子のテスト
    std::cout << "\n===== FragTrap Copy Test =====" << std::endl;
    FragTrap original("Original");
    original.takeDamage(20);
    
    // コピーコンストラクタ
    FragTrap copy(original);
    copy.attack("CopyTest");
    
    // コピー代入演算子
    FragTrap assigned("Assigned");
    assigned = original;
    assigned.attack("AssignTest");
    
    // 継承階層の確認 - 継承したクラスが正しく動作するか
    std::cout << "\n===== Inheritance Test =====" << std::endl;
    ClapTrap* BobPtr1 = &Jim; // ScavTrapをClapTrapとして扱う
    ClapTrap* BobPtr2 = &Mike; // FragTrapをClapTrapとして扱う
    
    BobPtr1->attack("Virtual Target");
    BobPtr2->attack("Virtual Target");
    
    std::cout << "\n===== Destruction Test =====" << std::endl;
    // ここでスコープが終了し、全てのオブジェクトのデストラクタが呼ばれる
    return 0;
}