#include "Harl.hpp"

int main(void)
{
    Harl harl;

    harl.announce("debug");
    harl.announce("info");
    harl.announce("warning");
    harl.announce("error");
    harl.announce("test");
    return (0);
}