#include "monty.h"

/**
 * swap - Swap element 1 for element 2 of the stack.
 * @stack: Points to the top node of the stack.
 * @_line: Opcode line number.
 */
void swap(stack_t **stack, unsigned int _line)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_2(8, _line, "swap");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * nop - Does nothing.
 * @stack: Top of the stack.
 * @_line: Current line number.
 */
void nop(stack_t **stack, unsigned int _line)
{
	(void)*stack;
	(void)_line;
}
