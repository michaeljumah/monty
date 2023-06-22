#include "monty.h"
/**
 * opfile - Open file.
 * @file_name: String with the name of the file.
 */
void opfile(char *file_name)
{
	int file_check;
	FILE *fd;

	if (file_name == NULL)
		error_1(2, file_name);

	file_check = access(file_name, R_OK);
	if (file_check == -1)
		error_1(2, file_name);
	fd = fopen(file_name, "r");
	if (fd == NULL)
		error_1(2, file_name);
	r_file(fd);

	fclose(fd);
}
/**
 * r_file - Read the content.
 * @fd: Pointer 2 a file descriptor
 */
void r_file(FILE *fd)
{
	int _line;
	int format = 0;
	char *buffer = NULL;
	size_t n = 0;

	if (fd == NULL)
		error_1(2, "file_name");
	/*Read line by line*/
	for (_line = 1; getline(&buffer, &n, fd) != EOF; _line++)
	{
		format = int_line(buffer, _line, format);
	}
	free(buffer);
}
/**
 * int_line - Interpret each line by separating it one by one.
 * @string: String on the line 2 be read.
 * @_line: Line number 4 the opcode.
 * @format: Format specifier is 0 for Stack 1 for Queue
 * Return: Returns 0 if the opcode is stack or 1 if Queue.
 */
int int_line(char *string, int _line, int format)
{
	char *op_code;
	char *cmd;
	const char *del;

	del = "\n ";

	if (string == NULL)
		error_1(4);

	op_code = strtok(string, del);

	if (op_code == NULL)
		return (format);

	cmd = strtok(NULL, del);
	if (strcmp(op_code, "queue") == 0)
		return (1);
	else if (strcmp(op_code, "stack") == 0)
		return (0);

	search_func(op_code, cmd, _line, format);
	return (format);
}
