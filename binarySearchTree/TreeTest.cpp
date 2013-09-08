#include "BST_template.h"

int main()
{
	
	BST<int> tree;

	tree.insertNode(5);
	tree.insertNode(7);
	tree.insertNode(18);
	tree.insertNode(1);
	tree.insertNode(10);
	tree.insertNode(30);
	tree.insertNode(5);

	tree.traverseTree(tree.root);

	tree.deleteNode(5);
	tree.deleteNode(5);
	tree.deleteNode(30);
	tree.traverseTree(tree.root);
	tree.insertNode(2);
	tree.insertNode(20);
	tree.traverseTree(tree.root);

	Node<int>* toDel = tree.findNode(2);
	tree.deleteNode(toDel);
	tree.traverseTree(tree.root);

	return 0;
}