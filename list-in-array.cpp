#include<iostream>
using namespace std;

class List
{   
    public:
      int arr1[50];
     
    int size;
    List(){
      size =0;
   
    }


    void addItem(int val,  int index)
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
            arr1[i] = arr1[i-1];
        }
        arr1[index] = val;
        size++;

    }

    void deleteItem(int index)
    {
        for(int i =  index; i < size; i++)
        {
            arr1[i] = arr1[i+1];
        }
        size--;

    }

    void copyList(int arr1[], int arr2[])
    {
        for(int i = 0; i < size; i++)
        {
            arr2[i] = arr1[i];
        }
    }

    void clear()
    {
        size = 0;
    }

    int get(int index)
    {
        return arr1[index];
    }
    void replace(int i,int val){
    	arr1[i]=val;
	}
    int find(int val)
    {
        for(int i = 0; i < size; i++)
        {
            if(arr1[i] == val)
            {
                return i;
            }
        }
        cout << endl << "value does not exist in the list " << endl;
    }
    void print(int arr[])
    {   
        if(size == 0)
        {
            cout << " list is empty " << endl;
            return;
        }
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
    }
};
int main(){
    List l1;
    int arr2[50];
    l1.addItem(1,0);
    l1.addItem(2,1);
    l1.addItem(3,2);
    l1.addItem(4,3);
    l1.addItem(5,4);
    l1.addItem(10,2);
    l1.replace(3,9);
    // l1.clear();
    cout << endl << "arr1: ";
    l1.print(l1.arr1);
    cout << endl << "index of the given value is : " << l1.find(20);

    // cout << endl << " this is the value at the given index " << l1.get(2);
    // l1.copyList(l1.arr1, arr2);
    // cout << endl << "arr2: ";
    // l1.print(arr2);
//     cout << "size of the list is: " << l1.size <<endl;
//     cout << endl << "elements of the list before deletetion are: " << endl;
//     l1.print(l1.arr1);
//     l1.deleteItem(2);
//     cout << endl << "array after deletetion: " << endl;
//     l1.print(l1.arr1);
//
}