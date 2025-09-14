/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:45:18 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/12 19:41:08 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice& original);
    ~Ice();
    Ice& operator=(const Ice& original);

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif