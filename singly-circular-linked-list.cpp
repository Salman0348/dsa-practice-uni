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
        if(head == NULL)        //if the list is empty
        {
            cout<<"list is empty " <<endl;
            return;
        }
                                
        if(head->data == pos)       // if the deleting node is the head node
        {
            Node *lastNode = head;
            while(lastNode->next != head)   // to obatain the next of the last node 
            {
                lastNode = lastNode->next;
            }
        
            if(head == head->next)      //if there is only one node
            {
                delete head;
                head = NULL;

            }else // for more than one node, the last node should point to the second node after deletion
                {
                    lastNode->next = head->next;
                    Node *ptr = head;
                    head = head->next;
                    delete ptr;
                    
                } 
                return;    
        }else                   //the deleting node is not the head node
            {
                Node *p = head, *q = NULL;
                do
                {           //finding the pos valued node
                    if(p->data == pos)      
                    {
                        q->next = p->next;
                        return;
                    }
                    q = p;
                    p = p->next;
                } while (p != head);
                cout<< endl << "deletion match not found for "<< pos << endl;

                
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
    c.insertAfter(11,9);
    cout << "display function is here before delete " << endl;
    c.display();
    c.del(1);
    cout<< endl << "display function is here after delete " << endl;
    c.display();
}