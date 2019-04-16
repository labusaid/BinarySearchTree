//
// Created by labusaid on 4/16/19.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H


#include <cstdio>
#include <iosfwd>
#include <string>

// forward declaration of the template class binarySearchTree
template<class DataType>
class binarySearchTree;

// treeNode class
template <class DataType>
class treeNode
{
	friend class binarySearchTree<DataType>;
private:
	<DataType> key;
	treeNode<DataType> leftNode;
	treeNode<DataType> rightNode;
public:
	std::ostream &operator<< (std::ostream &out);
};

// binarySearchTree class
template <class DataType>
class binarySearchTree
{
private:
	treeNode<DataType> rootNode = nullptr;
public:
	bool empty() const;
	std::size_t size() const;
	void print() const;
	void debug(std::ostream &out) const;
	bool find(const DataType &searchItem, void (*foundNode)(const DataType&));
	bool erase(const DataType &deleteItem);
	void insert(const DataType &newItem);
	void insert(const DataType &newItem, void (*duplicateItemFound)(DataType &existingItem, const DataType &newItem));
	void update(DataType &exsitingItem, const DataType &newItem);
	void traverse(void (*itemFound)(const DataType& foundItem)) const;
};

#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H
