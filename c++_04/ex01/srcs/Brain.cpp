/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:46:15 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/13 16:16:46 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
    int i;

	i = 0;
	while (i < 100)
	{
		ideas[i] = "Idea";
		i++;
	}
}

// 浅いコピー(Shallow Copy):

// ポインタの「アドレス値のみ」をコピーする
// 結果として、コピー元とコピー先が同じメモリ領域を指す
// C++のデフォルトのコピーコンストラクタや代入演算子は浅いコピーを行う

// 深いコピー(Deep Copy):

// ポインタが指す「オブジェクト自体」を複製する
// コピー先には新しいメモリ領域を割り当てる
// 明示的に実装する必要がある

// 浅いコピーでは次の問題が発生します:

// 共有リソースの問題:

// 複数のオブジェクトが同じBrainを参照することになる
// 一方の変更がもう一方に影響してしまう


// メモリ管理の問題:

// 一方のオブジェクトがデストラクタでBrainを削除すると、もう一方のオブジェクトはダングリングポインタを持つことになる
// 二重解放の危険性がある

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called\n";
    for (int i = 0; i < 100; ++i)
    {
        ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy assignment operator called\n";
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
        {
            ideas[i] = other.ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor called\n";
}