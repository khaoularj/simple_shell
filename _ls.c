#include "shell.h"

/**
 * myAddnd - is a function to add node at start of singly linked list;
 * @pointerHead: is a pointer to the pointerHead node;
 * @str: is a string of node's field;
 * @num: is node's index of history linked list;
 *
 * Return: value equal to the size of singly linked list;
 */
strl_t *myAddnd(strl_t **pointerHead, const char *str, int num)
{
	strl_t *newhead;

	if (!pointerHead)
		return (NULL);

	newhead = malloc(sizeof(strl_t));
	if (!newhead)
		return (NULL);

	set_mem((void *)newhead, 0, sizeof(strl_t));
	newhead->num = num;
	if (str)
	{
		newhead->str = my_strdup(str);
		if (!newhead->str)
		{
			free(newhead);
			return (NULL);
		}
	}

	newhead->next = *pointerHead;
	*pointerHead = newhead;
	return (newhead);
}

/**
 * endmyAddnd - is a function to add node at the end of linked list;
 * @pointerHead: is a pointer to the pointerHead node;
 * @str: is a string of node's field;
 * @num: is node's index of history linked list;
 *
 * Return: value equal to the size of singly linked list;
 */
strl_t *endmyAddnd(strl_t **pointerHead, const char *str, int num)
{
	strl_t *newnode, *node;

	if (!pointerHead)
		return (NULL);

	node = *pointerHead;
	newnode = malloc(sizeof(strl_t));
	if (!newnode)
		return (NULL);

	set_mem((void *)newnode, 0, sizeof(strl_t));
	newnode->num = num;

	if (str)
	{
		newnode->str = my_strdup(str);
		if (!newnode->str)
		{
			free(newnode);

			return (NULL);
		}
	}

	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = newnode;
	}
	else
		*pointerHead = newnode;

	return (newnode);
}

/**
 * ndIndex_del - is a function to delete node at a certain index;
 * @pointerHead: is a pointer to pointing pointerHead node;
 * @index: is index where to delete a node;
 *
 * Return: value 1 for true otherwise 0;
 */
int ndIndex_del(strl_t **pointerHead, unsigned int index)
{
	unsigned int i = 0;
	strl_t *node, *prevnode;

	if (!pointerHead || !*pointerHead)
		return (0);

	if (!index)
	{
		node = *pointerHead;
		*pointerHead = (*pointerHead)->next;
		free(node->str);
		free(node);

		return (1);
	}
	node = *pointerHead;
	while (node)
	{
		if (i == index)
		{
			prevnode->next = node->next;
			free(node->str);
			free(node);

			return (1);
		}
		i++;
		prevnode = node;
		node = node->next;
	}

	return (0);
}

/**
 * allListnd - a function to free all linked listt;
 * @ppd: is a pointer to pointing pointerHead node for storing pointer's address;
 *
 * Return: nothing.
 */
void allListnd(strl_t **ppd)
{
	strl_t *node, *nextnode, *pointerHead;

	if (!ppd || !*ppd)
		return;

	pointerHead = *ppd;
	node = pointerHead;
	while (node)
	{
		nextnode = node->next;
		free(node->str);
		free(node);
		node = nextnode;
	}

	*ppd = NULL;
}
