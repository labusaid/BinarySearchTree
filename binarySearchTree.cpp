//
// Created by labusaid on 4/16/19.
//

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
