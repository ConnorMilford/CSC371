// -----------------------------------------------------
// CSC371 Advanced Object-Oriented Programming (2024/25)
//
// (c) Martin Porcheron
//     Thomas Reitmaier
//     thomas.reitmaier@swansea.ac.uk
// -----------------------------------------------------

#include <iostream>
#include <set>

#include "cat.h"

int main(int argc, char* argv []) {

  std::set <Cat> unique_cats;
  unique_cats.insert(Cat("Garfield",  42));
  unique_cats.insert(Cat("Garfield",  10));
  unique_cats.insert(Cat("Catbert",   666));
  unique_cats.insert(Cat("Toothless", 13));
  unique_cats.insert(Cat("Garfield",  42)); 
  unique_cats.insert(Cat("Garfield",  42));

  std::cout << "Unique Ordered Cats" << std::endl;
  for (auto it = unique_cats.begin(); it != unique_cats.end(); it++) {
    std::cout << *it << std::endl;
  }

  return 0;
}
