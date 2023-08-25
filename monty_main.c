#include "monty.h"
/**
 * main - start point
 * @argc: arg counter
 * @argv: arg vector
 * Return: success || failure
 */
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		 /*output  usage error*/

		usage_error();
	}
	else
	{
		/** read file and execute */
		execute(argv[1]);
	}

	return (EXIT_SUCCESS);

}
