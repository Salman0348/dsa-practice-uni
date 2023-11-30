#include<iostream>
using namespace std;

int main(){
	
	char ch;
	cout<<"Enter a charater"<<endl;
	cin>>ch;
	
	if((ch>='a')&&(ch<='z')){
		cout<<"small alphabet";
	}
	else if((ch>='A')&&(ch<='Z')){
		cout<<"capital letter";
	}
	else{
		cout<<"numeric value";
		}
}
