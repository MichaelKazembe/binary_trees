#include "binary_trees.h"

/**
 * array_to_bst - Convert an array to a binary search tree
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 * Return: Root node of the search tree
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root_node = NULL;
	size_t i;

	i = 0;
	while (i < size)
	{
		bst_insert(&root_node, array[i]);
		i++;
	}
	return (root_node);
}
