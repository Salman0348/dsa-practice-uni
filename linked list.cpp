#include<iostream>
using namespace std;

struct Node{
	int a;
	Node* next;
};


int main(){
	Node* node = new Node;
	
	int b=2;
	int* c = &b;
	cout<<c;
}
