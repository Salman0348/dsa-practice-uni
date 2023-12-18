#include<iostream>
using namespace std;

class Queue
{
    public:
    int front, rear, size, noOfElements;
    int * arr = new int[size];
    Queue(int size)
    {
        this->front = this->rear = -1;
        noOfElements = 0;
        this->size = size;
    }

    void enQueue(int val)
    {
        if(noOfElements == size)
        {
            cout << "queue is full" << endl;
            return;
        }
        if(front == -1) //special condition
            front++;

        rear = (rear + 1)%size;
        arr[rear] = val;
        noOfElements++;
    }

    int deQueue()
    {
        if(front == -1)
        {
            cout << "Queue is empty";
            return -1;
        }
        int val = arr[front];
        if(front == rear)   //special condition
        {
            front = rear = -1;
            return val;
        }
        front = (front+1)%size;
        noOfElements--;
        return val;

    }
    int first(){
        if(front == -1)
        {
            cout << "list is empty.";
            return -1;
        }
        return arr[front];
    }
    void display()
    {   
        if(front == -1)
        {
            cout << " queue is empty";
            return;
        }
        int i = front;
        do
        {
            cout << arr[i] << " ";
            i = (i+1)%size;
        }while( i != (rear+1)%size);
    }
};

int main()
{
    Queue q(5);
    q.enQueue(5);
    q.enQueue(2);
    q.enQueue(4);
    q.enQueue(1);
    q.enQueue(3);
    q.enQueue(13);
    // q.deQueue();
    // q.deQueue();
    q.enQueue(10);
    cout << endl << "this is the first value: " << q.first() << endl;
    q.display();
}
    