#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const & src);
        ~FragTrap(void);

        FragTrap &  operator=(FragTrap const & src);

        void  highFivesGuys();
};

std::ostream &  operator<<(std::ostream & o, FragTrap const & src);
#endif