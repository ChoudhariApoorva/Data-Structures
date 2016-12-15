#include <iostream>
using namespace std;

// A linked list node consisting of a value and a pointer to the next node

template <typename T>
struct Node
{
	T key;
	struct Node* link;
	Node(T val):key(val), link(NULL){}
};

template <typename T>
struct List
{
	private:
		Node<T>* head;
	public:
		List<T>();
		void insert_end(T);
		void insert_beginning(T);
		int count_nodes();
		void disp_list();
		void delete_node(T);
};

/*

The following functions are supported by LinkedList : 
1) Display List
2) Insert an element in the end of the list
3) Insert an element in the beginning of the list
4) Count the number of nodes in the list
5) Delete all nodes with the given node value

*/

template <typename T>
List<T>::List()
{
	head = NULL;
}

template <typename T>
void List<T>::disp_list()
{
	Node<T>* temp = head;

	while(temp)
	{
		cout << temp->key << " ";
		temp = temp->link;
	}

	cout << endl;
}

template <typename T>
void List<T>::insert_end(T key)
{
	Node<T>* temp = new Node<T>(key);
	Node<T>* pres = head;
	Node<T>* prev = NULL;

	if(pres == NULL)
	{
		head = temp;
	}
	else
	{
		while(pres)
		{
			prev = pres;
			pres = pres->link;
		}

		prev->link = temp;
	}
}

template <typename T>
void List<T>::insert_beginning(T key)
{
	Node<T>* temp = new Node<T>(key);

	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->link = head;
		head = temp;
	}
}

template <typename T>
int List<T>::count_nodes()
{
	Node<T>* pres = head;
	int count = 0;

	while(pres)
	{
		++count;
		pres = pres->link;
	}

	return count;
}

template <typename T>
void List<T>::delete_node(T val)
{
	Node<T>* pres = head;
	Node<T>* prev = NULL;

	if(pres->key == val)
	{
		head = pres->link;
		pres->link = NULL;
		delete pres;
		pres = head;
	}
	
	while(pres)
	{
		prev = pres;
		pres = pres->link;

		if(pres && pres->key == val)
		{
			prev->link = pres->link;
			pres->link = NULL;	
			delete pres;
			pres = prev->link;
		}
	}
	
}
