#include "Harl.hpp"

Harl::Harl(void){
    return;
}

Harl::~Harl(void){
    return;
}

void Harl::debug(void){
    std::cout << "[  DEBUG  ] : " ;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
    std::cout << "[  INFO.  ] : " ;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void){
    std::cout << "[ WARNING ] : ";
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error(void){
    std::cout << "[  ERROR  ] : " ;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::announce(std::string level){

    std::string levels[4] = {"debug", "info", "warning", "error"};
    void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*func[i])();
            return;
        }
    }
    std::cout << "[ " << level << " ]" << " : is Not exist" << std::endl;

    // if (level == "debug")
    //     this->debug();
    // else if (level == "info")
    //     this->info();
    // else if (level == "warning")
    //     this->warning();
    // else if (level == "error")
    //     this->error();
    // else
    //     std::cout << "[ " << level << " ]" << " : is Not exist" << std::endl;
}