#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	BinaryTree<int> T;
	T.add(5);
	T.add(10,"L");
	T.add(20,"R");
	T.add(30,"LR");
	T.add(40,"LL");
	T.add(50,"RL");
	T.add(60,"RR");
	
	T.disp();

	return 0;
}

/*

	5
	/   \
  		10     20
      / \    / \
     40 30  50 60

Sample output - Inorder tree traversal
40 10 30 5 50 20 60

 */