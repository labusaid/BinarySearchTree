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
	delete(leftNode);
	delete(rightNode);
}

//-----binarySearchTree-----
//Default Constructor
template<class DataType>
binarySearchTree<DataType>::binarySearchTree() = default;

//Destructor
template<class DataType>
binarySearchTree<DataType>::~binarySearchTree() {
	deleteAll();
}

//Deletes all nodes in tree
template<class DataType>
void binarySearchTree<DataType>::deleteAll() {
	deleteAll(rootNode);
	rootNode = nullptr;
}

//Deletes nodes recursively from passed node
template<class DataType>
void binarySearchTree<DataType>::deleteAll(treeNode<DataType> *node) {
	if (node != nullptr)
	{
		// delete all nodes to the left
		deleteAll(node->leftNode);

		// delete all nodes to the right
		deleteAll(node->rightNode);

		// delete the node now
		delete node;
	}
}

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
	return size(rootNode);
}

template<class DataType>
std::size_t binarySearchTree<DataType>::size(treeNode<DataType> *node) const {
	if (node == nullptr) {
		return 0;
	}
	return (size(node->leftNode) + size(node->rightNode) + 1);
}

//Prints tree keys inOrder
template<class DataType>
void binarySearchTree<DataType>::print() const {
	print(rootNode);
}

template<class DataType>
void binarySearchTree<DataType>::print(treeNode<DataType> *node) const {
	if (node == nullptr) {
		return;
	}
	print(node->leftNode);
	std::cout << node->key << std::endl;
	print(node->rightNode);
}

//Prints tree inOrder along with left and right pointers
template<class DataType>
void binarySearchTree<DataType>::debug(std::ostream &out) const {
	debug(out, rootNode);
}

template<class DataType>
void binarySearchTree<DataType>::debug(std::ostream &out, treeNode<DataType> *node) const {
	if (node == nullptr) {
		return;
	}
	print(node->leftNode);
	std::cout << node->key << ", " << node->leftNode << ", " << node->rightNode << std::endl;
	print(node->rightNode);
}


//Locates node and calls foundNode passing the located node
template<class DataType>
bool binarySearchTree<DataType>::find(const DataType &searchItem) {
	return (find(searchItem, rootNode));
}

template<class DataType>
bool binarySearchTree<DataType>::find(const DataType &searchItem, void (*foundNode)(const DataType &)) {
	return (find(searchItem, rootNode));
}

template<class DataType>
bool binarySearchTree<DataType>::find(const DataType &searchItem, treeNode<DataType> *node) {
	if (searchItem == node->key) {
		return true;
	}
	else if (searchItem < node->key) {
		if (node->leftNode == nullptr) {
			return false;
		}
		find(searchItem, node->leftNode);
	}
	else if (searchItem > node->key) {
		if (node->rightNode == nullptr) {
			return false;
		}
		find(searchItem, node->rightNode);
	}
}

//Removes a node from the tree
template<class DataType>
bool binarySearchTree<DataType>::erase(const DataType &deleteItem) {
	erase(deleteItem, rootNode);
}

template<class DataType>
bool binarySearchTree<DataType>::erase(const DataType &deleteItem, treeNode<DataType> *node) {
	if (deleteItem == node->key) {
		//TODO: erase pointers towards node
//		delete(node);
		return true;
	}
	else if (deleteItem< node->key) {
		if (node->leftNode == nullptr) {
			return false;
		}
		erase(deleteItem, node->leftNode);
	}
	else if (deleteItem > node->key) {
		if (node->rightNode == nullptr) {
			return false;
		}
		erase(deleteItem, node->rightNode);
	}
}

//Adds a node to the tree
template<class DataType>
void binarySearchTree<DataType>::insert(const DataType &newItem) {
	if(empty()) {
		rootNode = new treeNode<DataType>(newItem);
	}
	else {
		insert(newItem, *rootNode);
	}
}

template<class DataType>
void binarySearchTree<DataType>::insert(const DataType &newItem, treeNode<DataType> &currentNode) {
	if (newItem == currentNode.key) {
		update(currentNode.key, newItem);
	}
	else if (newItem < currentNode.key) {
		if (currentNode.leftNode == nullptr) {
			currentNode.leftNode = new treeNode<DataType>(newItem);
		}
		else {
			insert(newItem, *currentNode.leftNode);
		}
	}
	else if (newItem > currentNode.key) {
		if (currentNode.rightNode == nullptr) {
			currentNode.rightNode = new treeNode<DataType>(newItem);
		}
		else {
			insert(newItem, *currentNode.rightNode);
		}
	}
}

//Adds a node to the tree and calls duplicateItemFound if it already exists
template<class DataType>
void binarySearchTree<DataType>::insert(const DataType &newItem, void (*duplicateItemFound)(DataType &, const DataType &)) {
	if(empty()) {
		rootNode = new treeNode<DataType>(newItem);
	}
	else {
		insert(newItem, *rootNode);
	}
}

//Updates the information of a node
template<class DataType>
void binarySearchTree<DataType>::update(DataType &existingItem, const DataType &newItem) {
	update(existingItem, newItem, rootNode);
}

template<class DataType>
void binarySearchTree<DataType>::update(DataType &existingItem, const DataType &newItem, treeNode<DataType> *node) {
	if (existingItem == node->key) {
		node->key = newItem;
		return;
	}
	else if (existingItem < node->key) {
		update(existingItem, newItem, existingItem.leftNode);
	}
	else if (existingItem > existingItem.key) {
		update(existingItem, newItem, node->rightNode);
	}
}

//I understand how this is supposed to work in theory and how it's supposed to make life easier but I could never figure
//out what I needed to pass in for the function to actually work as intended and it ended up costing me more time in the end.

//Calls itemFound for each item in the tree
template<class DataType>
void binarySearchTree<DataType>::traverse(void (*itemFound)(const DataType &)) const {
	traverse(rootNode, *itemFound);
}

//Used by traverse function
template<class DataType>
void binarySearchTree<DataType>::traverse(treeNode<DataType> *node, void (*itemFound)(const DataType &)) const {
    if (node == nullptr) {
        return;
    }
	traverse(node->leftNode, *itemFound);
    itemFound(node->key);
	traverse(node->rightNode, *itemFound);
}

//Main
int main() {
	auto *testTree = new binarySearchTree<int>;
	testTree->insert(5);
	testTree->insert(10);
	testTree->insert(1);
	testTree->insert(3);
	testTree->insert(4);
	testTree->insert(9);
	testTree->print();
	std::cout << "items: " << testTree->size() << std::endl;
	std::cout << "found 10: " << testTree->find(10) << std::endl;
//	std::cout << "erased 10: " << testTree->erase(10) << std::endl;
	std::cout << "found 10: " << testTree->find(10) << std::endl;
	delete(testTree);
	return 0;
}