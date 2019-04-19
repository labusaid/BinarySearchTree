//
// Created by labusaid on 4/16/19.
//

#include <iostream>
#include "binarySearchTree.h"

//-----treeNode-----
//TreeNode Constructor
template<class DataType>
treeNode<DataType>::treeNode(DataType newKey) {
	key = newKey;
}

//TreeNode Destructor
template<class DataType>
treeNode<DataType>::~treeNode() {
	delete(key);
	delete(leftNode);
	delete(rightNode);
}

//-----binarySearchTree-----
//Default Constructor
template<class DataType>
binarySearchTree<DataType>::binarySearchTree() = default;

//Destructor
//template<class DataType>
//binarySearchTree<DataType>::~binarySearchTree() = default;

//Returns if tree contains no nodes
template<class DataType>
bool binarySearchTree<DataType>::empty() const {
	return (size() == 0);
}

//Returns size of tree
template<class DataType>
std::size_t binarySearchTree<DataType>::size() const {
	if (rootNode == nullptr) {
		return 0;
	}
	return sizeRecursive(rootNode);
}

template<class DataType>
std::size_t binarySearchTree<DataType>::sizeRecursive(treeNode<DataType> *node) const {
	if (node == nullptr) {
		return 0;
	}
	return (sizeRecursive(node->leftNode) + sizeRecursive(node->rightNode) + 1);
}

//Prints tree keys inOrder
template<class DataType>
void binarySearchTree<DataType>::print() const {
	printRecursive(rootNode);
}

template<class DataType>
void binarySearchTree<DataType>::printRecursive(treeNode<DataType> *node) const {
	if (node == nullptr) {
		return;
	}
    printRecursive(node->leftNode);
	std::cout << node->key << std::endl;
    printRecursive(node->rightNode);
}

//Prints tree inOrder along with left and right pointers
template<class DataType>
void binarySearchTree<DataType>::debug(std::ostream &out) const {

}

//Locates node and calls foundNode passing the located node
template<class DataType>
bool binarySearchTree<DataType>::find(const DataType &searchItem, void (*foundNode)(const DataType &)) {
	return false;
}

//Removes a node from the tree
template<class DataType>
bool binarySearchTree<DataType>::erase(const DataType &deleteItem) {

}

//Adds a node to the tree
template<class DataType>
void binarySearchTree<DataType>::insert(const DataType &newItem) {
	if(empty()) {
		rootNode = new treeNode<DataType>(newItem);
	}
	else {
		insertRecursive(newItem, *rootNode);
	}
}

template<class DataType>
void binarySearchTree<DataType>::insertRecursive(const DataType &newItem, treeNode<DataType> &currentNode) {
	if (newItem == currentNode.key) {
//		update(currentNode, newItem);
	}
	else if (newItem < currentNode.key) {
		if (currentNode.leftNode == nullptr) {
			currentNode.leftNode = new treeNode<DataType>(newItem);
		}
		else {
			insertRecursive(newItem, *currentNode.leftNode);
		}
	}
	else if (newItem > currentNode.key) {
		if (currentNode.rightNode == nullptr) {
			currentNode.rightNode = new treeNode<DataType>(newItem);
		}
		else {
			insertRecursive(newItem, *currentNode.rightNode);
		}
	}
}

//Adds a node to the tree and calls duplicateItemFound if it already exists
template<class DataType>
void binarySearchTree<DataType>::insert(const DataType &newItem, void (*duplicateItemFound)(DataType &, const DataType &)) {

}

//Updates the information of a node
template<class DataType>
void binarySearchTree<DataType>::update(DataType &exsitingItem, const DataType &newItem) {

}

//Calls itemFound for each item in the tree
template<class DataType>
void binarySearchTree<DataType>::traverse(void (*itemFound)(const DataType &)) const {
	traverseRecursive(rootNode, *itemFound);
}

//Used by traverse function
template<class DataType>
void binarySearchTree<DataType>::traverseRecursive(treeNode<DataType> *node ,void (*itemFound)(const DataType &)) const {
    if (node == nullptr) {
        return;
    }
    traverseRecursive(node->leftNode, *itemFound);
    itemFound(node->key);
    traverseRecursive(node->rightNode, *itemFound);
}

//Used for debugging
template<class DataType>
void testFunc(const DataType *itemFound) {
	std::cout << "What?" << std::endl;
}

//Main
int main() {
	auto testTree = new binarySearchTree<int>;
	testTree->insert(5);
	testTree->insert(10);
	testTree->insert(1);
	testTree->insert(3);
	testTree->insert(4);
	testTree->insert(9);
	testTree->print();
	std::cout << testTree->size() << std::endl;
	return 0;
}