#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl harl;
    std::string str;
    std::string levels[4] = {"debug", "info", "warning", "error"};
    int i;
    int found=0;

    if (argc != 2)
    {
        std::cout << "Usage: ./harl [debug, info, warning, error]" << std::endl;
        return (1);
    }

    for (i=3; i>0; i--)
    {
        if (levels[i] == argv[1])
        {
            found = 1;
            break;
        }
    }
    
    if (!found)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (0);
    }

    i = 3 - i;
    switch (i)
    {
        case 3:
            harl.announce("debug");
            i--;
        case 2:
            harl.announce("info");
            i--;
        case 1:
            harl.announce("warning");
            i--;
        case 0:
            harl.announce("error");
            i--;
        default:
            break;
    }
    return (0);
}