#include "binary_trees.h"

/**
 * binary_tree_height - Find the height of a binary tree
 * @tree: Root node of the tree
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left;
	size_t height_right;

	if (tree == NULL)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_left++;
	height_right = binary_tree_height(tree->right);
	height_right++;

	if (height_left > height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}

/**
 * levelorder - Perform level order traversal using a binary tree
 * @tree: Binary tree to traverse
 * @func: Function pointer to perform an operation on each node's value
 * @level: Level of the tree being traversed
 */
void levelorder(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL || func == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else
	{
		levelorder(tree->left, func, level - 1);
		levelorder(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - Perform level order traversal on a binary tree
 * @tree: Root node of the binary tree
 * @func: Function pointer to perform an operation on each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i = 0;
	size_t level;

	if (tree == NULL || func == NULL)
		return;

	level = binary_tree_height(tree);

	while (i < level)
	{
		levelorder(tree, func, i);
		i++;
	}
}
