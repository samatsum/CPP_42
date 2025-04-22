/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:10:36 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/22 19:24:25 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#pragma once

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        std::string _weapon;
    public:
        HumanA(std::string name, Weapon weapon);
        void    attack(void);
};

#endif