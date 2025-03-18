#include <string>
#include <iostream>

#include "cat.h"


Cat:: Cat(std::string name): name(name), lives(9) {
    std::cout << "Constructor called with name " << name << "\n"; 
}

Cat::Cat(std::string name, unsigned int lives): name(name), lives(lives) {
    std::cout << "Constuctor called with name " << name
    << " They have " << lives << " lives \n";
}

Cat::~Cat() {
    std::cout << "Destructor called \n"; 
}

std::string const Cat::get_name() const {
    return this->name;
}

unsigned int const Cat::get_lives() const {
    return this->lives;
}

void Cat::set_name(std::string const name) {
    this->name = name;
    std::cout << "set_name called\n";
}

void Cat::set_lives(unsigned int const lives) {
    std::cout << "set_lives called\n";

    if (lives >= this->lives) {
        return;
    }

    if (this->lives > 0 && lives == 0) {
        set_name("The cat formerly known as " + get_name() + "\n");
        this->lives = lives;
    }
    
    if (lives > 1) {
        this->lives = lives;
    }
}





