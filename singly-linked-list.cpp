#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int d){
		this->data = d;
		this->next = NULL;
	};
};
class SinglyLinkedList
{
	Node *head;

public:
	SinglyLinkedList() 
	{
		head = NULL;
	};
	// function to insert a node at end
	void insertEnd(int val)
	{
		Node *newNode = new Node(val);

		if (head == NULL) // if there is no node, this node node will be the first node.
			head = newNode;
		else
		{
			Node *ptr = head;
			while (ptr->next != NULL)
			{ // if there are one or more node available the new node will be add to the last node.
				ptr = ptr->next;
			}
			ptr->next = newNode;
		}
	}
	// function to insert a node  at the start
	void insertStart(int val)
	{
		Node *newNode = new Node(val);

		newNode->next = head;
		head = newNode;
	}

	void insertAfter(int val, int pos)
	{

			Node *newNode = new Node(val);
			Node *ptr = head;
			while (ptr->data != pos)
			{ // checks for the given node(vlue)
				if (ptr->next == NULL)
				{
					cout << "match not found";
					return;
				}
				ptr = ptr->next;
			}
			newNode->next = ptr->next;
			ptr->next = newNode;
	}
	void deleteNode(int pos)
	{
		Node *ptr = head, *q;
		if (head == NULL)
		{ // list is empty
			cout << "list is empty";
			return;
		}

			if (ptr->data == pos)
			{ // the deleting  item is at start
				head = ptr->next;
				delete ptr;
			}
			else
			{ // the deleting item is in mid or at the end
			while (ptr->data != pos)
			{ // checks for the given node(vlue)
				if (ptr->next == NULL)
				{
					cout << "match not found for delete";
					return;
				}
				q = ptr;
				ptr = ptr->next;
			}
			q->next = ptr->next;
			delete ptr;
			
			}
		}
	

	void display()
	{
		Node *ptr = head;
		while (ptr)
		{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
};

int main()
{
	SinglyLinkedList s1;
	s1.insertEnd(1);
	s1.insertEnd(1);
	s1.insertEnd(1);
	s1.insertStart(0);
	s1.insertStart(1);
	s1.insertEnd(2);
	s1.insertAfter(99,1);
	cout<<"display befor delete"<<endl;
	s1.display();
	s1.deleteNode(1);
	cout<<endl<<"display after delete"<<endl;
	s1.display();
}
