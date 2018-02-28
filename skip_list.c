#include <stdio.h>
#include <stdlib.h>

#define MAXSKIPLEVEL 5

struct ListNode {
	int data;
	struct ListNode *next[1];
};

struct SkipList {
	struct ListNode *header;
	int listLevel;
};

struct SkipList list;

/**************************Function declaration***************************/
void initList();
void insertElement(int);

int main(int argc, char*argv[])
{
	int loopVar, *a, maxnum;
	if (argc < 2){
		printf("less number of command line arguments\n");
		exit(1);
	}
	maxnum = atoi(argv[1]);
	initList();
	a = (int *)malloc(maxnum * sizeof(*a));
	if (!a){
		printf("unable to locate memory\n");
		exit(1);
	}	

	for (loopVar = 0; loopVar < maxnum; loopVar++)
		a[loopVar] = rand();
	printf("Random %d items\n", maxnum);
	printf("%d\n", a[0]);
	insertElement(a[0]);
	free(list.header);
	list.header = NULL;
	return 0;
}

/*
 * Function Name : initList()
 * Purpose       : Create skipList and insert header in each SkipList.
 */

void initList()
{
	int loopVar;
	printf("initList() start\n");
	list.header = (struct ListNode *)malloc(sizeof(struct ListNode) + MAXSKIPLEVEL*sizeof(struct ListNode));
	if(list.header == NULL){
		printf("Memory Error\n");
		exit(1);
	}

	for(loopVar = 0; loopVar <= MAXSKIPLEVEL; loopVar++){
		list.header->next[loopVar] = list.header;
		list.listLevel = 0;	
	}
	printf("initList() end\n");
}

/*
 * Function Name : insertElement()
 * Purpose	 : insert an element in a skip list.
 */

void insertElement(int data)
{
	int i, newLevel;
	struct ListNode *update[MAXSKIPLEVEL + 1], *temp;
	temp = list.header;

	for (i = list.listLevel; i >= 0; i--){
		while (temp ->next[i] != list.header && temp->next[i]->data < data)
			temp = temp->next[i];
		update[i] = temp;
	}
	temp = temp->next[0];

	if (temp != list.header && temp->data == data)
		return(temp);

	//determine level
	for (newLevel = 0; rand() < RAND_MAX/2 && newLevel < MAXSKIPLEVEL; newLevel++);	

	if (newLevel > list.listLevel){
		for (i = list.listLevel + 1; i <= newLevel; i++)
			update[i] = list.header;
		list.listLevel = newLevel;
	}
	//make new node
	temp = (struct ListNode *)malloc(sizeof(*temp) * (newLevel + 1));
	temp->data = data;

	for (i = 0; i <= newLevel; i++){
		temp->next[i] = update[i]->next[i];
		update[i]->next[i] = temp;
	}


}
