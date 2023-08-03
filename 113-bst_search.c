#include "binary_trees.h"

/**
 * bst_search - Search for a node with a value in a binary search tree
 * @tree: Pointer to the root
 * @value: Value of the node to search for
 * Return: Address of the node or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	while (tree)
	{
		if (tree->n == value)
			return ((bst_t *)tree);

		if (value < tree->n)
			tree = tree->left;
		else if (value > tree->n)
			tree = tree->right;
	}

	return (NULL);
}
