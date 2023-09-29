#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * factorize - factorizing a number.
 * @num: number to factorize
 *
 * Return: Return succes or failure.
 */
void factorize(int num)
{
	printf("%d=", num);
	int divisor = 2;
	while (num > 1)
	{
		if (num % divisor == 0)
		{
			printf("%d", divisor);
			num /= divisor;
			if (num > 1)
			{
				printf("*");
			}
		}
		else
		{
			divisor++;
		}
	}
	printf("\n");
}

/**
 * main - main argument.
 * argc: argument count.
 * argv: argument vector.
 * Return: return success or failure.
 */
int main(int argc, char *argv[])
{
	int num;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	while (fscanf(file, "%d", &num) != EOF)
	{
		factorize(num);
	}

	fclose(file);

	return (0);
}
