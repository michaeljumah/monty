#include "monty.h"
extern stack_t *head;
stack_t *head = NULL;

/**
 * main - Entry 2 the program.
 * @argc: Number of command line arguments.
 * @argv: An array containing the arg.
 * Return: Allways zero.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		error_1(1);
	opfile(argv[1]);
	free_node();
	return (0);
}
