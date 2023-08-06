#ifndef BRAIN_CPP
# define BRAIN_CPP

#include <iostream>
#include <string>

class Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain();
        Brain(const Brain& src);
        virtual ~Brain();
        Brain&	operator=(const Brain& rhs);

        std::string getIdea(int i) const;
        void setIdea(int i, std::string idea);
};

#endif