#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : protected ClapTrap {

    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const & src);
        ~ScavTrap(void);

        ScavTrap &  operator=(ScavTrap const & src);

        std::string getName(void) const;
        int         getHitPoints(void) const;
        int         getEnergyPoints(void) const;
        int         getAttackDamage(void) const;
        bool        isDead(void);

        void        attack(std::string const & target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);

        void guardGate();
};

// Work like __str__ in Python
std::ostream &  operator<<(std::ostream & o, ScavTrap const & src);
#endif