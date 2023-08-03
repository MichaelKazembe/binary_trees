#include "binary_trees.h"

/**
 * binary_tree_sibling - Find the sibling of a node
 * @node: Node to find the sibling of
 * Return: Pointer to the sibling node, NULL if not found
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return (node->parent->left);
	else
		return (NULL);
}

/**
 * binary_tree_uncle - Find the uncle of a node (parent of parent)
 * @node: Node to find the uncle of
 * Return: Pointer to the uncle node, NULL if not found
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	if (node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
