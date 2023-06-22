#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @_line: Interger representing the line number of of the opcode.
 */
void add(stack_t **stack, unsigned int _line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_2(8, _line, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub - Substrac the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @_line: Interger representing the line number of of the opcode.
 */
void sub(stack_t **stack, unsigned int _line)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_2(8, _line, "sub");

	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_ - Division the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @_line: Interger representing the line number of of the opcode.
 */
void div_(stack_t **stack, unsigned int _line)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_2(8, _line, "div");

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", _line);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * mult - multiplica dos numeros
 *@stack: pointer to a top node
 *@_line: opcode line number
 */
void mult(stack_t **stack, unsigned int _line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_2(8, _line, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = sum;
}
