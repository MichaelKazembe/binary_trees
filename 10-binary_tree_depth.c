#include "binary_trees.h"

/**
* binary_tree_depth - measures the depth of a node in a binary tree
* @node: node to measure the depth
* Return:0 if tree is NULL, otherwise node_depth
*/

size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t node_depth;

	if (node == NULL)
	{
		return (0);
	}

	if (node->parent == NULL)
	{
		return (0);
	}

	node_depth = binary_tree_depth(node->parent);
	node_depth++;

	return (node_depth);
}
