#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * listint_len - returns the number of elements in a linked list
 * @h: the linked list
 *
 * Return: returns the number of elements in a linked list
 */

size_t listint_len(const listint_t *h)
{
	size_t i;

	i = 0;
	while (h != NULL)
	{
		i++;
		h = h->next;
	}
	return (i);
}

/**
 * delete_nodeint_at_index - deletes the node at index of linked list
 * @head: the pointer to the linked list
 * @index: index to be deleted
 *
 * Return: returns 1 on success, -1 on failure.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int x;
	listint_t *temp, *remove;

	temp = *head;
	if (head == NULL || index >= listint_len(*head))
	{
		return (-1);
	}
	else if (index == 0)
	{
		remove = temp;
		*head = temp->next;
		free(remove);
		return (1);
	}
	else if (index == listint_len(*head) - 1)
	{
		while (temp->next->next != NULL)
			temp = temp->next;
		remove = temp->next;
		temp->next = NULL;
		free(remove);
		return (1);
	}
	x = 0;
	while (x < index - 1)
	{
		temp = temp->next;
		x++;
	}
	remove = temp->next->next;
	free(temp->next);
	temp->next = remove;
	return (1);
}
