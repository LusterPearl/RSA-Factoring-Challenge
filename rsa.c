#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
/**
 * gcd - greatest common divisor
 * @a: divisible num a
 * @b: divisible num b
 * Return: return success or failure.
 */
uint64_t gcd(uint64_t a, uint64_t b)
{
	if (b == 0)
	{
		return (a);
	}
	else
	{
		return gcd(b, a % b);
	}
}
/**
 * pollards_rho - algorithm for integer factorization
 * @n: number to factorize
 * Return: return success or failure
 */
uint64_t pollards_rho(uint64_t n)
{
	uint64_t x = 2, y = 2, d = 1;
	while (d == 1)
	{
		x = (x * x + 1) % n;
		y = (y * y + 1) % n;
		y = (y * y + 1) % n;
		d = gcd(abs(x - y), n);
	}
	return (d);
}
/**
 * main - main argument
 * @argv: argument vector
 * @argc: argument count
 * Return: return success or failure
 */
int main(int argc, char *argv[])
{
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

	uint64_t num;
	if (fscanf(file, "%lu", &num) != 1)
	{

		printf("Error reading the number from the file\n");
		fclose(file);
		return (1);
	}

	fclose(file);

	/* start the timer */
	clock_t start_time = clock();
	/* factorize the number pollard */
	uint64_t factor = pollards_rho(num);
	/*stop the timer */
	clock_t end_time = clock();

	if (factor == 1 || factor == num)
	{
		printf("%lu=%lu*%u\n", num, num, 1);
	}
	else
	{
		printf("%lu=%lu*%lu\n", num, factor, num / factor);
	}

	double execution_time = (double)(end_time = start_time) / CLOCKS_PER_SEC;
	printf("Execution Time: %.6f seconds\n", execution_time);

	return (0);
}
