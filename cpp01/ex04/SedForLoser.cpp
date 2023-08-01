#include "SedForLoser.hpp"

SedForLoser::SedForLoser(std::string infile) : _infile(infile)
{
    this->_outfile = infile + ".replace";
    this->_error_message = "Error: can't open file: " + infile;
    std::cout << "SedForLoser constructor called" << std::endl;
}

SedForLoser::~SedForLoser()
{
    std::cout << "SedForLoser destructor called" << std::endl;
}

void SedForLoser::myReplace(std::string s1, std::string s2)
{
    std::ifstream   infile_stream(this->_infile.c_str());
    std::ofstream   outfile_stream(this->_outfile.c_str());
    std::string     line;

    if (!infile_stream.is_open())
    {
        std::cout << this->_error_message << std::endl;
        return ;
    }
    while (std::getline(infile_stream, line))
    {
        while (line.find(s1) != std::string::npos)
            line.replace(line.find(s1), s1.length(), s2);
        outfile_stream << line << std::endl;
    }
    std::cout << "Done!\n file: " << this->_outfile << " had created!" << std::endl;
    infile_stream.close();
    outfile_stream.close();
}