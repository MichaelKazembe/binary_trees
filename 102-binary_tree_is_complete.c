#include "binary_trees.h"

/**
 * binary_tree_nodes - Count how many nodes are in a tree
 * @tree: Root node of the tree
 * Return: Number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes_left, nodes_right;

	if (tree == NULL)
		return (0);

	nodes_left = binary_tree_nodes(tree->left) + 1;
	nodes_right = binary_tree_nodes(tree->right) + 1;

	return (nodes_right + nodes_left - 1);
}

/**
 * is_complete - Check if a binary tree is complete using index & num nodes
 * @tree: Root node of the tree
 * @index: Index of the current node
 * @nodes: Number of nodes in the tree
 * Return: 0 if not complete, 1 if complete
 */
int is_complete(const binary_tree_t *tree, int index, int nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= nodes)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, nodes) &&
		is_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_complete - Check if a binary tree is complete
 * @tree: Root node of the tree
 * Return: 1 if true, 0 if false
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index = 0;
	size_t nodes = binary_tree_nodes(tree);

	if (tree == NULL)
		return (0);

	return (is_complete(tree, index, (int)nodes));
}
