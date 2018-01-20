#include <stdio.h>
#include <stdlib.h>

enum{
	INSERTION_BEG=1,
	INSERTION_END,
	DISPLAY_LIST,
	DELETE_BEG,
	DELETE_END,
	EXIT=10
};

struct ListNode {
	int data;
	struct ListNode *next;
};

/*========================Function Declarations==================================*/
void InsertAtBeginInCLL(struct ListNode**, int);
void InsertAtEndInCLL(struct ListNode **, int);
void DeleteAtBeginInCLL(struct ListNode **);
void DeleteAtEndInCLL(struct ListNode **);
void DisplayCLL(struct ListNode *);
//void DeleteEndNodeCircularLinkList(struct ListNode **, int);

int main()
{
	struct ListNode *startNode;
	while (1){
		int choice;
		printf("Enter the choice\n");
		printf("Press 1 for Insertion in the starting\n");
		printf("Press 2 for Instertion in the End\n");
		printf("Press 3 for Display\n");
		printf("Press 4 for Deletion in the starting\n");
		printf("Press 5 for Deletion in the End\n");
		printf("Press 10 for Exit\n");
		scanf("%d", &choice);

		switch (choice){
		
		case INSERTION_BEG:
		{
			int data;
			printf("Enter the data\n");
			scanf("%d", &data);
			InsertAtBeginInCLL(&startNode, data);
		}
		break;
		case INSERTION_END:
		{
			int data;
			printf("Enter the data\n");
			scanf("%d", &data);
			InsertAtEndInCLL(&startNode, data);
		}
		break;
		case DISPLAY_LIST:
			DisplayCLL(startNode);
		break;
		case DELETE_BEG:
		{
			DeleteAtBeginInCLL(&startNode);
		}
		break;
		case DELETE_END:
		{
			DeleteAtEndInCLL(&startNode);
		}
		break;
		case EXIT:
			//DeleteLinkList(startNode);
			return 0;

		default :
			printf("This is not a valid option\n");
		}
	}
	return 0;
}
/*========================Insertion At the begining==================================*/
void InsertAtBeginInCLL(struct ListNode **startNode, int data)
{
	struct ListNode *new, *loopNode;
	
	new = (struct ListNode *)malloc(sizeof(struct ListNode));
	new->data = data;
	loopNode = *startNode;

	if (*startNode == NULL){
		*startNode = new;
		(*startNode)->next = *startNode;
	} else {
		while (loopNode->next != *startNode)
			loopNode = loopNode->next;
		loopNode->next = new;
		new->next = *startNode;
		*startNode = new;
	}
}

/*========================Insertion in the End==================================*/
void InsertAtEndInCLL(struct ListNode **startNode, int data)
{
	struct ListNode *newNode, *loopNode;
	
	newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->data = data;
	loopNode = *startNode;

	if (*startNode == NULL){
		printf("List is empty\n");
		return ;
	} 
	while (loopNode->next != *startNode)
		loopNode = loopNode->next;
	loopNode->next = newNode;
	newNode->next = *startNode;
}

/*========================Delete At the begining==================================*/
void DeleteAtBeginInCLL(struct ListNode **startNode)
{
	struct ListNode *tempNode, *loopNode;
	
	loopNode = *startNode;

	if (*startNode == NULL){
		printf("List is empty\n");
		return ;
	} 
	while (loopNode->next != *startNode)
		loopNode = loopNode->next;
	tempNode = loopNode->next;
	loopNode->next = (*startNode)->next;
	*startNode = (*startNode)->next;
	free(tempNode);
	tempNode = NULL;
}

/*========================Delete At the End==================================*/
void DeleteAtEndInCLL(struct ListNode **startNode)
{
	struct ListNode *tempNode, *loopNode;
	
	loopNode = *startNode;

	if (*startNode == NULL){
		printf("List is empty\n");
		return ;
	} 
	while (loopNode->next->next != *startNode)
		loopNode = loopNode->next;
	tempNode = loopNode->next;
	loopNode->next = *startNode;
	free(tempNode);
	tempNode = NULL;
}

/*========================Display==================================*/
void DisplayCLL(struct ListNode *startNode)
{
	struct ListNode *loopNode;
	if (startNode == NULL){
		printf("List is empty\n");
		return ;
	}
	loopNode = startNode;
	do{
		printf("%d ", loopNode->data);
		loopNode = loopNode->next;
	}while(loopNode != startNode);
	printf("\n");
}
