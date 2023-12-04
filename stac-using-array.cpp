#include<iostream>
using namespace std;

class Stack
{
    int top = -1;
    int size = 5;
    // let the stack be of int type
    int arr[5];
    public:
    bool isFull()
    {
        return (top == size-1);
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    void push(int val)
    {
        if(isFull())
        {   
            cout << endl << "stack overflow " << endl;
        }
        else
        {
            arr[++top] = val;
        }
    }

    int pop()
    {
        if(isEmpty())
        {
            cout << endl << "Stack underflow " << endl;
        }
        else
        {
            return (arr[top--]);
        }
    }

    int topVal()
    {
        return arr[top];
    }
    
    void display()
    {	
    	if(isEmpty())
    	{
    		cout << "The stack is empty " << endl;
		}
		else
		{
	    	int i = 0;
	    	while(i <= top)
	    	{
	    		cout << arr[i];
	    		i++;
		}
		}

	}
};


int main(){
Stack s1;
s1.isEmpty();
s1.push(1);
s1.push(2);
s1.push(3);
s1.push(4);
s1.pop();
cout << endl << "top value " << s1.topVal() << endl;
s1.display();




}