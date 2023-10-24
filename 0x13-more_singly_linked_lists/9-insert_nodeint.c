#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * list_len - returns the number of elements in a linked list
 * @h: the linked list
 *
 * Return: returns the number of elements in a linked list
 */

size_t list_len(const listint_t *h)
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
 * new_nodeint - Creates a new node for list
 * @n: number to add to new node
 *
 * Return: returns the new node or NULL on failure
 */
listint_t *new_nodeint(const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	return (new);
}

/**
 * add_node - adds a new node at the beginning of a list
 * @head: pointer to the head of the list
 * @n: number to add to new node
 *
 * Return: the address of the new element, or NULL on failure
 */
listint_t *add_node(listint_t **head, const int n)
{
	listint_t *new;

	if (head == NULL)
		return (NULL);
	new = new_nodeint(n);
	if (new == NULL)
		return (new);
	new->next = *head;
	*head = new;
	return (*head);
}

/**
* add_node_end - adds a new node at the end of a linked list
* @head: pointer to the head of the linked list
* @n: number to add to new node
*
* Return: returns the address of the new element, or NULL on failure
*/
listint_t *add_node_end(listint_t **head, const int n)
{
	listint_t *new, *last;

	last = *head;
	if (head == NULL)
		return (NULL);
	new = new_nodeint(n);
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	return (new);
}

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: the linked list
 * @idx: the index where we are inserting
 * @n: number for new node
 *
 * Return: returns the address of the new node, or NULL on failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int x;
	listint_t *new, *temp;

	if (head == NULL || idx > list_len(*head))
		return (NULL);
	else if (idx == 0)
		return (add_node(head, n));
	else if (idx == list_len(*head))
		return (add_node_end(head, n));
	x = 0;
	new = new_nodeint(n);
	temp = *head;
	if (new == NULL)
		return (NULL);
	while (x < idx - 1)
	{
		temp = temp->next;
		x++;
	}
	new->next = temp->next;
	temp->next = new;
	return (new);
}

