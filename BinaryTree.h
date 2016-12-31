#include <iostream>
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
		Node* root;
	public:
		BinaryTree();
		void disp();
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
		cout
	}
}
