/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:12:50 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/13 16:07:36 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &copy);
        ~WrongCat();
		WrongCat &operator=(const WrongCat &original);

		void makeSound(void) const; // オーバーライドするが、ポリモーフィズムは機能しない
		// オーバーライド自体は行われている（WrongCatはWrongAnimalのmakeSoundを上書きしている）
		// しかし、基底クラスでメソッドがvirtualと宣言されていないため、ポリモーフィズムが機能しない
		//「同じ名前の関数が、オブジェクトの実際の型に応じて異なる挙動を示す」が　ポリモーフィズム。
};

#endif