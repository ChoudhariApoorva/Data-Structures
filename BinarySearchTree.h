#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T key;
	struct Node<T>* left;
	struct Node<T>* right;

	Node(T key): key(key), left(NULL), right(NULL) {}
};

template <typename T>
class BinarySearchTree
{
	private:
		struct Node<T>* root;
		void addHelper(Node<T>*, Node<T>*);
		void dispHelper(Node<T>*);
	public:
		BinarySearchTree();
		void add(T);
		void disp();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

template <typename T>
void BinarySearchTree<T>::add(T key)
{
	Node<T>* temp = new Node<T>(key);
	
	if(!root)
		root = temp;
	else
		addHelper(root,temp);
}

template<typename T>
void BinarySearchTree<T>::disp()
{
	if(root)
	{
		dispHelper(root);
		cout << endl;
	}
	else
	{
		cout << "Tree is empty" << endl;
	}

}

// Helper function to add an element to the Binary Search Tree

template<typename T>
void BinarySearchTree<T>::addHelper(Node<T>* root, Node<T>* temp)
{
	if(root)
	{
		if(temp->key < root->key)
		{
			if(!root->left)
				root->left = temp;
			else
				addHelper(root->left,temp);
		}
		else
		{
			if(!root->right)
				root->right = temp;
			else
				addHelper(root->right,temp);
		}

	}
}

// Helper function for PreOrder traversal of the Binary Search Tree

template<typename T>
void BinarySearchTree<T>::dispHelper(Node<T>* root)
{
	if(root)
	{
		dispHelper(root->left);
		cout << root->key << " ";
		dispHelper(root->right);
	}
}