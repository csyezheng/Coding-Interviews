#include <exception>
#include "06_Binary_tree_node.h"

BinaryTreeNode* construct_binary_tree(int *preorder, int *inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;

	return construct_core(preorder, preorder + length - 1,
		inorder, inorder + length - 1);
}

BinaryTreeNode* construct_core(int *start_preorder, int *end_preorder,
	int *start_inorder, int *end_inorder)
{
	int root_value = start_preorder[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->m_nValue = root_value;
	root->m_pLeft = nullptr;
	root->m_pRight = nullptr;

	auto root_inorder = start_inorder; 
	while (root_inorder <= end_inorder && *root_inorder != root_value)
		++root_inorder;

	if (*root_inorder != root_value)
		throw std::exception("invalid input");

	auto left_length = root_inorder - start_inorder;
	auto preorder_left_end = start_preorder + left_length;

	if (left_length > 0)
		root->m_pLeft = construct_core(start_preorder + 1, preorder_left_end,
			start_inorder, root_inorder - 1);
	if (end_preorder - preorder_left_end > 0)
		root->m_pRight = construct_core(preorder_left_end + 1, end_preorder,
			root_inorder + 1, end_inorder);

	return root;
}