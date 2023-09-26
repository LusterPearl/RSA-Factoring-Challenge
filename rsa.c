#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * is_prime - to check if number is prime
 * @num: number is prie or not
 * Return: false or True
 */
bool is_prime(long long num)
{
	if (num <= 1) return false;
	if (num <= 3) return true;
	if (num % 2 == 0 || num % 3 == 0) return false;

	for (long long i = 5; i * i <= num; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
		{
			return (false);
		}
	}
	return (true);
}

/**
 * factorize_rsa - factorize number into prime p and q.
 * @n: number n into prime factors
 * Return: 0 or 1.
 */
void factorize_rsa(long long n)
{
	for (long long p = 2; p <= n; p++)
	{
		if (n % p == 0 && is_prime(p))
		{
			long long q = n / p;
			if (is_prime(q))
			{
				printf("%lld=%lld*%lld\n", n, p, q);
				return;
			}
		}
	}
	printf("No prime factorization found for %lld\n", n);
}

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1.
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	long long num;
	fclose(file);

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return(1);
	}

	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	for (int i = 0; fscanf(file, "%lld\n", &num) == 1; i++)
	{
		factorize_rsa(num);
	}
		return (0);
}
