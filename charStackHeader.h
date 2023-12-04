#include<iostream>
using namespace std;

class Node
{
    public:
    char data;
    Node *next;
    Node(int val): data(val), next(NULL){}
};

class Stack
{
    Node *head;
    public:
    Stack(): head(NULL){}

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(char val)
    {
        Node * newNode = new Node(val);
        if(head == NULL)        //if stack is empty
        {
            head = newNode;
        }
        else                   //when stack has not emty 
        {
            newNode->next = head;
            head = newNode;
        }
    }

    char pop()
    {
        if(isEmpty())
        {
            cout << "Stack is empty " << endl;
        }
        else
        {   
            Node *ptr = head;
            head = head->next;
            delete ptr;
        }
    }

    char topVal()
    {
        if(isEmpty())
        {
            cout << "Stack is empty " << endl;
        }
        else
        {
            return head->data;
        }
    }
    void display()
    {
        if(isEmpty())
        {
            cout << "Stack is empty " << endl;
        }
        else
        {
            Node *ptr = head;
            while(ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            
        }
    }

};
