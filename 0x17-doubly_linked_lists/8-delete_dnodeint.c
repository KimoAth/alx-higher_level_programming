#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given position.
 * @head: Pointer to a pointer to the head of the linked list.
 * @index: Index of the node that should be deleted.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
        dlistint_t *current;
        unsigned int i;

        if (head == NULL || *head == NULL)
                return -1;

        current = *head;
        if (index == 0)
        {
                *head = (*head)->next;
                if (*head != NULL)
                        (*head)->prev = NULL;
                free(current);
                return 1;
        }

        for (i = 0; i < index && current != NULL; i++)
        {
                current = current->next;
        }

        if (current == NULL)
                return -1;

        if (current->next != NULL)
                current->next->prev = current->prev;
        if (current->prev != NULL)
                current->prev->next = current->next;

        free(current);
        return 1;
}
