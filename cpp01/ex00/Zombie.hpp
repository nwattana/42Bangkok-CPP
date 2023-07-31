#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

/// @brief Zombie class
/// @details This class is a zombie BraiiiiiinnnzzzZ !
class Zombie
{
    private:
        std::string _name;


    public:
        Zombie(std::string name);
        ~Zombie();
        
        void announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif