// -----------------------------------------------------
// CSC371 Advanced Object-Oriented Programming (2024/25)
//
// (c) Martin Porcheron
//     Thomas Reitmaier
//     thomas.reitmaier@swansea.ac.uk
// -----------------------------------------------------

#include <iostream>

#include "cat.h"

int main(int argc, char* argv[]) {
    Cat a("Garfield");
    
    std::cout << a.get_name() << " has "
              << a.get_lives() << " lives." << std::endl;
              
    Cat b("Mog" , 10);
    std::cout << b.get_name() << " has "
              << b.get_lives() << " lives." << std::endl;


    b.set_lives(42);
    std::cout << " Lives: " << b.get_lives() << "\n";
    
    b.set_name("Prince");
    std::cout << " Name: " << b.get_name() << "\n";
    
    b.set_lives(8);
    std::cout << " Lives: " << b.get_lives() << "\n";
    
    b.set_lives(0);
    std::cout << " Lives: " << b.get_lives() << "\n";
    std::cout << " Name: " << b.get_name() << "\n";

    b.set_lives(0);
    std::cout << " Lives: " << b.get_lives() << "\n";
    std::cout << " Name: " << b.get_name() << "\n";          
              
    return 0;

};
