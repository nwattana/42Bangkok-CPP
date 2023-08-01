#ifndef SEDFORLOSER_HPP
# define SEDFORLOSER_HPP

# include <iostream>
# include <string>
# include <fstream>

class SedForLoser
{
    private:
        std::string        _infile;
        std::string        _outfile;

        std::string        _error_message;

    public:
        SedForLoser(std::string infile);
        ~SedForLoser();
        void	myReplace(std::string s1, std::string s2);
};



#endif