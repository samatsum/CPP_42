/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:18:58 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/24 18:33:52 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#pragma once

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon      *_weapon;
    public:
        HumanB(std::string name);
        void    setWeapon(Weapon& weapon);
        void    attack(void);
};

#endif