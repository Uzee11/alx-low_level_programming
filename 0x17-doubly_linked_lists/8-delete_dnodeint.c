#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a given index in a dlistint_t list
 * @head: Pointer to the pointer of the head of the list
 * @index: Index of the node to be deleted
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp, *to_delete;
    unsigned int i;

    /* Check if the list is empty */
    if (*head == NULL)
        return -1;

    /* If index is 0, delete the head */
    if (index == 0)
    {
        to_delete = *head;
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(to_delete);
        return 1;
    }

    /* Traverse to the desired index */
    temp = *head;
    for (i = 0; i < index && temp != NULL; i++)
        temp = temp->next;

    /* Check if the desired index was reached */
    if (i == index && temp != NULL)
    {
        /* Delete the node at the desired index */
        to_delete = temp;
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        free(to_delete);
        return 1;
    }
    else
    {
        /* If the desired index is not reachable, return -1 */
        return -1;
    }
}
