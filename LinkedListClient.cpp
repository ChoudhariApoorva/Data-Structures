#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

int main()
{
	List<int> L = List<int>();

	L.insert_end(10);
	L.insert_end(20);
	L.insert_end(30);
	L.insert_beginning(5);
	L.insert_beginning(1);
	L.insert_beginning(5);
	L.disp_list();

	cout << "Number of nodes in the list = " << L.count_nodes() << endl;

	L.delete_node(5);
	L.disp_list();

	return 0;
}

/* Sample Output :

5 1 5 10 20 30 
Number of nodes in the list = 6
1 10 20 30 

*/