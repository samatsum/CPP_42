#include "../include/DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap()
: ClapTrap()
, ScavTrap()
, FragTrap()
{
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original)
: ClapTrap(original)
, ScavTrap(original)
, FragTrap(original)
, _name(original._name)
{
    std::cout << "DiamondTrap " << this->_name << " Copy Constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name")
, ScavTrap(name)
, FragTrap(name)
, _name(name)
{
    std::cout << "DiamondTrap " << this->_name << " Constructor called" << std::endl;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

// Deconstructors
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
    std::cout << "DiamondTrap " << this->_name << " Assignment Operator called" << std::endl;
    if (this != &original)
    {
        ClapTrap::operator=(original);
        this->_name = original._name;
    }
    return *this;
}

// Public Methods
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name is " << this->_name << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::_name << std::endl;
}