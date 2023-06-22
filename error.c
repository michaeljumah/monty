#include "monty.h"
/**
 * error_1 - Prints error messages.
 * @error_code: The error codes are the following.
 */
void error_1(unsigned int error_code, ...)
{
	va_list a;
	char *op_error;
	unsigned int line_count;

	va_start(a, error_code);

	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(a, char *));
			break;
		case 3:
			line_count = va_arg(a, unsigned int);
			op_error = va_arg(a, char *);
			fprintf(stderr, "L%u: unknown instruction %s\n", line_count, op_error);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%u: usage: push integer\n", va_arg(a, unsigned int));
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * error_2 - Handles errors.
 * @error_code: The error codes are the following.
 */
void error_2(unsigned int error_code, ...)
{
	va_list a;
	char *op_error;
	unsigned int _line;

	va_start(a, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%u: can't pint, stack empty\n",
					va_arg(a, unsigned int));
			break;
		case 7:
			fprintf(stderr, "L%u: can't pop an empty stack\n",
					va_arg(a, unsigned int));
			break;
		case 8:
			_line = va_arg(a, unsigned int);
			op_error = va_arg(a, char *);
			fprintf(stderr, "L%u: can't %s, stack too short\n", _line, op_error);
			break;
		case 9:
			_line = va_arg(a, unsigned int);
			op_error = va_arg(a, char *);
			fprintf(stderr, "L%u: can't div %s, stack too short \n",
					_line, op_error);
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}
