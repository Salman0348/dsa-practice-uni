#include<iostream>
#include<string>
#include "charStackHeader.h"
using namespace std;

int prd(char ch)
{
    if(ch == '^')
    {
        return 3;
    }
    else if(ch == '*' || ch == '/')
    {
        return 2;
    }
    else if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(Stack s, const string& infix)
{
    string postfix;
    for(int i = 0; i < infix.length(); i++)
    {
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
        }
        else if(infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while((s.topVal() != '(') && (!s.isEmpty()))
            {
                postfix += s.topVal();
				s.pop();
            }
            if(s.topVal() == '(')
            {
                s.pop();
            }
        }
        else
        {
            if(s.isEmpty())
            {
                s.push(infix[i]);
            }
            else
            {
                if(prd(infix[i]) > prd(s.topVal()))
                {
                    s.push(infix[i]);
                }
                else if(prd(infix[i]) < prd(s.topVal()))
                {
                    while((!s.isEmpty()) && (prd(infix[i]) <= prd(s.topVal())))
                    {
                        postfix += s.topVal();
				        s.pop();
                    }
                    s.push(infix[i]);
                }
                else
                {
                    if(infix[i] == '^')
                    {
                        postfix += infix[i];
                    }
                    else
                    {
				        postfix += s.topVal();
				        s.pop();
                        s.push(infix[i]);
                    }
                }
            }
        }
    }

    while(!s.isEmpty())
    {
        postfix += s.topVal();
        s.pop();
    }

    return postfix;
}

int main()
{	
	Stack s1;
	string infix;
	int choice;

    do
    {	
       	 	cout << endl << "1 for Entering an infix expression: " << endl;
   	 	
   	 		cout << "0 for  for exit " << endl;
   	 		cin>> choice;
	switch(choice)
   	 	{

	    	case 1:
	    		cout << "Enter an infix expression: " << endl;
				cin >> infix;
			
		    
		    	cout << "Postfix form: " << endl;
		    	cout << infixToPostfix(s1, infix) << endl;
		    	break;
			case 0:
		    	cout << "Exiting programm" << endl;
		    	break;
			default:
				cout << "inavalid choice " << endl;
	    			
		}

	}while(choice != 0);

    return 0;
}
