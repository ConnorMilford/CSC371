#include <string>
#include <iostream>

#include "cat.h"


int main(int argc, char* argv[]) {
    //if ()


    for (int i = 1; i < argc; i += 2) {
        std::string name = argv[i];
        unsigned int lives = std::stoi(argv[i + 1]);
        
        Cat cat(name, lives);
        std::cout << "Created cat: " << cat.get_name()
                  << " with " << cat.get_lives() << " lives." << std::endl;
    }
    
    return 0;
}