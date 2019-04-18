//
// Created by labusaid on 4/16/19.
//

#include <iostream>
#include "binarySearchTree.h"

template<class DataType>
bool binarySearchTree<DataType>::empty() const {
	return (size() == 0);
}

template<class DataType>
std::size_t binarySearchTree<DataType>::size() const {
	if (rootNode == nullptr) {
		return 0;
	}
	return 1;
}

template<class DataType>
void binarySearchTree<DataType>::print() const {
//	TODO: use traverse function to print
//	treeNode<DataType> *currentNode = rootNode;
//
//	if (currentNode->leftNode == nullptr && currentNode->rightNode == nullptr) {
//		std::cout << currentNode << std::endl;
//	}
}

template<class DataType>
void binarySearchTree<DataType>::debug(std::ostream &out) const {

}

template<class DataType>
bool binarySearchTree<DataType>::find(const DataType &searchItem, void (*foundNode)(const DataType &)) {
	return false;
}

template<class DataType>
bool binarySearchTree<DataType>::erase(const DataType &deleteItem) {
	return false;
}

template<class DataType>
void binarySearchTree<DataType>::insert(const DataType &newItem) {
	treeNode<DataType> newNode = new treeNode<DataType>;
	newNode.key = newItem;
}

template<class DataType>
void
binarySearchTree<DataType>::insert(const DataType &newItem, void (*duplicateItemFound)(DataType &, const DataType &)) {

}

template<class DataType>
void binarySearchTree<DataType>::update(DataType &exsitingItem, const DataType &newItem) {

}

template<class DataType>
void binarySearchTree<DataType>::traverse(void (*itemFound)(const DataType &)) const {

}
