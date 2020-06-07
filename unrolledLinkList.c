/* 
 * This linkList design to store data in incremental order
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
struct node *func_create_insert(int *, int);
void func_process();
struct node *func_create();
void func_print_choice();
void func_choice_operation(struct node *, int);

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

func_insert(struct node * head)
{
	int value;
	if (head == NULL){
		printf("List is empty\n");
		return;
	}
	printf("Enter the value you want to insert\n");
	scanf("%d", &value);
	while (head){
	
		if (head && head->next){
			if (value > head->arr[element_count] && value < head->next->arr[0]){//This will decide element 
				if (head->arr[element_count] < SIZE){// if there is any space in this node then only insert otherwise else
				
				}
			}
		}else{}
	}

}

void func_display(struct node *head)
{
	int elementCount, loopVar;
	if (head == NULL){
		printf("List is empty\n");
		return;
	}
	printf ("%d %d %d\n", head->arr[0], head->arr[1], head->arr[2]);
	elementCount = head->element_count;
	while (head){
		for (loopVar = 0; loopVar < elementCount; loopVar++){
			printf("%d ", head->arr[loopVar]);
		}

		head = head->next;
		if(head){
			elementCount = head->element_count;
			printf(" %d element count\n", elementCount);
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
