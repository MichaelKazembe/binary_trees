#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a node to the right.
 * @tree: A pointer to the node to rotate.
 *
 * Return: The new root node.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *original_root;
	binary_tree_t *new_root;
	binary_tree_t *new_root_right_child;

	if (tree == NULL)
		return (NULL);

	original_root = tree;
	new_root = original_root->left;

	if (new_root != NULL)
	{
		new_root->parent = original_root->parent;
		new_root_right_child = new_root->right;
		new_root->right = original_root;

		if (original_root->parent != NULL)
		{
			if (original_root->parent->left == original_root)
				original_root->parent->left = new_root;
			if (original_root->parent->right == original_root)
				original_root->parent->right = new_root;
		}

		original_root->left = new_root_right_child;
		original_root->parent = new_root;

		if (new_root_right_child != NULL)
		{
			new_root_right_child->parent = original_root;
		}
	}

	return (new_root);
}
