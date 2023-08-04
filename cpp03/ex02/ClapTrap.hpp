#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

// Claptrap
// Name 
// Hit points 10
// Energy points 10 replesent health
// Attack damage 0

// when claptrap attack it cause the target to lose <attack> hit point
// void attack(std::string const & target);

// when claptrap take damage it cause the target to lose <attack> hit point
// void takeDamage(unsigned int amount);

// when claptrap be repaired it cause the target to gain <repair> hit point
// void beRepaired(unsigned int amount);




class ClapTrap {

    protected:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;


    public:
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const & src);
        ~ClapTrap(void);

        ClapTrap &  operator=(ClapTrap const & src);
        
        std::string getName(void) const;
        int         getHitPoints(void) const;
        int         getEnergyPoints(void) const;
        int         getAttackDamage(void) const;

        void        attack(std::string const & target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
};

std::ostream &  operator<<(std::ostream & o, ClapTrap const & i);
#endif