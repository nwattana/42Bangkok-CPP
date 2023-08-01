#include "main.hpp"

int main (int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return (1);
    }
    SedForLoser sedforloser(argv[1]);
    sedforloser.myReplace(argv[2], argv[3]);
}