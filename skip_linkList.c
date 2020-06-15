#include <stdio.h>
#include <stdlib.h>

#define MAXSKIPLEVEL 5

//Structure declaration
struct listnode{
	int data;
	struct listnode *next[1];
	
};

struct skiplist{
	struct listnode *header;
	int listLevel;
}list;
////Function prototype
void initList();
int insertElement(int);
void listTraverse();


int insertElement(int data)
{
	printf("insertElement\n");
	int i, newLevel;
	struct listnode *update[MAXSKIPLEVEL + 1];
	struct listnode *temp;
	temp = list.header;

	for (i = list.listLevel; i >=0; i--){
		while(temp->next[i] != list.header && temp->next[i]->data < data)
			temp = temp->next[i];
		update[i] = temp;
	}

	temp = temp->next[0];
	if (temp != list.header && temp->data == data)
	{
		return temp;
	}

	for (newLevel = 0; rand() < RAND_MAX/2 && newLevel< MAXSKIPLEVEL; i++);

	if (newLevel > list.listLevel){
		for(i = list.listLevel + 1; i <= newLevel; i++)
			update[i] = list.header;
		list.listLevel = newLevel;
	}

	temp = (struct listnode *)malloc(sizeof(struct listnode) + newLevel*sizeof(struct listnode *));

	temp->data = data;
	for(i = 0; i <= newLevel; i++){
		temp->next[i] = update[i]->next[i];
		update[i]->next[i] = temp;
	}

}

void initList()
{
	printf("initList\n");
	int loopVar;
	list.header = (struct listnode *)malloc(sizeof(struct listnode)) + ( MAXSKIPLEVEL * sizeof(struct listnode *));
	if (NULL == list.header){
		perror("malloc");
		exit(1);
	}

	for(loopVar = 0; loopVar <= MAXSKIPLEVEL; loopVar++)
		list.header->next[loopVar] = list.header;
	list.listLevel = 0;
}

void listTraverse()
{
	int i;
	struct listnode *temp = list.header;
	printf("listTraverse\n");
		while(temp && temp->next[0] != list.header){
		//while(temp ){
			printf("%d-->", temp->next[0]->data);
			temp = temp->next[0];
		}
}

int main()
{
	initList();
	insertElement(2);
	listTraverse();
	insertElement(8);
	listTraverse();
	return 0;
}
