#include "binary_trees.h"

/**
 * binary_tree_depth - Find the depth of a node in a tree
 * @node: Node to find the depth of
 * Return: Depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth;

	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (0);

	depth = binary_tree_depth(node->parent);
	depth++;
	return (depth);
}

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor, NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *first_node = (binary_tree_t *)first;
	binary_tree_t *second_node = (binary_tree_t *)second;
	size_t first_depth;
	size_t second_depth;

	if (first_node == NULL || second_node == NULL)
		return (NULL);

	first_depth = binary_tree_depth(first_node);
	second_depth = binary_tree_depth(second_node);

	while (first_depth > second_depth)
	{
		first_node = first_node->parent;
		first_depth--;
	}

	while (second_depth > first_depth)
	{
		second_node = second_node->parent;
		second_depth--;
	}

	while (first_node != second_node)
	{
		first_node = first_node->parent;
		second_node = second_node->parent;
	}

	return (first_node);
}
