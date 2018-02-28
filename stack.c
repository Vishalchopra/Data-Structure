#include <stdio.h>
#include <stdlib.h>

enum {
	CREATE=1,
	PUSH,
	POP,
	EXIT
};

struct stack {
	int top;
	int capacity;
	int *array;
};
/*******************************Function Declaration********************/
void create_stack(struct stack **);
void push(struct stack *, int);
int IsStackFull(struct stack *);
void DoubleStack(struct stack *);
int pop(struct stack *);
int IsStackEmpty(struct stack *);

int main()
{
	struct stack *stack_top;
	while (1){
		int choice;
		printf("Enter your choice\n");
		printf("Press 1 to create stack\n");
		printf("Press 2 to push stack\n");
		printf("Press 3 to pop stack\n");
		printf("Press 4 to delete stack\n");
		scanf("%d", &choice);
		printf("\n\n\n\n");

		switch (choice){
		case CREATE:
			create_stack(&stack_top);
		break;

		case PUSH:
		{
			int data;
			printf ("Enter the data\n");
			scanf ("%d", &data);
			push(stack_top, data);
		}
		break;
		case POP:
		{
			printf ("Pop from the stack %d\n", pop(stack_top));
		}
		break;
		}
		
	}
	return 0;
}

/*******************************Function to create stack********************/
void create_stack(struct stack **stack_top)
{
	*stack_top = (struct stack *)malloc(sizeof(*stack_top));
	if (!*stack_top){
		perror("malloc");
		return;
	}
	(*stack_top)->capacity = 1;
	(*stack_top)->top = -1;

	(*stack_top)->array = (int *)malloc(sizeof(int)* ((*stack_top)-> capacity));

	if (!(*stack_top)->array){
		perror("malloc");
		return;
	}
}

/*******************************Function to PUSH********************/
void push(struct stack *stack_top, int data)
{
	if (IsStackFull(stack_top)){
		DoubleStack(stack_top);
	}
	stack_top->array[++stack_top->top] = data;
}

/*******************************Function to POP********************/
int pop(struct stack *stack_top)
{
	if(IsStackEmpty(stack_top))
		return -1;
	return stack_top->array[stack_top->top--];
}


int IsStackFull(struct stack *stack_top)
{
	return (stack_top->top == (stack_top->capacity - 1));
}
int IsStackEmpty(struct stack *stack_top)
{
	return stack_top->top == -1;
}

void DoubleStack(struct stack *stack_top)
{
	stack_top->capacity *= 2;
	stack_top->array = (int *)realloc(stack_top->array, stack_top->capacity);
}
