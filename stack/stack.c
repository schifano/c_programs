/* 
	Name: Rachel A Schifano
	Description: Program that implements a stack with an array of ints.
 */

#include "dslib.h"
#include <stdlib.h>

// Initialize the stack struct
void stack_init(stack *s, int capacity) {
	s->stack_ptr = malloc(capacity*sizeof(int));
	s->size = capacity;
	s->elements = 0;  
}


// Returns the size of the stack; the number of elements in the array
int stack_size(stack *s) {
	return s->elements;
}

/* Returns the integer element on top of the stack.
   If the stack is empty, the return value is undefined. */ 
int stack_pop(stack *s) {
	if (s->elements == 0) {
		return 0;	
	}
	s->elements--;
	return s->stack_ptr[s->elements+1];
}

/* If the stack is not full, pushes the item on top of the stack. 
   Otherwise, do nothing. */
void stack_push(stack *s, int e) {
	if (s->elements+1 > s->size) {
		// do nothing
	}
	else {
		s->stack_ptr[s->elements+1] = e;
		s->elements++;
	}
}

// Frees this stack.
void stack_deallocate(stack *s) {
	free(s->stack_ptr);
}

