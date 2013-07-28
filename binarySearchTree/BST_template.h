#include <iostream>


template<class T>
class BST
{

public:

	template<class U>
	class Node
	{
	public:
		Node(const U& iData)
		{
			data = iData;
			right = 0;
			left = 0;
			parent = 0;
		}

		Node* right;
		Node* left;
		Node* parent;
		U data;
	};

	BST():root(0){};
	~BST();

	Node<T>* insertNode(const T& iData);
	Node<T>* findNode(const T& iData) const;
	bool deleteNode(const T& iData);
	bool deleteNode(Node<T>* iNode);
	int traverseTree(Node<T>* iNode) const;


	Node<T>* root;

private:
	Node<T>* findClosest(const T& iData,  Node<T>* iRoot) const;
	void deleteTree(Node<T>* iRoot);
};


template<class T>
BST<T>::Node<T>* BST<T>::findClosest(const T& iData, BST<T>::Node<T>* iRoot) const
{
	if (!iRoot)
	{
		return 0;
	}
	else if (iRoot->data == iData)
	{
		// element found
		return iRoot;
	}

	if (iData > iRoot->data)
	{
		if (iRoot->right)
		{
			return findClosest(iData, iRoot->right);
		}
		else
			return iRoot;
	}

	else
	{
		if (iRoot->left)
		{
			return findClosest(iData, iRoot->left);
		}
		else
			return iRoot;
	}


}

template<class T>
BST<T>::Node<T>* BST<T>::findNode(const T& iData) const
{
	if (!iData)
		return 0;

	Node<T>* result = findClosest(iData, root);
	if (result->data == iData)
	{
		std::cout << "item found" << std::endl;
		return result;
	}
	else
	{
		// if not found
		std::cout << "item not found" << std::endl;
		return NULL;
	}
}

template<class T>
BST<T>::Node<T>* BST<T>::insertNode(const T& iData)
{
	Node<T>* newParent = findClosest(iData, root);

	if (newParent == 0)
	{
		// tree empty
		Node<T>* newNode = new Node<T>(iData);
		root = newNode;
		std::cout << "item " << iData << " added" << std::endl;
		std::cout << "root = " << root->data << std::endl;
		return newNode;
	}
	else if (newParent->data == iData)
	{
		std::cout << "Item already in tree!" << std::endl;
		return newParent;
	}

	// else create new node and insert into tree
	Node<T>* newNode = new Node<T>(iData);
	newNode->parent = newParent;
	if (iData > newParent->data)
	{
		newParent->right = newNode;
	}
	else
	{
		newParent->left = newNode;
	}
	std::cout << "item " << iData << " added" << std::endl;

	return newNode;

}

template<class T>
bool BST<T>::deleteNode(BST<T>::Node<T>* iNode)
{
	if (!iNode)
	{
		std::cout << "Node not valid" << std::endl;
		return false;
	}

	if (!iNode->parent)
	{
		// if root
		std::cout << "deleting root node" << std::endl;

		if (iNode->left)
		{
			root = iNode->left;
			if (iNode->right)
			{
				// reconnect iNode->right
				Node<T>* newRight = iNode->left;
				while (newRight->right)
				{
					newRight=newRight->right;
				}
				newRight->right = iNode->right;
			}	
		}
		else if (iNode->right)
		{
			root = iNode->right;
		}
	}
	
	else
	{
		// check which child it was
		if (iNode->parent->left == iNode)
		{
			if(iNode->right)
			{
				iNode->parent->left = iNode->right;
				if (iNode->left)
				{
					// reconnect iNode->left
					Node<T>* newLeft = iNode->right;
					while (newLeft->left)
					{
						newLeft=newLeft->left;
					}
					newLeft->left = iNode->left;
				}	
			}
			else if (iNode->left)
			{
				iNode->parent->left = iNode->left;
			}
			else
			{
				iNode->parent->left = 0;
			}
		}
		else
		{
			// it was right node
			if(iNode->left)
			{
				iNode->parent->right = iNode->left;
				if (iNode->right)
				{
					// reconnect iNode->right
					Node<T>* newRight = iNode->left;
					while (newRight->right)
					{
						newRight=newRight->right;
					}
					newRight->right = iNode->right;
				}	
			}
			else if (iNode->right)
			{
				iNode->parent->right = iNode->right;
			}
			else
			{
				iNode->parent->right = 0;
			}
		}
	}

	std::cout << "item " << iNode->data << " deleted" << std::endl;
	delete iNode;
	return true;
}

template<class T>
bool BST<T>::deleteNode(const T& iData)
{
	if (!iData)
	{
		return false;
	}
	Node<T>* nodeToDel = findNode(iData);
	if (nodeToDel)
	{
		return deleteNode(nodeToDel);
	}
	else
	{
		std::cout << "item not found, therefore could not be deleted" << std::endl;
		return false;
	}
}

template<class T>
void BST<T>::deleteTree(BST<T>::Node<T>* iNode)
{
	if (!iNode)
	{
		return;
	}
		
	if (iNode->right)
	{
		deleteTree(iNode->right);
	}
	if (iNode->left)
	{
		deleteTree(iNode->left);
	}

	std::cout << "item " << iNode->data << " deleted" << std::endl;	
	delete iNode;
	return;

}

template<class T>
int BST<T>::traverseTree(BST<T>::Node<T>* iNode) const
{
	if (iNode == root)
	{
		std::cout << "Contents of tree: " << std::endl;
	}
	if (!iNode)
		return 0;
	int numNodes = 1;
	numNodes += traverseTree(iNode->left);
	std::cout << iNode->data << "  ";
	numNodes += traverseTree(iNode->right);

	
}

// destructor
template<class T>
BST<T>::~BST()
{
	deleteTree(root);
}

