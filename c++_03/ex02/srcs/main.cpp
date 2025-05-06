/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:13:58 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/07 01:13:28 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ScavTrap.hpp"

int main()
{
    // 基本的なClapTrapのテスト
    std::cout << "===== ClapTrap Tests =====" << std::endl;
    ClapTrap Bob("Bob");
    Bob.attack("Target");
    Bob.takeDamage(5);
    Bob.beRepaired(3);
    std::cout << std::endl;
    
    // ScavTrapのテスト
    std::cout << "===== ScavTrap Tests =====" << std::endl;
    ScavTrap Jim("Jim");
    
    // 攻撃力・HP・エネルギーポイントのテスト
    Jim.attack("Target");
    Jim.takeDamage(30);
    Jim.beRepaired(20);
    
    // guardGate機能のテスト
    Jim.guardGate();
    Jim.guardGate(); // 二回目を呼び出し、既にガード中メッセージを確認
    
    // エネルギーポイント使い果たしのテスト
    std::cout << "\n===== Energy Point Test =====" << std::endl;
    // エネルギーポイントを使い果たす
    for (int i = 0; i < 48; i++) {
        Jim.attack("Target");
    }
    // エネルギーポイントが尽きた後の動作確認
    Jim.attack("Target");
    Jim.beRepaired(10);
    
    // HPが0になった場合のテスト
    std::cout << "\n===== HP Depletion Test =====" << std::endl;
    ScavTrap Mike("Mike");
    // HPが0になるまでダメージを与える
    Mike.takeDamage(70);
    Mike.takeDamage(50); // HP以上のダメージ
    
    // HP0後の動作確認
    Mike.attack("Target");
    Mike.beRepaired(10);
    
    // コピーコンストラクタとコピー代入演算子のテスト
    std::cout << "\n===== Copy Test =====" << std::endl;
    ScavTrap original("ORIGINAL");
    original.takeDamage(20);
    
    // コピーコンストラクタ
    ScavTrap copy(original);
    copy.attack("CopyTest");
    
    // コピー代入演算子
    ScavTrap Assigned("Assigned");
    Assigned = original;
    Assigned.attack("AssignTest");
    
    std::cout << "\n===== Destruction Test =====" << std::endl;
    // ここでスコープが終了し、全てのオブジェクトのデストラクタが呼ばれる
    return 0;
}