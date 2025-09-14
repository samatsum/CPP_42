/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:13:58 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/08 21:56:50 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

// 各クラスの詳細情報を表示する関数
void printSeparator(const std::string& title) {
    std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main()
{
    // 各クラスの基本テスト
    printSeparator("基本クラステスト");
    
    // ClapTrapのテスト
    {
        std::cout << "--- ClapTrap テスト ---" << std::endl;
        ClapTrap Bob("Bob");
        Bob.attack("Target");
        Bob.takeDamage(5);
        Bob.beRepaired(3);
    }
    std::cout << std::endl;
    // ScavTrapのテスト
    {
        std::cout << "--- ScavTrap テスト ---" << std::endl;
        ScavTrap Jim("Jim");
        Jim.attack("Target");
        Jim.takeDamage(30);
        Jim.beRepaired(20);
        Jim.guardGate();
    }
    std::cout << std::endl;
    // FragTrapのテスト
    {
        std::cout << "--- FragTrap テスト ---" << std::endl;
        FragTrap Mike("Mike");
        Mike.attack("Target");
        Mike.takeDamage(40);
        Mike.beRepaired(30);
        Mike.highFiveGuys();
    }
    std::cout << std::endl;
    // DiamondTrapの詳細テスト
    printSeparator("DiamondTrap テスト");
    
    // 1. デフォルトコンストラクタのテスト
    {
        std::cout << "--- デフォルトコンストラクタ ---" << std::endl;
        DiamondTrap diamond;
        diamond.attack("Target");
        diamond.takeDamage(20);
        diamond.beRepaired(10);
        diamond.guardGate();
        diamond.highFiveGuys();
        diamond.whoAmI();
    }
    std::cout << std::endl;
    // 2. 名前付きコンストラクタのテスト
    {
        std::cout << "--- 名前付きコンストラクタ ---" << std::endl;
        DiamondTrap diamond("Emily");
        diamond.attack("Target");
        diamond.takeDamage(30);
        diamond.beRepaired(15);
        diamond.guardGate();
        diamond.highFiveGuys();
        diamond.whoAmI();
    }
    std::cout << std::endl;
    // 3. コピーコンストラクタのテスト
    {
        std::cout << "--- コピーコンストラクタ ---" << std::endl;
        DiamondTrap original("ORIGINAL");
        original.takeDamage(40);
        
        // コピーコンストラクタを使用
        DiamondTrap copy(original);
        
        // オリジナルとコピーの状態を比較
        std::cout << "オリジナルの状態：" << std::endl;
        original.whoAmI();
        original.attack("Target");
        
        std::cout << "コピーの状態：" << std::endl;
        copy.whoAmI();
        copy.attack("Target");
    }
    std::cout << std::endl;
    // 4. 代入演算子のテスト
    {
        std::cout << "--- 代入演算子 ---" << std::endl;
        DiamondTrap original("AssignOriginal");
        original.takeDamage(25);
        
        // 別のオブジェクトを作成し、代入
        DiamondTrap assigned("AssignedObject");
        assigned = original;
        
        // オリジナルと代入先の状態を比較
        std::cout << "オリジナルの状態：" << std::endl;
        original.whoAmI();
        original.attack("Target");
        
        std::cout << "代入先の状態：" << std::endl;
        assigned.whoAmI();
        assigned.attack("Target");
    }
    std::cout << std::endl;
    // 5. 継承された機能のテスト
    {
        std::cout << "--- 継承された機能 ---" << std::endl;
        DiamondTrap diamond("Inheritance");
        
        // ScavTrapから継承されたattack
        std::cout << "ScavTrapのattack：" << std::endl;
        diamond.attack("Target");
        
        // ScavTrapから継承されたguardGate
        std::cout << "ScavTrapのguardGate：" << std::endl;
        diamond.guardGate();
        
        // FragTrapから継承されたhighFiveGuys
        std::cout << "FragTrapのhighFiveGuys：" << std::endl;
        diamond.highFiveGuys();
        
        // DiamondTrap固有のwhoAmI
        std::cout << "DiamondTrap固有のwhoAmI：" << std::endl;
        diamond.whoAmI();
    }
    std::cout << std::endl;
    // 6. エネルギーと体力の動作テスト
    {
        std::cout << "--- エネルギーと体力のテスト ---" << std::endl;
        DiamondTrap diamond("Endurance");
        
        // 体力を使い果たすまでダメージ
        std::cout << "体力テスト：" << std::endl;
        diamond.takeDamage(70);
        diamond.takeDamage(50); // すでにほとんど体力がないはず
        
        // 体力がなくなった状態での操作
        diamond.attack("Target"); // 失敗するはず
        diamond.beRepaired(10);   // 失敗するはず
        
        // 新しいDiamondTrapを作成してエネルギーテスト
        DiamondTrap energyTest("EnergyTest");
        std::cout << "エネルギーテスト：" << std::endl;
        
        // エネルギーを使い果たすまで攻撃（ScavTrapから50エネルギーポイント継承）
        for (int i = 0; i < 25; i++) {
            energyTest.attack("Target");
            energyTest.beRepaired(1);
        }
        
        // エネルギーがなくなった後の操作
        energyTest.attack("Target");    // 失敗するはず
        energyTest.beRepaired(10);      // 失敗するはず
        energyTest.highFiveGuys();      // エネルギーは必要ないはず
        energyTest.guardGate();         // エネルギーは必要ないはず
    }
    std::cout << std::endl;
    printSeparator("テスト終了");
    
    return 0;
}
