#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
	BinarySearchTree<int> T;
	T.add(10);
	T.add(5);
	T.add(20);
	T.add(15);
	T.add(40);

	T.disp();

	return 0;
}

/* 

	10
    / \
   5  20
      / \
     15  40

Sample output - Inorder tree traversal
5 10 15 20 40

*/