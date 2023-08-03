#include "binary_trees.h"

/**
* binary_tree_size - measures the size of a binary tree
* @tree:  root node of the tree to measure the size
* Return:0 if tree in NULL
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left;
	size_t right;

	if (tree == NULL)
	{
		return (0);
	}

	if (!(tree->left) && !(tree->right))
	{
		return (1);
	}

	left = binary_tree_size(tree->left);
	left++;

	right = binary_tree_size(tree->right);
	right++;

	return (left + right - 1);
}
