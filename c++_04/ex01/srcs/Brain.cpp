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

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain copy constructor called\n";
}

Brain &Brain::operator=(const Brain &other)
{
	int i;

	i = 0;
	while (i < 100)
	{
		ideas[i] = other.ideas[i];
		i++;
	}
	std::cout << "Brain copy assignment constructor called\n";
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor called\n";
}