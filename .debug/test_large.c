/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:08:15 by anpayot           #+#    #+#             */
/*   Updated: 2025/05/05 15:38:53 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

/**
 * @brief Simple function to check if a number is already in an array
 */
static int	is_in_array(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Generate a unique random number
 */
static int	generate_unique_number(int *numbers, int size, int min, int max)
{
	int	num;
	int	attempts;

	attempts = 0;
	while (attempts++ < 1000)
	{
		num = min + rand() % (max - min + 1);
		if (!is_in_array(numbers, size, num))
			return (num);
	}
	// If we couldn't find a unique number, generate one outside the normal range
	return (max + 1 + size);
}

/**
 * @brief Generate an array of random unique numbers
 */
static int	*generate_random_numbers(int count)
{
	int				*numbers;
	int				i;
	struct timeval	tv;
	pid_t			pid;

	numbers = (int *)malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);

	// Better randomization using multiple entropy sources
	gettimeofday(&tv, NULL);
	pid = getpid();
	srand((unsigned int)((tv.tv_sec * 1000000 + tv.tv_usec) ^ pid ^ (long)&numbers));

	i = 0;
	while (i < count)
	{
		// Alternate between different ranges to get more variety
		if (i % 4 == 0)
			numbers[i] = generate_unique_number(numbers, i, -500000, 500000);
		else if (i % 4 == 1)
			numbers[i] = generate_unique_number(numbers, i, -100000, 100000);
		else if (i % 4 == 2)
			numbers[i] = generate_unique_number(numbers, i, -10000, 10000);
		else
			numbers[i] = generate_unique_number(numbers, i, -1000, 1000);
		i++;
	}

	// Shuffle the array using Fisher-Yates algorithm for even better randomization
	for (i = count - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		int temp = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = temp;
	}

	return (numbers);
}

/**
 * @brief Count operations in a file
 */
static int	count_file_lines(const char *filename)
{
	FILE	*file;
	int		count;
	char	buffer[1024];

	file = fopen(filename, "r");
	if (!file)
		return (-1);

	count = 0;
	while (fgets(buffer, sizeof(buffer), file))
		count++;

	fclose(file);
	return (count);
}

/**
 * @brief Write numbers to a file
 */
static int	write_numbers_to_file(int *numbers, int count, const char *filename)
{
	FILE	*file;
	int		i;

	file = fopen(filename, "w");
	if (!file)
		return (0);

	for (i = 0; i < count; i++)
	{
		fprintf(file, "%d", numbers[i]);
		if (i < count - 1)
			fprintf(file, " ");
	}
	fprintf(file, "\n");

	fclose(file);
	return (1);
}

int	main(int argc, char **argv)
{
	int		count;
	int		*numbers;
	int		operations;
	int		i;
	char	command[512];
	char	result_buffer[128];
	FILE	*fp;

	// Parse command line arguments
	count = (argc > 1) ? ft_atoi(argv[1]) : 500;
	if (count <= 0 || count > 10000)
		count = 500;

	printf("=== Testing push_swap with %d random numbers ===\n", count);

	// Generate random numbers
	numbers = generate_random_numbers(count);
	if (!numbers)
	{
		printf("Error: Failed to allocate memory\n");
		return (1);
	}

	// Print sample of generated numbers
	printf("Sample numbers: ");
	for (i = 0; i < 5 && i < count; i++)
		printf("%d ", numbers[i]);
	printf("...\n");

	// Write numbers to file
	if (!write_numbers_to_file(numbers, count, "temp_numbers.txt"))
	{
		printf("Error: Failed to write numbers to file\n");
		free(numbers);
		return (1);
	}

	// Run push_swap and save output
	sprintf(command, "cat temp_numbers.txt | xargs ../push_swap > temp_operations.txt");
	if (system(command) != 0)
	{
		printf("Error: Failed to run push_swap\n");
		free(numbers);
		remove("temp_numbers.txt");
		return (1);
	}

	// Count operations
	operations = count_file_lines("temp_operations.txt");
	if (operations >= 0)
		printf("Operations: %d\n", operations);
	else
		printf("Error: Failed to count operations\n");

	// Run checker
	sprintf(command, "cat temp_operations.txt | ../checker_Mac $(cat temp_numbers.txt)");
	fp = popen(command, "r");
	if (fp)
	{
		if (fgets(result_buffer, sizeof(result_buffer), fp))
		{
			// Remove newline if present
			char *newline = strchr(result_buffer, '\n');
			if (newline)
				*newline = '\0';
			printf("Checker result: %s\n", result_buffer);
		}
		else
			printf("Error: Failed to read checker result\n");
		pclose(fp);
	}
	else
		printf("Error: Failed to run checker\n");

	// Clean up temporary files
	remove("temp_numbers.txt");
	remove("temp_operations.txt");
	free(numbers);

	// Evaluate performance for 500 numbers
	if (count == 500 && operations >= 0)
	{
		printf("\nPerformance evaluation:\n");
		if (operations <= 5000)
			printf("Excellent! (%d operations)\n", operations);
		else if (operations <= 5500)
			printf("Very good! (%d operations)\n", operations);
		else if (operations <= 6500)
			printf("Good (%d operations)\n", operations);
		else if (operations <= 8000)
			printf("Fair (%d operations)\n", operations);
		else
			printf("Needs optimization (%d operations)\n", operations);
	}

	return (0);
}