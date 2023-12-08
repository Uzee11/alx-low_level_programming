#include "lists.h"
#include <stdio.h>

/**
 * is_palindrome - Checks if a number is a palindrome
 * @number: The number to be checked
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(int number)
{
    int original = number;
    int reversed = 0;
    int remainder;

    while (number > 0)
    {
        remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }

    return original == reversed;
}

/**
 * find_largest_palindrome - Finds the largest palindrome made from
 * the product of two 3-digit numbers
 * Return: The largest palindrome
 */
int find_largest_palindrome(void)
{
    int largest_palindrome = 0;
    int i, j, product;

    for (i = 100; i < 1000; i++)
    {
        for (j = 100; j < 1000; j++)
        {
            product = i * j;
            if (is_palindrome(product) && product > largest_palindrome)
                largest_palindrome = product;
        }
    }

    return largest_palindrome;
}

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
    int result = find_largest_palindrome();

    /* Save the result to the file */
    FILE *file = fopen("102-result", "w");
    if (file != NULL)
    {
        fprintf(file, "%d", result);
        fclose(file);
    }

    return 0;
}
