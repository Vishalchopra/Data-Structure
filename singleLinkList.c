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
	PRINT_N_FROM_END,
	PRINT_MIDDLE_NODE,
	PRINT_REVERSE,
	REVERSE_LIST,
	EXIT,
};

struct ListNode {
	int data;
	struct ListNode *next;
};

/*========================Function Declarations==================================*/
void InsertInLinkList(struct ListNode**, int, int);
void DisplayLinkList(struct ListNode *);
void DeleteNodeFromLinkList(struct ListNode **, int);
struct ListNode* MergeLists(struct ListNode *, struct ListNode*);
void PrintNthNodeFromLast(struct ListNode *, int);
void displayMiddleNode(struct ListNode *);
void reverseList(struct ListNode **);
void printReverseList(struct ListNode *);

//=======================Print List in reverse order======================
void printReverseList(struct ListNode *head)
{
	if (head == NULL){
		return;
	}
	printReverseList(head->next);
	printf("%d---->", head->data);
}


/*==========================Reverse Linklist========================*/
void reverseList(struct ListNode **head)
{
	struct ListNode *next, *prev, *head1;
	prev = NULL;
	head1= *head;
	if (!head){
		printf("List is empty");
		return;
	}

	while(head1->next){
		next = head1->next;
		head1->next = prev;
		prev = head1;
		head1 = next;
	}
	head1->next = prev;
	*head = head1;

}

//==========================Middle Node=============================
void displayMiddleNode(struct ListNode *head)
{
	struct ListNode *loopNode;
	if (head == NULL){
		printf("List is empty. Please insert new node and try again\n");
		return;
	}
	DisplayLinkList(head);
	loopNode = head;
	while(loopNode->next && loopNode->next->next){
		head = head->next;
		loopNode = loopNode->next->next;
	}

	if (!loopNode->next)
		printf("\nOdd numbers of nodes present in linklist\n");
	else
		printf("\nEven numbers of nodes present in linklist\n");

	printf("\nMiddle node of linklist is %d at address = %p\n", head->data, head);
}

int main()
{
	struct ListNode *startNode = NULL;
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
		printf("Press 8 for Print nth node from end\n");
		printf("Press 9 for Print nth node from end\n");
		printf("Press 10 for Print in reverse order\n");
		printf("Press 11 for Reverse LinkList\n");
		printf("Press 12 for Exit\n");
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
		case PRINT_N_FROM_END:
		{
			int n;
			printf("Enter the node you want to print\n");
			scanf("%d", &n);
			PrintNthNodeFromLast(startNode, n);
		}
		break;
		case PRINT_MIDDLE_NODE:
			displayMiddleNode(startNode);
		break;
		case PRINT_REVERSE:
			printReverseList(startNode);	
		break;
		case REVERSE_LIST:
			reverseList(&startNode);
		break;
		case EXIT:
			printf("Need to improve more come back again\n");
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
	if (position == INSERTION_BEG){
		new->next = *startNode;
		*startNode = new;
		return ;
	}
	
	if (*startNode == NULL){
		printf ("List is empty\n");
		return ;
	}
	p = *startNode;
	if (position == INSERTION_POS){
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
	if (position == DELETE_BEG){
		(*head) = (*head)->next;
		free(p);
		p = NULL;
		return ;
	}

	if (position == DELETE_POS){
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
		while (p->next != NULL && p->next->next != NULL){
			p = p->next;
		}
	}


	q = p->next;
	if (q == NULL){
		free (*head);
		(*head) = NULL;
		return ;
	}
	p->next = q->next;
	free (q);
	q = NULL;
}

/*========================Merge two sorted array==================================*/
struct ListNode* MergeLists(struct ListNode *headA, struct ListNode* headB)
{
    struct ListNode *temp1, *temp2, *temp, list;
    temp = &list;
    temp1 = headA;
    temp2 = headB;
    while (1){
        if (temp1 && (temp2 == NULL || temp1->data <= temp2->data)){
                temp->next = (struct ListNode *)malloc(sizeof(*temp));
                temp->next->data = temp1->data;
                temp = temp->next;
                temp1 = temp1->next;
            } else if(temp2){
                temp->next = (struct ListNode *)malloc(sizeof(*temp));
                temp->next->data = temp2->data;
                temp = temp->next;
                temp2 = temp2->next;
            }
            
        if (!temp1 && !temp2)
            break;
    }
    temp = list.next;
    return temp;
}


/*========================Print nth Node from end==================================*/
void PrintNthNodeFromLast(struct ListNode *start, int n)
{
	struct ListNode *temp;
	if (start == NULL){
		printf("List is empty\n");
		return;
	}
	int count = 1;
	temp = start;
	
	while (count < n){
		temp = temp->next;
		if (temp == NULL){
			printf("%d is greater than the length of the Linklist\n", n);
			return ;
		}
		count++;
	}
	while (temp != NULL){
		if (temp->next == NULL){
			printf("%d is %d node from the last node\n", start->data, n);
			return;
		}
		start = start->next;
		temp = temp->next;
	}

}
/*void DeleteNode(struct ListNode **head)
{
	struct ListNode
}*/
