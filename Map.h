#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <stdio.h>
#include "List.h"
typedef struct City{
char name[20];
List* neighbors;
int x;
int y;
int disFromStart;
int distToGoal;
struct City* link;
}City;

typedef struct Neighbor{
int distance;
char name[20];
struct City* city;
}Neighbor;

int cmpcity(void*city1, void*city2);

void displaycity(void*city);

int cmpneighbor(void*nb1, void*nb2);

int cmpname(void*nb1, void*nb2);

//add all neighboring cities of a city into open list and set the new city's back pointer to the target city
void addopen(List* open,List* closed, City* city,City* destination);

void voidf();


//to find a city by its name
City* byname(List* list, char name[20]);
#endif // MAP_H_INCLUDED
