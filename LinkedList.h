
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T> *next;
};

template <typename T>
struct LinkedList
{
	Node<T> *head;
	Node<T> *tail;

	Node<T> *CreateNode(T init_data)
	{
		Node<T> *node = new Node<T>;
		node->data = init_data;
		node->next = NULL;
		return node;
	}

	void CreateList()
	{
		head = NULL;
		tail = NULL;
	}

	void AddHead(Node<T> *node)
	{
		if (head == NULL)
		{
			head = node;
			tail = node;
		}
		else
		{
			node->next = head;
			head = node;
		}
	}

	void AddTail(Node<T> *node)
	{
		if (head == NULL)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
	}

	void InsertAfterQ(Node<T> *p, Node<T> *q)
	{
		if (q != NULL)
		{
			p->next = q->next;
			q->next = p->next;
			if (tail == q)
				tail = p;
		}
		else
			AddHead(p);
	}

	int RemoveHead(int &x)
	{
		if (head != NULL)
		{
			Node<T> *node = head;
			x = node->data;
			head = node->next;
			delete node;
			if (head == NULL)
				tail = NULL;
			return 1;
		}
		return 0;
	}

	int RemoveTail(int &x);

	int RemoveAfterQ(Node<T> *q, int &x)
	{
		if (q != NULL)
		{
			Node<T> *p = q->next;
			if (p != NULL)
			{
				if (tail == p)
					tail = q;
				q->next = p->next;
				x = p->data;
				delete p;
				return 1;
			}
			return 0;
		}
		return 0;
	}
	Node<T> *Get(int index)
	{
		Node<T> *node = head;
		int i = 0;
		while (node != NULL && i != index)
		{
			node = node->next;
			i++;
		}
		if (i == index && node != NULL)
			return node;
		return NULL;
	}
	void PrintList()
	{
		if (head != NULL)
		{
			Node<T> *node = head;
			while (node != NULL)
			{
				cout << node->data << ' ';
				node = node->next;
			}
		}
	}
	Node<T> *Search(int x)
	{
		Node<T> *node = head;
		while (node != NULL && node->data != x)
			node = node->next;
		if (node != NULL)
			return node;
		return NULL;
	}

	int Length()
	{
		int count = 0;
		Node<T> *node = head;
		while (node != NULL)
		{
			count++;
			node = node->next;
		}
		return count;
	}

	void DestroyList()
	{
		int x;
		Node<T> *node = head;
		while (node != NULL)
		{
			RemoveHead(x);
			node = head;
		}
		tail = NULL;
	}
};

// int main()
// {
// 	// Create a linked list
// 	LinkedList<int> list;
// 	list.CreateList();

// 	// Add sample data to list
// 	Node<int> *node;
// 	for (int i = 1; i <= 10; i++)
// 	{
// 		// Create new node with init data is i
// 		node = list.CreateNode(i);

// 		// Add node to head
// 		// List that is added node by AddHead will be reversed
// 		// AddHead(list, node);

// 		// Add node to Tail
// 		list.AddTail(node);
// 	}

// 	// Print list
// 	list.PrintList();
// 	cout << endl;

// 	// Get list's length
// 	int len = list.Length();
// 	cout << "Length of list: " << len << endl;

// 	// Get node at index 7
// 	Node<int> *nodeAtIdx7 = list.Get(7);
// 	if (nodeAtIdx7 != NULL)
// 		cout << "Data at node have idx 7: " << nodeAtIdx7->data << endl;

// 	// Search for 4 in list
// 	Node<int> *search4InList = list.Search(4);
// 	if (search4InList != NULL)
// 		cout << "4 was founded" << endl;
// 	else
// 		cout << "4 not Found" << endl;

// 	// Remove node after 4 in list
// 	int x;
// 	int res = list.RemoveAfterQ(search4InList, x);
// 	if (res)
// 	{
// 		cout << "Data of node has been removed: " << x << endl;
// 		cout << "List after removed: ";
// 		list.PrintList();
// 		cout << endl;
// 	}
// 	else
// 		cout << "Nothing is removed" << endl;

// 	// Insert 2409 after node 4
// 	Node<int> *node2409 = list.CreateNode(2409);
// 	list.InsertAfterQ(node2409, search4InList);
// 	cout << "List after insert 2409 after 4: ";
// 	list.PrintList();
// 	cout << endl;

// 	// Remove Head
// 	res = list.RemoveHead(x);
// 	if (res)
// 	{
// 		cout << "Data of node has been removed: " << x << endl;
// 		cout << "List after removed head: ";
// 		list.PrintList();
// 		cout << endl;
// 	}
// 	else
// 		cout << "Nothing is removed" << endl;

// 	// Destroy all node
// 	list.DestroyList();

// 	return 0;
// }
