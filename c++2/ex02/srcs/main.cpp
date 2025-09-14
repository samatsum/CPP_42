/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:13:58 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/06 19:20:50 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

// int main( void )
// {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }


int main(void)
{
    // std::cout << std::fixed;       // 固定小数点表記を使用
    // std::cout.precision(8);        // 小数点以下8桁を表示（十分な桁数）
    // 基本的なコンストラクタのテスト
    std::cout << "\n=== コンストラクタのテスト ===\n";
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    // 代入演算子のテスト
    std::cout << "\n=== 代入演算子のテスト ===\n";
    a = Fixed(1234.4321f);
    std::cout << "a is now " << a << std::endl;

    // 比較演算子のテスト
    std::cout << "\n=== 比較演算子のテスト ===\n";
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b >= d: " << (b >= d) << std::endl;
    std::cout << "b <= d: " << (b <= d) << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

    // 算術演算子のテスト
    std::cout << "\n=== 算術演算子のテスト ===\n";
    Fixed e(5.05f);
    Fixed f(2);
    std::cout << "e(" << e << ") + f(" << f << ") = " << (e + f) << std::endl;
    std::cout << "e(" << e << ") - f(" << f << ") = " << (e - f) << std::endl;
    std::cout << "e(" << e << ") * f(" << f << ") = " << (e * f) << std::endl;
    std::cout << "e(" << e << ") / f(" << f << ") = " << (e / f) << std::endl;

    // インクリメント/デクリメント演算子のテスト
    std::cout << "\n=== インクリメント/デクリメントのテスト ===\n";
    Fixed g(1);
    std::cout << "g is " << g << std::endl;
    std::cout << "++g is " << ++g << std::endl;
    std::cout << "g is now " << g << std::endl;
    std::cout << "g++ is " << g++ << std::endl;
    std::cout << "g is now " << g << std::endl;
    std::cout << "--g is " << --g << std::endl;
    std::cout << "g is now " << g << std::endl;
    std::cout << "g-- is " << g-- << std::endl;
    std::cout << "g is now " << g << std::endl;

    // min, max関数のテスト
    std::cout << "\n=== min, max関数のテスト ===\n";
    Fixed h(3.14f);
    Fixed i(2.72f);
    
    std::cout << "h is " << h << std::endl;
    std::cout << "i is " << i << std::endl;
    std::cout << "min(h, i) is " << Fixed::min(h, i) << std::endl;
    std::cout << "max(h, i) is " << Fixed::max(h, i) << std::endl;

    // constバージョンのmin, max関数のテスト
    const Fixed j(1.1f);
    const Fixed k(2.2f);
    
    std::cout << "\n=== const min, max関数のテスト ===\n";
    std::cout << "j is " << j << std::endl;
    std::cout << "k is " << k << std::endl;
    std::cout << "min(j, k) is " << Fixed::min(j, k) << std::endl;
    std::cout << "max(j, k) is " << Fixed::max(j, k) << std::endl;

    // 課題で示された例のテスト
    std::cout << "\n=== 課題で示された例のテスト ===\n";
    Fixed x;
    Fixed const y(Fixed(5.05f) * Fixed(2));

    std::cout << x << std::endl;
    std::cout << ++x << std::endl;
    std::cout << x << std::endl;
    std::cout << x++ << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << Fixed::max(x, y) << std::endl;

    return 0;
}
