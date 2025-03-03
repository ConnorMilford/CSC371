// -----------------------------------------------------
// CSC371 Advanced Object-Oriented Programming (2024/25)
//
// (c) Martin Porcheron
//     Thomas Reitmaier
//     thomas.reitmaier@swansea.ac.uk
// -----------------------------------------------------

#include <stdio.h>

#include "constituency.h"

void printAndDestroyAll(struct Constituency constituencies[], int numConstituencies);

int main()
{
  const int numConstituencies = 5;
  struct Constituency constituencies[numConstituencies];
  
  constructConstituency(
      &constituencies[0],
      "Swansea East",
      (unsigned int[]){1, 2, 3, 4},4
    );
  
  constructConstituency(
      &constituencies[1],
      "Swansea West",
      (unsigned int[]){0, 2}, 2
    );    
  
  constructConstituency(
      &constituencies[2],
      "Gower",
      (unsigned int[]){0, 1, 3}, 3
    ); 

  constructConstituency(
      &constituencies[3],
      "Neath",
      (unsigned int[]){0, 2, 4}, 3
    );   

    constructConstituency(
      &constituencies[4],
      "Aberavon",
      (unsigned int[]){0, 3}, 2
    ); 
  

  printAndDestroyAll(constituencies, numConstituencies); 

  return 0;
}


void printAndDestroyAll(struct Constituency constituencies[], int numConstituencies) {
  //temp assignments
  struct Constituency mostNeighbours = constituencies[numConstituencies-1];
  struct Constituency leastNeighbours = constituencies[numConstituencies-1];

  for (int i = 0; i < numConstituencies; i++) {
    if (constituencies[i].numNeighbours > mostNeighbours.numNeighbours){mostNeighbours = constituencies[i];}
    // no need for explicit tie condition, if it is smaller[i] and already exists it will not be overwritten
    else if (constituencies[i].numNeighbours < leastNeighbours.numNeighbours){leastNeighbours = constituencies[i];}
    
    
    printConstituency(&constituencies[i]);
  }

  printf("Least neighbours - %s with %d \n", leastNeighbours.name, leastNeighbours.numNeighbours);
  printf("Most neighbours - %s with %d \n", mostNeighbours.name, mostNeighbours.numNeighbours);

  for (int i=0; i<numConstituencies; i++) {
    destructConstituency(&constituencies[i]);
  }
}