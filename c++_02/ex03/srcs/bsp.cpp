/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:39:01 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/06 21:38:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

//ベクトルAB×ベクトルAP
static Fixed cross_product(Point const& A, Point const& B, Point const& P)
{
    // (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x)…つまり外積Z成分の計算
    return (((B.get_X() - A.get_X()) * (P.get_Y() - A.get_Y())) - 
           ((B.get_Y() - A.get_Y()) * (P.get_X() - A.get_X())));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed c1;
    Fixed c2;
    Fixed c3;

    c1 = cross_product(a, b, point);
    c2 = cross_product(b, c, point);
    c3 = cross_product(c, a, point);
    // すべての外積が同じ符号（すべて正またはすべて負）（つまり、外積ベクトルの向きが同じ）なら内部
    //正の値：第1ベクトルから第2ベクトルへ反時計回りの関係
    //負の値：第1ベクトルから第2ベクトルへ時計回りの関係
    
    // 外積0の場合は辺上なので、外部と見なす
    return ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0));
}

//http://www.sousakuba.com/Programming/gs_hittest_point_triangle.html 参考にしました。わかりやすい！