#include "shell.h"
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
