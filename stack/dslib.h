/* 
	Name: Rachel A Schifano
	Professor: Dr. Suh
	Course: IT 383
	Program: 0
	Header File
 */

// Declare a struct
typedef struct stack {
	int size;
	int elements;
	int *stack_ptr;
} stack;

// Initializes the stack that stores integers with maximum size capacity
void stack_init(stack *s, int capacity);

// Returns the size of the stack; the number of elements in the array
int stack_size(stack *s);

/* Returns the integer element on top of the stack.
   If the stack is empty, the return value is undefined. */ 
int stack_pop(stack *s);

/* If the stack is not full, pushes the item on top of the stack.
   Otherwise, do nothing. */
void stack_push(stack *s, int e);

// Frees this stack.
void stack_deallocate(stack *s);
