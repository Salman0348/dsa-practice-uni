#include<iostream>
using namespace std;

class Node{
	public:
    int data;
    Node* next;
    
        Node(int d): data(d) , next(NULL){};
};
class SinglyLinkedList{
	Node* head;
	public:
	SinglyLinkedList(): head(NULL){};
								//function to insert a node at end
	void insertEnd(int val){
		Node* newNode = new Node(val);
	
		
		if(head==NULL)				//if there is no node, this node node will be the first node.
		head=newNode;
		else{
			Node* ptr = head;
			while(ptr->next !=NULL){			//if there are one or more node available the new node will be add to the last node.
				ptr = ptr->next;			
					}
				ptr->next = newNode;
			
		}
			
	}
								//function to insert a node at the start
	void insertStart(int val){
		Node* newNode = new Node(val);
		if(head == NULL){			//if node initially, newly created node will be the first node.
			head=newNode;
			}
			else{					//if there are one or more nodes then the newly created node will add to the first node.
				newNode->next=head;
				head = newNode;
				}
	}

	void insertAfter(int val, int pos){
		
		Node* newNode = new Node(val);
		Node* ptr=head;
		while(ptr->data != pos){ 		//checks for the given node(node)
			if(ptr->next == NULL){
				cout<<"match not found";
				return;
			}
			ptr = ptr->next;
			}
			newNode->next = ptr->next;
			ptr->next = newNode;
			
	}
	
	void display(){
		Node*ptr =head;
		while(ptr){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
		}
	}
	
};


int main(){
	SinglyLinkedList s1;
	s1.insertEnd(1);
	s1.insertEnd(2);
	s1.insertEnd(3);
	s1.insertEnd(4);
	s1.insertStart(0);
	s1.insertAfter(99,2);
	s1.display();

}