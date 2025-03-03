#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "constituency.h"



//Not using #pragma pack(1), dont need to save memory or performance.

void constructConstituency(struct Constituency* const obj, const char* name,
    const unsigned int* neighbours, const unsigned int numNeighbours) {

        obj->name = NULL;
        obj->neighbours = NULL; 
        obj->numNeighbours = 0;

        if (name != NULL) {
            // malloc string size + "\0"
            obj->name = (char*) malloc(strlen(name) + 1); // free space for 'name'
            
            // ensure allocation worked 
            if (obj->name != NULL){
                strcpy(obj->name, name);
            }
        }

        if (neighbours != NULL) {
            obj->neighbours = (unsigned*) malloc(numNeighbours*sizeof(unsigned));
            // ensure allocation worked 
            if (obj->neighbours != NULL){
                memcpy(obj->neighbours, neighbours, sizeof(unsigned)*numNeighbours);
            }

        }

        if (numNeighbours != 0) {
            obj->numNeighbours = numNeighbours;
        }
    }

void printConstituency(struct Constituency* const obj){
    printf("Constituency Name - %s \n", obj->name);
    for (size_t i=0; i< obj->numNeighbours; i++) {
        printf("Neighbours - %zu. %u \n", i + 1, obj->neighbours[i]);
    }
    printf("This constituency has %u neighbours \n", obj->numNeighbours);
}

void destructConstituency(struct Constituency* const obj) {
    if (obj->name != NULL) {
        free(obj->name);
        obj->name = NULL;
    }

    if (obj->neighbours != NULL) {
        free(obj->neighbours);
        obj->neighbours = NULL;
    }

    if (obj->numNeighbours != 0) {
        obj->numNeighbours = 0;
    }
}
// if name, neighbours are null may cause mem leak
struct Constituency* copyConstituencies(struct Constituency* constituencies, const unsigned int numConstituencies) {
    struct Constituency* copies = malloc(numConstituencies * sizeof(struct Constituency));
    for (int i=0; i<numConstituencies; i++){

        copies[i].name = malloc(strlen(constituencies[i].name));
        strcpy(copies[i].name, constituencies[i].name);

        copies[i].neighbours = malloc(sizeof(unsigned) * constituencies[i].numNeighbours);
        memcpy(copies[i].neighbours, constituencies[i].neighbours, sizeof(unsigned)*constituencies[i].numNeighbours);

        copies[i].numNeighbours = constituencies[i].numNeighbours;
    }

    return copies;
}
