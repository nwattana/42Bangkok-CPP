#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// why public here ? -> https://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance
// all inheritance will have same access level as base class.
class ScavTrap : public ClapTrap {

    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const & src);
        ~ScavTrap(void);

        ScavTrap &  operator=(ScavTrap const & src);

        void        attack(std::string const & target);
        // void        takeDamage(unsigned int amount);
        // void        beRepaired(unsigned int amount);

        void        guardGate();
};

std::ostream &  operator<<(std::ostream & o, ScavTrap const & src);
#endif