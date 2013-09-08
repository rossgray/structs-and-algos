#include "BST_template.h"

Node<int> * find_kth(Node<int> * iCurRoot, unsigned int& ioCurIdx, unsigned int k)
{
    Node<int>* kth_elem = NULL; // if we find the kth elem, we will set this pointer to point to it

    if (!iCurRoot->right)
    {
        // if we can't go any further right, then we need to increase the index by one
        ioCurIdx++;
        if (ioCurIdx==k) // we've found the kth element
            return iCurRoot; 
    }
    else
    {
        // else keep going right
        kth_elem = find_kth(iCurRoot->right, ioCurIdx, k);
        // check if we found the kth elem
        if (ioCurIdx == k)
            return kth_elem; // return it
        // check that the current element is not the kth element
        ioCurIdx++;
        if (ioCurIdx == k)
            return iCurRoot; // return cur elem
    }

    // if element not yet found, we need to try the left sub tree
    if (iCurRoot->left)
    {
        kth_elem = find_kth(iCurRoot->left, ioCurIdx, k);
    }   

    return kth_elem;
}


Node<int> * kth_largest(Node<int> *root, unsigned int k)
{
    unsigned int curIdx = 0;
    return find_kth(root, curIdx, k); 
}


// test algorithm
int main()
{
    // initialise
    BST<int> tree;
    tree.insertNode(50);
    tree.insertNode(27);
    tree.insertNode(10);
    tree.insertNode(6);
    tree.insertNode(20);
    tree.insertNode(40);
    tree.insertNode(46);
    tree.insertNode(30);
    tree.insertNode(29);
    tree.insertNode(33);
    tree.insertNode(31);
    tree.insertNode(71);
    tree.insertNode(56);
    tree.insertNode(82);
    tree.insertNode(79); 

    tree.traverseTree(tree.root);

    Node<int>* kth = kth_largest(tree.root, 3);
    std::cout << "3rd largest element = " << kth->data << std::endl;

    kth = kth_largest(tree.root, 1);
    std::cout << "1st largest element = " << kth->data << std::endl;

    kth = kth_largest(tree.root, 2);
    std::cout << "2nd largest element = " << kth->data << std::endl;

    kth = kth_largest(tree.root, 5);
    std::cout << "5th largest element = " << kth->data << std::endl;

    kth = kth_largest(tree.root, 9);
    std::cout << "9th largest element = " << kth->data << std::endl;

    kth = kth_largest(tree.root, 12);
    std::cout << "12th largest element = " << kth->data << std::endl;

    return 0;
}