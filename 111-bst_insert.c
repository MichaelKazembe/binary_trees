#include "binary_trees.h"

/**
 * bst_insert - Insert a node into a BST
 * @tree: Double pointer to the rooti node of BST
 * @value: Value of the node to insert
 * Return: Address of the new node or NULL
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = *tree;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	while (tmp)
	{
		if (tmp->n == value)
			return (NULL);

		if (value < tmp->n)
		{
			if (tmp->left == NULL)
			{
				tmp->left = (bst_t *)binary_tree_node(tmp, value);
				return (tmp->left);
			}
			tmp = tmp->left;
		}
		else if (value > tmp->n)
		{
			if (tmp->right == NULL)
			{
				tmp->right = (bst_t *)binary_tree_node(tmp, value);
				return (tmp->right);
			}
			tmp = tmp->right;
		}
	}

	return (NULL);
}
