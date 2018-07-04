#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Map.h"
#include <string.h>
#include <math.h>

int main(int nwords,char* words[])
{
    //check if the parameters are 3
    if (nwords != 3) {
        printf("usage:Astar depart destination");
        return 1;
    }

    //put every city and neighbor in their list
List * map = newList(cmpcity,displaycity);
List *neighbors = newList(cmpneighbor,voidf);


FILE *france;
Neighbor* cneighbor;
int inumbers;
char cityname[20];
char nametmp[20];
int x;
int y;
france = fopen("FRANCE.MAP","r");
if (france==0){
    printf("fail");
}
else{
while( (inumbers = fscanf(france,"%s %d %d",&cityname,&x,&y))!=EOF){

    if (inumbers == 3){
            City* city= (City*)malloc(sizeof(City));
        strcpy(city->name,cityname);
        strcpy(nametmp,cityname);
        city->x=x;
        city->y=y;
		city->disFromStart = 10000;
		city->neighbors=newList(cmpneighbor,voidf);
    addList(map,city);

    }
    else if(inumbers == 2){
        Neighbor* neighbor = (Neighbor*)malloc(sizeof(Neighbor));


            neighbor->distance = x;

            neighbor->city =0;

            strcpy(neighbor->name,cityname);

          //  addList(neighbors,neighbor);
 City* city = byname(map,nametmp);
 addList(city->neighbors,neighbor);


    }
    else printf("error");

}
}

//find the related city and make the neighbor->city pointer point to it

char resname[20];
City* rescity;
Neighbor* currentneighbor;
 for(int i=1;i<map->nelts+1;i++){
        nthInList(map,i,&rescity);
   for(int j=1;j<rescity->neighbors->nelts+1;j++){
        nthInList(rescity->neighbors,j,&currentneighbor);
        strcpy(resname,currentneighbor->name);
            currentneighbor->city=byname(map,resname);
        }
    }


//A* algorithm

City* depart = byname(map,words[1]);
City* destination = byname(map,words[2]);
City* current = depart;
List* open = newList(cmpcity,displaycity);
List* closed = newList(cmpcity,displaycity);
City* tmpcity;
if (depart==0||destination==0) return 1;
addList(open,current);
current->disFromStart=0;

//while the destination is not found
while (isInList(closed,destination)==0){

    if (lengthList(open)==0) return 1;

  Node * tmpnode = current->neighbors->head;
  Neighbor* tmpneighbor;

//relink the back pointers by new g value
  while (tmpnode) {
	  tmpneighbor = (Neighbor*)(tmpnode->val);
      tmpcity = (City*)(tmpneighbor->city);
	  int distance = current->disFromStart + tmpneighbor->distance;
	  if (tmpcity->disFromStart > distance) {
		  tmpcity->disFromStart = distance;
		  tmpcity->link = current;

	  }
	  tmpnode=tmpnode->next;
  }
  //check the open list and find the city with smallest f (distance to goal)
//displayList(open);
  tmpnode = open->head;
    int distance = 10000;
  while (tmpnode) {
	  City* tmpc=(City*)(tmpnode->val);
	  if (tmpc->distToGoal < distance) {
		  distance = tmpc->distToGoal;

		  tmpcity= tmpc;
	  }
		  tmpnode = tmpnode->next;

  }

  current = tmpcity;

    addopen(open,closed,current,destination);

    remFromList(open,current);

    addList(closed,current);
}
printf("***************************************************************************\n\n");
printf("the distance from the start and the destination is %d\n\n", current->disFromStart);
printf("***************************************************************************\n\n");
printf("you will pass by");
while(current!=depart){
printf(" %s",current->name);
current = current->link;
}
printf(" %s\n",depart->name);
printf("***************************************************************************\n\n");
printf("thank you for using\n\n");
printf("***************************************************************************\n");
return 0;
}

