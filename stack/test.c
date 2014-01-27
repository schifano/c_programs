/* 
	Name: Rachel A Schifano
	Professor: Dr. Suh
	Course: IT 383
	Program: 0
	Description: File that tests all operations of the stack from stack.c
 */

#include <stdio.h>
#include "dslib.h"

int main() {

	struct stack my_stack;
	stack_init(&my_stack, 2); // Initialize stack

	printf("Elements: %i\n",stack_size(&my_stack)); // Elements: 0

	stack_push(&my_stack,33); // Add 1 element
	printf("Number of elements should be 1: %i\n",stack_size(&my_stack)); // 1
	printf("Pop out a 33: %i\n",stack_pop(&my_stack)); // 33

	stack_push(&my_stack,33);
	stack_push(&my_stack,66);
	printf("Number of elements should be 2: %i\n",stack_size(&my_stack)); // 2
	printf("Pop out a 66: %i\n",stack_pop(&my_stack)); // 66

	stack_push(&my_stack,66); // re-push 66 so that there are two elements
	stack_push(&my_stack,99); // add another element to exceed capacity
	printf("Number of elements should STILL be 2 since exceeding capcity does nothing: %i\n",
		stack_size(&my_stack)); //2

	stack_deallocate(&my_stack); // deallocate memory

	// pop the only two elements in stack
	stack_pop(&my_stack);
	stack_pop(&my_stack);
	printf("Number of elements should be 0: %i\n",stack_size(&my_stack)); // 0

	// pop an element when there is nothing in the array
	stack_pop(&my_stack);
	printf("Number of elements should still be 0: %i\n",stack_size(&my_stack));

	puts("Programming in C is cool!"); // Yay

	return 0;
}
