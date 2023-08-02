#include "binary_trees.h"

/**
* binary_tree_is_leaf - checks if a node is leaf
* @node: pointer to the node to check
* Return: 0 if node is NULL, else 1
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}
	if (node->left || node->right)
	{
		return (0);
	}
	return (1);
}
