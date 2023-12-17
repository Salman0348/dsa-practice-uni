#include<iostream>
using namespace std;


class Node
{
    public:
        int data;
        Node* next;
    Node(int data){
        this->data =data;
         this->next = NULL;
        
    }
   
};

class Queue
{
    public:
    Node* head, *rear;
    Queue()
    {
        head = NULL;
        rear = NULL;
    }

    void enQueue(int val)
    {   
        Node *newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            rear = newNode; 
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        
    }

    int deQueue()
    {
        if(head == NULL)
        {
            cout << endl << "Queue is empty" << endl;
            return 0;
        }
        int val = head->data;

        Node *ptr = head;
        head = head->next;
        delete ptr; 

        return val;
    }

    int isEmpty()
    {
        return (head == NULL);
    }

    int front()
    {
        return head->data;
    }

    void display()
    {
        if(isEmpty())
        {
            cout << "the Queue is empty" << endl;
            return;
        }
        Node *ptr = head;
        while(ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }

    }

};

int main()
{
    Queue q;

    q.enQueue(2);
    
    q.enQueue(5);
    q.enQueue(24);
    q.display();
}
