/* 
 * This linkList design to store data in incremental order
 * Data should be greater than one.
 * */

#include <stdio.h>
#include <stdlib.h>

//Macro
#define CAPACITY 3
#define SIZE 5
enum {
	INSERTION=1,
	DISPLAY,
};

struct node{
	int arr[SIZE];
	struct node *next;
	int element_count;
};

//Function declarartion
struct node *create_new_node();
struct node *func_create_insert(int *, int);
void func_process();
struct node *func_create();
void func_print_choice();
void func_choice_operation(struct node *, int);
void func_create_newNode_insert(struct node *, int);

struct node *func_create_insert(int *arr, int start)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(!temp){
		perror("malloc");
		return;
	}
	temp->arr[0] = arr[start];
	if (start < 9){
		temp->arr[1] = arr[start + 1];
		temp->arr[2] = arr[start + 2];
	
	}
	temp->next = NULL;
	if(start < 9)
		temp->element_count = 3;
	else
		temp->element_count = 1;
	return temp;

}

void func_shift_element(struct node *head, struct node *new)
{
	int loopVar, ec;
	for(loopVar = 1; loopVar >= 0; loopVar--){
					printf("after%d ----- %d \n", loopVar, head->arr[(head->element_count) - 1]);
		new->arr[loopVar] = head->arr[head->element_count-1];
					printf("after%d ----- %d \n", new->arr[loopVar], head->arr[head->element_count]);
					printf("before\n");
		head->arr[(head->element_count) - 1] = 0;
		head->element_count--;
		new->element_count++;

	}

}

struct node *create_new_node()
{
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	new->next = NULL;
	return new;
}
/* When array is full this function create a new node and shift the last two element of head node to
 * new node and insert the value at the third place
 */
void func_create_newNode_insert(struct node *head, int value)
{
	struct node *new = create_new_node();
	func_shift_element(head, new);
	new->arr[new->element_count] = value;
	new->element_count++;
	new->next = head->next;
	head->next = new;
	return ;
}

func_insert(struct node * head)
{
	int value, element_count;
	if (head == NULL){
		printf("List is empty\n");
		return;
	}
	printf("Enter the value you want to insert\n");
	scanf("%d", &value);
	while (head){
		element_count = head->element_count;
		if (head && head->next){

			if (value > (head->arr[element_count]) && value < (head->next->arr[0])){//This will decide element 
				// Improvment can be done here after selecting the node, need to check where to insert the element instead
				// of inserting at the end eg. according to if elements in arr are 1->2->5 if we enter 4 there is a issue.
				if (element_count < SIZE){// if there is any space in this node then only insert otherwise else
					head->arr[element_count]=value;
					(head->element_count)++;
					break ;	
				}else{//if the node's array is full then create a new node and tranfer half elments to new node
					func_create_newNode_insert(head, value);
					break;
				}
			}else{
				head=head->next;
				continue;
			}
		}else{
			if (element_count < SIZE){
				head->arr[element_count] = value;
				head->element_count++;
				break;
			}else{
				func_create_newNode_insert(head, value);
			}
		}
	}

}

void func_display(struct node *head)
{
	int elementCount, loopVar;
	if (head == NULL){
		printf("List is empty\n");
		return;
	}
	elementCount = head->element_count;
	while (head){
		printf(" %d element count\n", elementCount);
		for (loopVar = 0; loopVar < elementCount; loopVar++){
			printf("%d ", head->arr[loopVar]);
		}

		head = head->next;
		if(head){
			elementCount = head->element_count;
		}
	}
	printf("\n");
}

void func_choice_operation(struct node *head, int choice)
{
	switch(choice){
		
		case INSERTION:
			func_insert(head);
		break;
		case DISPLAY:
			func_display(head);
		break;
		default:
			printf("No functionality for this choice. Enter a Valid choice\n");
		break;

	}
}

void func_print_choice()
{
	printf("Press 1 to insert in unrolled link list\n");
	printf("Press 2 to display unrolled link list\n");
	printf("Enter your choice\n");

}

struct node *func_create()
{
	struct node *head, *loophead;
	unsigned int size, loopVar;
	int arr[10] = {1, 2, 3, 8, 9, 10, 14, 15, 16, 21};
	size = 0;
	head = func_create_insert(arr, size);
	if (!head){
		printf("Unable to create a node\n");
		return;
	}
	loophead = head;
	for (loopVar = 0; loopVar < 3; loopVar++){
			size += 3;
			loophead->next = func_create_insert(arr, size);
			loophead = loophead->next;
			printf ("%d %d %d\n", loophead->arr[0], loophead->arr[1], loophead->arr[2]);
	}


	return head;
}


void func_process()
{
	int choice, loopVar = 1;
	struct node *head;
	head = func_create();
	while(loopVar){
		func_print_choice();
		scanf("%d", &choice);
		func_choice_operation(head, choice);

	}


}

int main()
{
	func_process();

	return 0;
}
