#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
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

    void push(int val)
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

    int pop()
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

    int topVal()
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
int main()
{
   Stack s1; 
   cout << endl << "1 for empty, 0 for non emty : " << s1.isEmpty() << endl;
   s1.push(4);
   s1.push(3);
   s1.push(5);
   s1.display();
   cout << endl << "1 for empty, 0 for non emty : " << s1.isEmpty() << endl;
   s1.pop();
   cout << "display after pop " << endl;
   s1.display();
   

}