#include "binary_trees.h"
/**
* binary_tree_insert_right - insert node to the right
* @parent: root node
* @value: value of node
* Return: address of new_node
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
  {
		return (NULL);
  }

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
  {
		return (NULL);
  }

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
  new_node->right = NULL;

	if (parent->right == NULL)
	{
		parent->right = new_node;
	}
	else
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
		parent->right = new_node;
	}
	return (new_node);
}
