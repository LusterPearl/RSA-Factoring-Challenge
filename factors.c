#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - factorization of number into p and q.
 * @n: number n into p and q.
 * Return: return success or failure.
 */
void factorize(int n)
{
	int p = 2;
	
	while (p < n)
	{
		if (n % p == 0)
		{
			int q = n / p;
			printf("%d=%d*%d\n", n, p, q);
			return;
		}
		p++;
	}
}

/**
 * main - main function
 * @argc: argument count.
 * @argv: argument vector
 * Return: return success or failure
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	int num;
	fclose(file);

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	while (fscanf(file, "%d\n", &num) == 1)
	{
		printf("Processing number: %d\n", num);
		factorize(num);
	}
	return (0);
}
