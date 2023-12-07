#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list
 * @head: Pointer to the pointer of the head of the list
 * @n: Value to be assigned to the new node
 * Return: The address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node, *temp;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return NULL;

    /* Initialize the new node */
    new_node->n = n;
    new_node->next = NULL;

    /* If the list is empty, new node is both head and tail */
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
    }
    else
    {
        /* Traverse to the end of the list */
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;

        /* Connect the new node to the last node */
        new_node->prev = temp;
        temp->next = new_node;
    }

    return new_node;
}
