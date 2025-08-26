// 1
#include<stdio.h>
#include<iostream>
using namespace std;
#define MAXLEN 100

class stack{
    int element[5];
    int top=-1;

public:
    int isFull()
    {
        if (top==4) //MAXLEN-1
            return 1;
                //wait for else
        else
          return 0;

          //return (top==4)
    }
    void push(int x)
    {
        if(isFull())
            cout<<"\n Overflow";
        else
            top++;
            element[top]= x;
    }
    void display()
    {
        for (int i=top;i>=0;i--)
            cout<<element[i]<<endl;
    }
    int isEmpty()
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }
    void topp() //peek()
    {
        if(isEmpty())
        {
            cout<<"Underflow";
        }
        else
            cout<<element[top];
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Underflow";
        }
        else
            top--;
    }


};


int main()
{
    stack S;
    for (int i=0;i<=4;i++)
        S.push(10+i);
    S.display();
    S.push(50);
    //S.display();
    cout<<"Top element is ";
    S.topp();
}

// 2
#include <iostream>
#include <stack>
#include <string>
using namespace std;
string reverseString(string str) {
    stack<char> s;
    // Push all characters of the string to the stack
    for (char c : str) {
        s.push(c);
    }
    // Pop all characters from the stack and build the reversed string
    string reversedStr = "";
    while (!s.empty()) {
        reversedStr += s.top();
        s.pop();
    }
    return reversedStr;
}
int main() {
    string str = "DataStructure";
    string reversedStr = reverseString(str);
    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversedStr << endl;
    return 0;
}
