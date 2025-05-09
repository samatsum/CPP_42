#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &original);
		DiamondTrap(std::string name);
	    ~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &original);

		void attack(const std::string &target);
		void whoAmI(void);
};

#endif