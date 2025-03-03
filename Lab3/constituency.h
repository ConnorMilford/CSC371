#ifndef CONSTITUENCY_H
#define CONSTITUENCY_H

struct Constituency
{
    char *name;

    unsigned *neighbours;

    unsigned numNeighbours;

}; //could have done typedef struct constituency_t


void constructConstituency(struct Constituency* const c, const char* name,
     const unsigned int* neighbours, const unsigned int numNeighbours);

void destructConstituency(struct Constituency* const c);

void printConstituency(struct Constituency*  const c);

struct Constituency* copyConstituencies(struct Constituency *constituencies, const unsigned int numConstituencies);

#endif

