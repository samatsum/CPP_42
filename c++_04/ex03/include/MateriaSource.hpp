/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:41:59 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/12 20:18:17 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
#define ARRAY_SIZE 4

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _templates[ARRAY_SIZE];

public:
    MateriaSource();
    MateriaSource(const MateriaSource& original);
    ~MateriaSource();
    MateriaSource& operator=(const MateriaSource& original);

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif