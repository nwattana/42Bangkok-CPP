#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, FragTrap {
    
        public:
            DiamondTrap(std::string name);
            DiamondTrap(DiamondTrap const & src);
            ~DiamondTrap(void);
    
            DiamondTrap &  operator=(DiamondTrap const & src);
            void   attack(std::string const & target);
            std::string getMyName(void) const;
            std::string getFragName(void) const;
            std::string getScavName(void) const;
            void        whoAmI() const;
        
        private:
            std::string _name;
};

std::ostream &  operator<<(std::ostream & o, DiamondTrap const & src);

#endif