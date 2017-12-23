#include <stdio.h>
#include <stdlib.h>

enum{
	INSERTION_BEG=1,
	INSERTION_POS,
	INSERTION_END,
	DISPLAY_LIST,
	DELETE_BEG,
	DELETE_POS,
	DELETE_END,
	EXIT=10
};

struct ListNode {
	int data;
	struct ListNode *next;
};

/*========================Function Declarations==================================*/
void InsertInLinkList(struct ListNode**, int, int);
void DisplayLinkList(struct ListNode *);
void DeleteNodeFromLinkList(struct ListNode **, int);

int main()
{
	struct ListNode *startNode;
	while (1){
		int choice;
		printf("Enter the choice\n");
		printf("Press 1 for Insertion in the starting\n");
		printf("Press 2 for Instertion in any postion\n");
		printf("Press 3 for Instertion in the End\n");
		printf("Press 4 for Display\n");
		printf("Press 5 for Deletion in the starting\n");
		printf("Press 6 for Deletion in any postion\n");
		printf("Press 7 for Deletion in the End\n");
		printf("Press 10 for Exit\n");
		scanf("%d", &choice);

		switch (choice){
		
		case INSERTION_BEG:
		case INSERTION_END:
		case INSERTION_POS:
		{
			int data;
			printf("Enter the data\n");
			scanf("%d", &data);
			InsertInLinkList(&startNode, data, choice);
		}
		break;
		case DISPLAY_LIST:
			DisplayLinkList(startNode);
		break;
		case DELETE_BEG:
		case DELETE_END:
		case DELETE_POS:
		{
			DeleteNodeFromLinkList(&startNode, choice);
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
/*========================Insertion==================================*/
void InsertInLinkList(struct ListNode **startNode, int data, int position)
{
	struct ListNode *new, *p;
	
	new = (struct ListNode *)malloc(sizeof(struct ListNode));
	new->data = data;
	if (position == 1){
		new->next = *startNode;
		*startNode = new;
		return ;
	}
	
	if (*startNode == NULL){
		printf ("List is empty\n");
		return ;
	}
	p = *startNode;
	if (position == 2){
		int pos;
		printf ("Enter the postion\n");
		scanf("%d", &pos);
		pos--;
		while (--pos){
			if (p == NULL){
				printf("Number of node in list is less\n");
				return ;
			}
			p = p->next;
		}
	}else{
		while (p->next != NULL){
			p = p->next;
		}
	}
	
	new->next = p->next;
	p->next = new;
}

/*========================Display==================================*/
void DisplayLinkList(struct ListNode *start)
{
	if (start == NULL){
		printf("List is empty\n");
		return ;
	}
	int pos = 1;
	while (start){
		printf ("%d ", start->data);
		start = start->next;
	}
	printf("\n");
}
/*========================Delete==================================*/
void DeleteNodeFromLinkList(struct ListNode **head, int position)
{
	if (*head == NULL){
		printf("List is empty\n");
		return;
	}
	struct ListNode *p, *q;
	p = *head;
	if (position == 5){
		(*head) = (*head)->next;
		free(p);
		p = NULL;
		return ;
	}

	if (position == 6){
		int pos;
		printf("Enter the position\n");
		scanf("%d", &pos);
		pos --;
		while (--pos){
			if (p == NULL){
				printf("Position is higher than the number of nodes\n");
				return;
			}
			p = p->next;
		}
	}else{
		while (p->next->next != NULL){
			p = p->next;
		}
	}


	q = p->next;
	if (q == NULL){
		p->next = q;
		free (q);
		q = NULL;
	}
	else
		p->next = q->next;
}

/*void DeleteNode(struct ListNode **head)
{
	struct ListNode
}*/
