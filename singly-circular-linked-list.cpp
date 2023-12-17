#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
class SinglyCircularLinkedList{
    public:
    Node *head;
    SinglyCircularLinkedList(): head(NULL){};

    void insertNodeAtEnd(int val)
    {
        Node* newNode = new Node(val);
         if(head == NULL)   //if there is no node in the linked list
         {  
            head = newNode;
            newNode->next = head;
         }
         else   //if linked list contains one or more nodes
        {
            Node *ptr = head;
            while(ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = head;
        }
    }
    void insertNodeAtStart(int val)
    {
        Node *newNode = new Node(val);
        if(head == NULL)
         {  
            head = newNode;
            newNode->next = head;
         }
         else
         {
            Node *ptr = head;
            while(ptr->next != head)
            {
                ptr = ptr->next;
            }
            newNode->next = head;
            ptr->next = newNode;
            head = newNode;
         }
    }
    
    void insertAfter(int val, int pos)
    {
        if(head == NULL)
        {
            cout<<"the list is empty " << endl;
           
        }
        else
        {  
            Node *newNode = new Node(val);
            Node *ptr = head;
            
            while (ptr->data != pos)
            { // checks for the given node(vlue)
                if (ptr->next == head)
                {
                    cout << "match not found";
                    return;
                }
                ptr = ptr->next;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }

    void del(int pos)
	{
		Node *ptr = head, *q;
		if (head == NULL)
		{ // list is empty
			cout << "list is empty";
		}

		else if (head->next == head)
		{ //	only one item is present in the list 
			if (head->data == pos)
			{// the data of the node is =  pos
				cout << "only item is present in the list and the data of it is =  pos " << pos << endl;
				head = NULL;
				delete ptr;
				
			}
			else
			{// the data of the node is !=  pos
				cout << "value does not match" << endl;
			}
		}
		else
		{ // more than one nodes is present
			if (ptr->data == pos)
			{ // the deleting  node is at start
				
                while(ptr->next != head)
                {
                    ptr = ptr->next;
                }
                q = head;
                head = head->next;
                ptr->next = head;
				delete q;
			}
			else
			{ // the deleting node is in mid or at the end
			while (ptr->data != pos)
			{ // checks for the given node(vlue)
				if (ptr->next == head)
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
    }

    void display()
    {   
        if(head == NULL)
        {
            cout<<"list is emty";
            return;
        }
        Node *ptr = head;
        do
        {   
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        while(ptr != head);
        
    }
    
};
int main(){
    SinglyCircularLinkedList c;
    // c.insertNodeAtEnd(1);
    // c.insertNodeAtEnd(2);
    c.insertNodeAtStart(0);
    // c.insertNodeAtStart(-1);
    c.insertAfter(5,0);
    c.insertAfter(8,0);
    // c.insertAfter(11,9);
    cout << "display function is here before delete " << endl;
    c.display();
    c.del(5);
    cout<< endl << "display function is here after delete " << endl;
    c.display();
}