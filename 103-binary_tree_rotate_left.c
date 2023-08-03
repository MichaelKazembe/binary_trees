#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a node to the left.
 * @tree: A pointer to the node to rotate.
 *
 * Return: The new root node.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *original_root;
	binary_tree_t *new_root;
	binary_tree_t *new_root_left_child;

	if (tree == NULL)
		return (NULL);

	original_root = tree;
	new_root = original_root->right;

	if (new_root != NULL)
	{
		new_root->parent = original_root->parent;
		new_root_left_child = new_root->left;
		new_root->left = original_root;

		if (original_root->parent != NULL)
		{
			if (original_root->parent->left == original_root)
				original_root->parent->left = new_root;
			if (original_root->parent->right == original_root)
				original_root->parent->right = new_root;
		}

		original_root->right = new_root_left_child;
		original_root->parent = new_root;

		if (new_root_left_child != NULL)
		{
			new_root_left_child->parent = original_root;
		}
	}

	return (new_root);
}
