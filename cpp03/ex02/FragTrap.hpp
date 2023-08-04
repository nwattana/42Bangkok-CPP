#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : protected ClapTrap {

    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const & src);
        ~FragTrap(void);

        FragTrap &  operator=(FragTrap const & src);

        std::string getName(void) const;
        int         getHitPoints(void) const;
        int         getEnergyPoints(void) const;
        int         getAttackDamage(void) const;
        bool        isDead(void);

        void        attack(std::string const & target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);

        void  highFivesGuys();
};

std::ostream &  operator<<(std::ostream & o, FragTrap const & src);
#endif