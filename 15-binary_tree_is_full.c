#include "binary_trees.h"

/**
 * binary_tree_is_full - Check if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is full, 0 otherwise or if tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_full, right_full;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_full = binary_tree_is_full(tree->left);
	right_full = binary_tree_is_full(tree->right);

	if (left_full == 0 || right_full == 0)
		return (0);

	return (1);
}
