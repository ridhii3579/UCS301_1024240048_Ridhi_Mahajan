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

// 3
#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced Expression\n";
    else
        cout << "Not Balanced\n";

    return 0;
}

//4
#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {  // Operand
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // remove '('
        }
        else { // Operator
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

// 5
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> s;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');  // convert char to int
        }
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (use digits only): ";
    cin >> postfix;

    cout << "Evaluated result: " << evaluatePostfix(postfix) << endl;

    return 0;
}

// Additional Questions 1
#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmaller(vector<int>& A) {
    vector<int> res;
    stack<int> s;

    for (int x : A) {
        while (!s.empty() && s.top() >= x)
            s.pop();
        if (s.empty()) res.push_back(-1);
        else res.push_back(s.top());
        s.push(x);
    }
    return res;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> ans = nearestSmaller(A);
    for (int x : ans) cout << x << " ";
    return 0;
}

// Additioanal Questions 2
#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<long long> s;
    long long minElement;

public:
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minElement = x;
        } else {
            if (x >= minElement) {
                s.push(x);
            } else {
                s.push(2LL * x - minElement);
                minElement = x;
            }
        }
    }

    void pop() {
        if (s.empty()) return;
        long long t = s.top();
        s.pop();
        if (t < minElement) {
            minElement = 2LL * minElement - t;
        }
    }

    int top() {
        long long t = s.top();
        if (t < minElement) return minElement;
        return t;
    }

    int getMin() {
        return minElement;
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    SpecialStack st;
    st.push(3);
    st.push(5);
    cout << st.getMin() << endl; // 3
    st.push(2);
    st.push(1);
    cout << st.getMin() << endl; // 1
    st.pop();
    cout << st.getMin() << endl; // 2
    st.pop();
    cout << st.top() << endl;    // 5
    return 0;
}

// Additional Questions 3
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
        if (!s.empty()) res[i] = s.top();
        s.push(arr[i]);
    }
    return res;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> ans = nextGreater(arr);
    for (int x : ans) cout << x << " ";
    return 0;
}

// Additional Questions 4
#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> res(n, 0);
    stack<int> s; // stores indices

    for (int i = 0; i < n; i++) {
        while (!s.empty() && T[i] > T[s.top()]) {
            int idx = s.top(); s.pop();
            res[idx] = i - idx;
        }
        s.push(i);
    }
    return res;
}

int main() {
    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(temp);
    for (int x : ans) cout << x << " ";
    return 0;
}

// Additional Questions 5
#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> res(n, 0);
    stack<int> s; // stores indices

    for (int i = 0; i < n; i++) {
        while (!s.empty() && T[i] > T[s.top()]) {
            int idx = s.top(); s.pop();
            res[idx] = i - idx;
        }
        s.push(i);
    }
    return res;
}

int main() {
    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(temp);
    for (int x : ans) cout << x << " ";
    return 0;
}
