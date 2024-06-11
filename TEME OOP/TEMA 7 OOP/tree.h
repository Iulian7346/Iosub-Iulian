#pragma once
#include <iostream>

template <typename T>
int compara(T firstValue, T secondValue)
{
	if (firstValue < secondValue)
	{
		return -1;
	}
	else if (firstValue > secondValue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <>
int compara <char*>(char* firstValue, char* secondValue)
{
	return strcmp(firstValue, secondValue);
}

template <typename T>
int compara2(T firstValue, T secondValue)
{
	if (firstValue > secondValue)
	{
		return -1;
	}
	else if (firstValue < secondValue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <typename T>
struct Node
{
	T value;
	Node<T>** children;
	unsigned int nrChildren;
};

template <class T>
class Tree
{
public:
	Node<T>* root;
	unsigned int maxChildrenPerNode;

	Tree(unsigned int nrChildren)
	{
		maxChildrenPerNode = nrChildren;
		root = nullptr;
	}

	void add_node(Node<T>* parent, T value)
	{
		if (parent == nullptr)
		{
			root = new Node<T>;
			root->value = value;
			root->nrChildren = 0;
			root->children = new Node<T>*[maxChildrenPerNode] {};
		}
		else
		{
			parent->children[parent->nrChildren] = new Node<T>;
			parent->children[parent->nrChildren]->value = value;
			parent->children[parent->nrChildren]->nrChildren = 0;
			parent->children[parent->nrChildren]->children = new Node<T>*[maxChildrenPerNode] {};
			parent->nrChildren++;
		}
	}


	void sort(Node<T>* parinte, int (*comparatie)(T, T))
	{
		unsigned int i, j;
		for (i = 0; i < parinte->nrChildren - 1; i++)
			for (j = i + 1; j < parinte->nrChildren; j++)
			{
				if (comparatie(parinte->children[i]->value, parinte->children[j]->value) > 0)
				{
					T aux;
					aux = parinte->children[i]->value;
					parinte->children[i]->value = parinte->children[j]->value;
					parinte->children[j]->value = aux;
				}
			}
	}

	void printNodes(Node<T>* parinte)
	{
		unsigned int i;
		for (i = 0; i < parinte->nrChildren; i++)
		{
			std::cout << parinte->children[i]->value << " ";
		}
	}

	unsigned int count(Node<T>* node) const {
		if (node == nullptr) {
			if (root == nullptr)
				return 0;
			else
				return count(root);
		}
		unsigned int totalChildren = node->nrChildren;
		for (unsigned int i = 0; i < node->nrChildren; ++i) {
			totalChildren += count(node->children[i]);
		}
		return totalChildren;
	}

	Node<T>* findNode(Node<T>* node, T value) const {
		if (node == nullptr) {
			return nullptr;
		}
		if (node->value== value) {
			return node;
		}
		for (unsigned int i = 0; i < node->nrChildren; ++i) {
		
			if (node->children[i].value == value) {
				return node->children[i];
			}
			else{
				return findNode(node->children, value);
			}
		}
		return nullptr;
	}
};

template <>
class Tree <char*>
{
public:
	Node<char*>* root;
	unsigned int maxChildrenPerNode;

	Tree(unsigned int nrChildren)
	{
		maxChildrenPerNode = nrChildren;
		root = nullptr;
	}

	void add_node(Node<char*>* parent, const char* value)
	{
		if (parent == nullptr)
		{
			root = new Node<char*>;
			//root->value = value;
			root->value = new char[100] {};
			strcpy(root->value, value);
			root->nrChildren = 0;
			root->children = new Node<char*>*[maxChildrenPerNode] {};
		}
		else
		{
			parent->children[parent->nrChildren] = new Node<char*>;
			//parent->children[parent->nrChildren]->value = value;
			parent->children[parent->nrChildren]->value = new char[100] {};
			strcpy(parent->children[parent->nrChildren]->value, value);
			parent->children[parent->nrChildren]->nrChildren = 0;
			parent->children[parent->nrChildren]->children = new Node<char*>*[maxChildrenPerNode] {};
			parent->nrChildren++;
		}
	}

	void sort(Node<char*>* parinte, int (*comparatie)(char*, char*))
	{
		unsigned int i, j;
		for (i = 0; i < parinte->nrChildren - 1; i++)
			for (j = i + 1; j < parinte->nrChildren; j++)
			{
				if (comparatie(parinte->children[i]->value, parinte->children[j]->value) > 0)
				{
					char* aux;
					aux = parinte->children[i]->value;
					parinte->children[i]->value = parinte->children[j]->value;
					parinte->children[j]->value = aux;
				}
			}
	}

	void printNodes(Node<char*>* parinte)
	{
		unsigned int i;
		for (i = 0; i < parinte->nrChildren; i++)
		{
			std::cout << parinte->children[i]->value << " ";
		}
	}

	void insert_node(Node<char*>* parent, const char* value)
	{
		if (parent == nullptr) {
			return;
		}

		Node<char*>* newNode = new Node<char*>;
		newNode->value = new char[100] {};
		strcpy(newNode->value, value);
		newNode->nrChildren = 0;
		newNode->children = new Node<char*>*[maxChildrenPerNode] {};

		parent->children[parent->nrChildren] = newNode;
		parent->nrChildren++;
	}

	unsigned int count(Node<char*>* node) const {
		if (node == nullptr) {
			if (root == nullptr)
				return 0;
			else
				return count(root);
		}
		unsigned int totalChildren = node->nrChildren;
		for (unsigned int i = 0; i < node->nrChildren; ++i) {
			totalChildren += count(node->children[i]);
		}
		return totalChildren;
	}

	Node<char*>* findNode(Node<char*>* node,const char* value) {
		if (node == nullptr) {
			return nullptr;
		}
		if (strcmp(node->value, value)==NULL) 
		{
			return node;
		}
		for (unsigned int i = 0; i < node->nrChildren; ++i) {

			if (strcmp(node->children[i]->value, value) == NULL) {
				return node->children[i];
			}
			else
			{
				if (findNode(node->children[i], value) != nullptr)

					return findNode(node->children[i], value);
			}
		}return nullptr;
		
	}
	

	
};

