#include "monty.h"

/**
 * new_node - Create a new node.
 * @n: Number to host inside the node.
 * Return: On succes point to a node otherwise NULL.
 */
stack_t *new_node(int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		error_1(4);
	new->next = NULL;
	new->prev = NULL;
	new->n = n;
	return (new);
}
/**
 * free_node - Free a list.
 */
void free_node(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
