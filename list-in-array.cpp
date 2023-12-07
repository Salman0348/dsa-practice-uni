#include<iostream>
using namespace std;

int arr[50];
    
    int size = 0;
    int current = 0;

    void addItem(int val, int index)
    {   
        if( size == 50)     // if the array is full
        {
            cout << " list is full " << endl; 
            return;
        }

        if(index > size)
        {
          cout << "index is greater than the size of list " << endl;
          return;  
        }

        for(int i = size; i > index; i--) // this loop is for shifting the items of the list to the right(one index) untill the given index
        {
            arr[i] = arr[i-1];
        }
        arr[index] = val;
        size++;

    }

    void print()
    {
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
    }
int main(){
    addItem(1,0);
    addItem(2,1);
    addItem(3,2);
    addItem(4,3);
    addItem(5,4);
    addItem(10,2);
    cout << "size of the list is: " << size <<endl;
    cout << endl << "elements of the list are " << endl;
    print();
}