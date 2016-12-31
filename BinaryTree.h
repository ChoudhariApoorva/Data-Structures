#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node
{
	T key;
	struct Node* left;
	struct Node* right;
	Node(T key):key(key),left(NULL),right(NULL){}
};

template <typename T>
class BinaryTree
{
	private:
		Node<T>* root;
		void dispHelper(Node<T>*);
		void addHelper(Node<T>*, Node<T>*, string);
	public:
		BinaryTree();
		void disp();
		void add(T,string dir="");
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
}

template <typename T>
void BinaryTree<T>::disp()
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

template <typename T>
void BinaryTree<T>::add(T key, string dir)
{
	Node<T>* temp = new Node<T>(key);

	if(!root)
	{
		root = temp;
	}
	else
	{
		addHelper(root,temp,dir);
	}
}	

template <typename T>
void BinaryTree<T>::dispHelper(Node<T>* root)
{
	if(root)
	{
		dispHelper(root->left);
		cout << root->key << " ";
		dispHelper(root->right);
	}
}

template <typename T>
void BinaryTree<T>::addHelper(Node<T>* root, Node<T>* temp, string dir)
{
	int len = dir.size();
	Node<T>* prev = NULL;
	Node<T>* pres = root;
	int i;

	for(i=0;i<len;++i)
	{
		if(pres)
		{
			if(dir[i] == 'L')
			{
				prev = pres;
				pres = pres->left;
			}
			else if(dir[i] == 'R')
			{
				prev = pres;
				pres = pres->right;
			}
		}
		else
		{
			cout << "Invalid directions" << endl;
			exit(1);
		}
	}

	if(dir[i-1] == 'L' && pres == NULL)
	{
		prev->left = temp;
	}
	else if(dir[i-1] == 'R' && pres == NULL)
	{
		prev->right = temp;
	}
}

