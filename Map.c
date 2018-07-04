#include <stdio.h>
#include "List.h"
#include "Map.h"
#include <math.h>
 int cmpcity(void*city1, void*city2) {
	return strcmp((char*)(((City*)city1)->name),(char*)(((City*)city2)->name));
}

 void displaycity(void*city) {
	printf("%s", ((City*)city)->name);
}

 int cmpneighbor(void*nb1, void*nb2) {
	Neighbor* n1 = (Neighbor*)nb1;
	Neighbor* n2 = (Neighbor*)nb2;

	return strcmp((char*)n1->name,(char*)n2->name);
}

 int cmpname(void*nb1, void*nb2) {
	return strcmp((char*)nb1, (char*)nb2);

}

//add all neighboring cities of a city into open list and set the new city's back pointer to the target city
void addopen(List* open, List* closed,City* city, City* destination) {

	Node* node = city->neighbors->head;

	while (node) {

		City* current = ((Neighbor*)(node->val))->city;
		if (isInList(open, current )== 0&&isInList(closed,current)==0) {

			current->link = city;
			int distance = ((Neighbor*)(node->val))->distance;
			current->disFromStart = distance + city->disFromStart;
			current->distToGoal = abs(current->x - destination->x)+abs(current->y - destination->y);
			addList(open, current);
		}
		node = node->next;
	}

}


 void voidf() {
}


//to find a city by its name
City* byname(List* list, char name[20]) {

	Node * tmp = list->head;
	for (int i = 1; i<list->nelts + 1; i++) {
            City* res=(City*)(tmp->val);

		if ((strcmp(name, res->name)) == 0) {

			return res;
		}
		else tmp = tmp->next;
	}
printf("can't find city");
	return 0;
}
