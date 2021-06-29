#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Stack
{
	int top;
	int capacity;
	int items[10];
};

int isFull(struct Stack *st)  // Stack is full when top is equal to the last index 
{
	return (st->top == st->capacity - 1);
}
int isEmpty(struct Stack *st)  // Stack is empty when top is equal to -1 
{
	return (st->top == -1);
}

void push(struct Stack *st, int item)
{
	if (isFull(st))
	{
		printf("\nStack is full \n");
		return;
	}
	st->top++;
	st->items[st->top] = item;
}

int pop(struct Stack *st)
{
	if (isEmpty(st))
		return INT_MIN;
	int temp = st->items[st->top];
	st->top--;
	return temp;
}

void printNGE(int arr[], int n)
{
	int i = 0;
	struct Stack s;
	s.top = -1;
	int element, next;

	/* push the first element to stack */
	push(&s, arr[0]);

	// iterate for rest of the elements 
	for (i = 1; i<n; i++)
	{
		next = arr[i];

		if (isEmpty(&s) == false)
		{
			element = pop(&s);
			/* If the popped element is smaller than next, then
			a) print the pair
			b) keep popping while elements are smaller and stack is not empty */
			while (element < next)
			{
				printf("\n %d --> %d", element, next);
				if (isEmpty(&s) == true)
					break;
				element = pop(&s);
			}

			/* If element is greater than next, then push the element back */
			if (element > next)
				push(&s, element);
		}

		/* push next to stack so that we can find
		next greater for it */
		push(&s, next);
	}

	/* After iterating over the loop, the remaining
	elements in stack do not have the next greater
	element, so print -1 for them */
	while (isEmpty(&s) == false)
	{
		element = pop(&s);
		next = -1;
		printf("\n %d --> %d", element, next);
	}
}
void main()
{
	int arr[] = { 11, 13, 21, 3, 4, 22, 33, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNGE(arr, n);

	_getch();
}