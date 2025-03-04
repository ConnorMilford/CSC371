#pragma once 
#include <string>

class Cat {
    private:
        std::string name;
        unsigned int lives; 

    public:
        Cat(std::string name);
        Cat(std::string name, unsigned int lives);
        ~ Cat();

        std::string const get_name();
        unsigned int const get_lives();

        void set_name(std::string const name);
        void set_lives(unsigned int const lives);
};


