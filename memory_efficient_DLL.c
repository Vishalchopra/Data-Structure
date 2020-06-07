#include <stdio.h>
#include <stdlib.h>

//enum for operations
enum {
	INSERTION_BEG=1,
	TRAVERSE,
	REVERSE_TRAVERSE,
	INSERTION_END,
	INSERTION_POS,
	DELETE_FULL,
	EXIT=10,
};

//structure declaration
struct node {
	int data;
	struct node *link;
};
//Function declarartion
void func_master();
void InsertInLinkList(struct node **, int, int);
struct node *nextNode(struct node *, struct node *);
void traverse(struct node *);
void reverse_traverse(struct node *);

int main()

{
	func_master();

}

void func_master()
{
	int choice=1;
	struct node *head = NULL;
	while(choice){
		printf("Enter your choice\n");
		printf("Press 1 for Insertion at the dawning\n");
		printf("Press 2 for traversing link list\n");
		printf("Press 3 for reverse traversing from a particular node number\n");
		printf("Press 4 for Insertion at the end\n");
		printf("Press 5 for Insertion at the given position\n");
		printf("Press 10 for EXIT\n");

		scanf("%d", &choice);
		switch (choice){
			case INSERTION_BEG:
			case INSERTION_END:
			case INSERTION_POS:	
			{
				int data;
				printf("Enter the data\n");
				scanf("%d", &data);
				InsertInLinkList(&head, data, choice);
			}
			break;
			case TRAVERSE:
				traverse(head);
			break;
			case REVERSE_TRAVERSE:
				reverse_traverse(head);
			break;

			case EXIT:
				delete_all(head);
				choice = 0;
				
			break;
			default:
				printf("Enter a valid option\n");
				

		
		}
	
	}

}

struct node *nextNode(struct node *node, struct node *prevNode)
{
	return (struct node *)((int)node ^ (int)node->link ^ (int)prevNode);

}

void InsertInLinkList(struct node **head, int data, int choice)
{
	struct node *new, *next;
	new = (struct node *)malloc(sizeof(struct node));

	if (NULL == new){
		perror("malloc");
		return ;
	}
	
	new->data = data;
	new->link = NULL;

	if (!(*head)){
		new->link = new;
		(*head) = new;
	}
	else {
		if (INSERTION_BEG == choice){

			
			next = (struct node *)(((int)(*head)->link) ^ (int)(*head));
			if (next)
				printf("next = %x   next->data = %p\n", next, next);
			new->link = (struct node *)((int)new ^ (int)new->link ^ (int)(*head));
			(*head)->link =(struct node *)( (int)next ^ (int)(*head) ^ (int)new );//next node XOR current head XOR new head
			(*head) = new;
			return;	
		}else if(INSERTION_END == choice){
			struct node *next, *prev, *loop_node;
			loop_node = (*head);
			prev = NULL;

			if (loop_node == NULL){
				printf("List is Empty\n ");
				return;
			}

			while (loop_node){
				printf("%d----->", loop_node->data);
				//next = (struct node *)((int)(loop_node->link) ^ (int)loop_node ^  (int)prev);
				next = nextNode(loop_node, prev);
				if (NULL == next)		// When next node is NULL break;
					break;
				prev = loop_node;
				loop_node = next;
			}
			new->link = (struct node *)((int)new ^ (int)loop_node ^ (int)next); //update last node address
			loop_node->link = (struct node *)((int)loop_node ^ (int)new ^ (int)prev); //Update the earlier last node address
		
		}else{
			struct node *next, *prev, *loop_node, *prev_prev_node, *next_head_node;
			int pos = 0;
			loop_node = (*head);
			prev = NULL;

			if (loop_node == NULL){
				printf("List is Empty\n ");
				return;
			}
			printf("Enter the position where you want to INSERT node, value should be greater than 1\n");
			scanf("%d", &pos);
			if (pos <= 1){
				printf("You have entered wrong position\n");
				return;
			}
			pos--;
			while (pos--){
				printf("Inwhile");
				if (loop_node == NULL){
					printf("Number of node in Doubly linklist is less than number you have entered\n");
					return;
				}
				printf("%d----->", loop_node->data);
				//next = (struct node *)((int)(loop_node->link) ^ (int)(loop_node) ^  (int)prev);
				next = nextNode(loop_node, prev);
				prev = loop_node;
				loop_node = next;
			}
			new->link = (struct node *)((int)new ^ (int) prev ^ (int)loop_node);//  update the new node link with XOR of its, next and prev nodes.			
			prev_prev_node = nextNode(prev, loop_node);
			//prev_prev_node = (struct node *)((int)prev->link ^ (int)prev ^ (int)loop_node); // extracting the address of node present before prvious node
			next_head_node = nextNode(loop_node, prev);
			//next_head_node = (struct node *)((int)(loop_node->link) ^ (int)loop_node ^ (int)prev );//extract address of node next to current head node so that we can update address of head node by XORing new node, head and next node.
			prev->link = (struct node *)((int)prev_prev_node ^ (int)prev ^ (int)new);//update the address of the node after which new node is added.
			loop_node->link = (struct node *)((int)loop_node ^ (int)new ^ (int)next_head_node );
		}

	}

}

void traverse(struct node *head)
{
	struct node *next, *prev;
	prev = NULL;

	if (head == NULL){
		printf("List is Empty\n ");
		return;
	}

	while (head){
		printf("%d----->", head->data);
		next = (struct node *)((int)(head)->link ^ (int)head ^  (int)prev);
		prev = head;
		head = next;
	}
	printf("\n");


}

void reverse_traverse(struct node *head)
{
	struct node *next, *prev;
	unsigned int node_number = 0;
	prev = NULL;

	if (head == NULL){
		printf("List is empty. Please Enter few node then try\n");
		return;
	}

	printf("Enter from which node you want to traverse back\n");
	scanf("%d", &node_number);

	if (node_number == 0){
		printf("Please Enter a number greater than 0\n");
		return;
	}
	if (1 == node_number){
		printf("%d---->reverse----->%d\n",head->data, head->data);
		return;
	}
	
	while (node_number--){
		if (head == NULL){
			printf("Number of node in Doubly linklist is less than number you have entered\n");
			return;
		}
		printf("%d----->", head->data);
		next = nextNode(head, prev);
		//next = (struct node *)((int)(head)->link ^ (int)head ^  (int)prev);
		prev = head;
		head = next;
		
	}

		next = head; 
		head = prev;
		prev = next;
	while(head){
		next = nextNode(head, prev);
		//next = (struct node *)((int)(head)->link ^ (int)head ^  (int)prev);
		if (next == NULL)
			break;
		prev = head;
		head = next;
		printf("%d----->", next->data);
	}
	printf("\n");
}


void delete_all(struct node *head)
{
/*	struct node *next, *next_to_next, *prev;
	prev = NULL;
	if (head == NULL){
		printf("Everything is alread sorted\n");
		return;
	}

	while (head){
		next = nextNode(head, prev);
		if (!next)
			break;
		next_to_next = nextNode(next, head);
		
	}
	free(head);
	head = NULL;
	if (prev){
		free(prev);
		prev = NULL;
	}
*/
}
