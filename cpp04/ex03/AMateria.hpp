#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria();
        AMateria(std::string const & type);
        virtual ~AMateria();

        std::string const & getType() const;
        virtual void user(ICharacter& target);
}


#endif