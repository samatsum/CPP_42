/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:13:58 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/06 20:58:36 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

int main() {
    // 三角形の頂点を定義
    Point a(0.0f, 0.0f);    // 原点
    Point b(10.0f, 30.0f);  // 第二頂点
    Point c(20.0f, 0.0f);   // 第三頂点

    // テストケース
    Point inside(10.0f, 10.0f);     // 三角形の内部にある点
    Point outside(30.0f, 15.0f);    // 三角形の外部にある点
    Point onEdge(10.0f, 0.0f);      // 三角形の辺上にある点
    Point onVertex(0.0f, 0.0f);     // 三角形の頂点上にある点

    // テスト結果表示
    std::cout << "三角形の頂点: A(0,0), B(10,30), C(20,0)" << std::endl;
    std::cout << "内部の点 (10,10): " << (bsp(a, b, c, inside) ? "内部" : "外部") << std::endl;
    std::cout << "外部の点 (30,15): " << (bsp(a, b, c, outside) ? "内部" : "外部") << std::endl;
    std::cout << "辺上の点 (10,0): " << (bsp(a, b, c, onEdge) ? "内部" : "外部") << std::endl;
    std::cout << "頂点上の点 (0,0): " << (bsp(a, b, c, onVertex) ? "内部" : "外部") << std::endl;

    return 0;
}