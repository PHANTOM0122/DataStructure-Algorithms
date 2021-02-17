#include "ITreeType.h"

void FindNode(TreeNode* tree, ItemType item, TreeNode* nodePtr, TreeNode* parentPtr) { 
	nodePtr = tree;
	parentPtr = nullptr; // tree -> root
	bool found = false;
	while (nodePtr != NULL && !found) {
		if (item < nodePtr->info) {
			parentPtr = nodePtr;
			nodePtr = nodePtr->left;
		}
		else if (item > nodePtr->info) {
			parentPtr = nodePtr;
			nodePtr = nodePtr->right;
		}
		else {
			found = true;
		}
	}
}

void TreeType::InsertItem(ItemType item) {
	TreeNode* newnode;
	TreeNode* nodeptr;
	TreeNode* parentptr;
	newnode = new TreeNode;
	newnode->info = item;
	newnode->left = NULL;
	newnode->right = NULL;
	FindNode(root, item, nodeptr, parentptr); 
	if (parentptr == NULL) // Empty!
		root = newnode;
	else if (item < parentptr->info) 
		parentptr->left = newnode; // ���غ��� ������ ���ʿ� attach
	else
		parentptr->right = newnode; // ���غ��� ũ�� �����ʿ� attach
}

void TreeType::DeleteItem(ItemType item) {
	TreeNode* nodeptr;
	TreeNode* parentptr;
	FindNode(root, item, nodeptr, parentptr);
	if (nodeptr == root)
		DeleteNode(root);
	else {
		if (parentptr->left == nodeptr)
			DeleteNode(parentptr->left);
		else
			DeleteNode(parentptr->right);
	}
}