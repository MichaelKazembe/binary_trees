#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - Check if a tree is a binary search tree
 * @tree: Tree to check
 * @min: INT_MIN
 * @max: INT_MAX
 * Return: 0 if false, 1 if true
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Check if a tree is a binary search tree
 * @tree: Tree to check
 * Return: 0 if false, 1 if true
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}
