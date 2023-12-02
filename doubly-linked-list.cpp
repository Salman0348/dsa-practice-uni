#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;

    Node(int d) : data(d), next(NULL), prev(NULL){};
};
class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList() : head(NULL){};
    // function to insert a node at end
    void insertEnd(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        { // if there is no node, this node node will be the first node.
            head = newNode;
            return;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            { // if there are one or more node available the new node will be add to the last node.
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->prev = ptr;
        }
    }
    // function to insert a node at the start
    void insertStart(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        { // if there is no node, this node node will be the first node.
            head = newNode;
            return;
        }
        else
        { // if there are one or more nodes then the newly created node will add to the first node.
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAfter(int val, int pos)
    {

        Node *newNode = new Node(val);
        Node *ptr = head;
        while (ptr->data != pos)
        { // checks for the given node(node)
            if (ptr->next == NULL)
            {
                cout << "match not found";
                return;
            }
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next->prev = newNode;
        ptr->next = newNode;
        newNode->prev = ptr;
    }
    void deleteNode(int pos)
    {
        Node *ptr = head;
        if (head == NULL)
        { // list is empty
            cout << "list is empty";
            return;
        }
        else if (head->next == NULL)
        { //	one node is present in the list and the data of it is =  pos
            if (head->data == pos)
            {
                head = NULL;
                delete ptr;
                return;
            }
            else
            {
                //	one node is present in the list and the data of it is !=  pos
                cout <<endl << pos << " value does not match" << endl;
            }
        }
        else
        { // more than one nodes is present
            if (ptr->data == pos)
            { // the deleting node is the first node
                head = ptr->next;
                ptr->next->prev = NULL;
                delete ptr;
                return;
            }
            else
            { // the deleting node is in between or at the end
                while (ptr != NULL)
                {
                    if (ptr->data == pos)
                    {   
                        if(ptr->next == NULL)   //if the node is the last
                        {
                            ptr->prev->next = ptr->next;
                            delete ptr;
                        }
                        else                
                        {                       //if the node is in between
                            ptr->prev->next = ptr->next;
                            ptr->next->prev = ptr->prev;
                            delete ptr;
                        }
       

                        return;
                    }
                    ptr = ptr->next;
                }
                cout << endl<< "Node not found for " << pos << endl;
            }
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
    }
};

int main()
{
    DoublyLinkedList s1;
    s1.insertEnd(1);
    // s1.insertEnd(2);
    // s1.insertEnd(3);
    // s1.insertEnd(4);
    // s1.insertStart(0);
    // s1.insertAfter(99, 2);
    cout << "display befor delete" << endl;
    s1.display();
    s1.deleteNode(3);
    cout << endl
         << "display after delete" << endl;
    s1.display();
}
