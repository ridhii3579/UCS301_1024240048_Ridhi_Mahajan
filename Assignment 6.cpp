// 1
#include <iostream>
using namespace std;

// Doubly Linked List Node
struct DoublyLinkedListNode {
    int data;
    DoublyLinkedListNode *next, *prev;
    DoublyLinkedListNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
public:
    DoublyLinkedListNode* head;
    DoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        DoublyLinkedListNode* node = new DoublyLinkedListNode(val);
        if (head) { node->next = head; head->prev = node; }
        head = node;
    }

    void insertAtEnd(int val) {
        DoublyLinkedListNode* node = new DoublyLinkedListNode(val);
        if (!head) { head = node; return; }
        DoublyLinkedListNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = node;
        node->prev = temp;
    }

    void insertAfter(int key, int val) {
        DoublyLinkedListNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Key not found\n"; return; }
        DoublyLinkedListNode* node = new DoublyLinkedListNode(val);
        node->next = temp->next;
        node->prev = temp;
        if (temp->next) temp->next->prev = node;
        temp->next = node;
    }

    void deleteNode(int key) {
        DoublyLinkedListNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Not found\n"; return; }
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    void search(int key) {
        DoublyLinkedListNode* t = head; int pos = 1;
        while (t) {
            if (t->data == key) { cout << "Found at " << pos << endl; return; }
            pos++; t = t->next;
        }
        cout << "Not found\n";
    }

    void display() {
        DoublyLinkedListNode* t = head;
        cout << "DoublyLinkedList: ";
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
};

// Circular Linked List Node
struct CircularLinkedListNode {
    int data;
    CircularLinkedListNode* next;
    CircularLinkedListNode(int val): data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    CircularLinkedListNode* head;
    CircularLinkedList(): head(nullptr) {}

    void insertEnd(int val) {
        CircularLinkedListNode* node = new CircularLinkedListNode(val);
        if (!head) { head = node; node->next = head; return; }
        CircularLinkedListNode* t = head;
        while (t->next != head) t = t->next;
        t->next = node; node->next = head;
    }

    void deleteNode(int key) {
        if (!head) return;
        CircularLinkedListNode *curr = head, *prev = nullptr;
        while (curr->data != key) {
            if (curr->next == head) { cout << "Not found\n"; return; }
            prev = curr; curr = curr->next;
        }
        if (curr == head && curr->next == head) { delete curr; head = nullptr; return; }
        if (curr == head) {
            prev = head;
            while (prev->next != head) prev = prev->next;
            head = head->next;
            prev->next = head;
        } else prev->next = curr->next;
        delete curr;
    }

    void search(int key) {
        if (!head) { cout << "Empty\n"; return; }
        CircularLinkedListNode* t = head; int pos = 1;
        do {
            if (t->data == key) { cout << "Found at " << pos << endl; return; }
            pos++; t = t->next;
        } while (t != head);
        cout << "Not found\n";
    }

    void display() {
        if (!head) { cout << "Empty\n"; return; }
        CircularLinkedListNode* t = head;
        cout << "Circular Linked List: ";
        do { cout << t->data << " "; t = t->next; } while (t != head);
        cout << endl;
    }
};

// Main driver
int main() {
    DoublyLinkedList DoublyLinkedList;
    CircularLinkedList CircularLinkedList;
    int ch, val, key;
    do {
        cout << " 1.DoublyLinkedList InsertBegin\n 2.DoublyLinkedList InsertEnd\n 3.DoublyLinkedList InsertAfter\n 4.DoublyLinkedList Delete\n 5.DoublyLinkedList Search\n 6.DoublyLinkedList Display\n";
        cout << " 7.CircularLinkedList Insert\n 8.CircularLinkedList Delete\n 9.CircularLinkedList Search\n 10.CircularLinkedList Display\n 11.Exit\nChoice: ";
        cin >> ch;
        switch(ch) {
            case 1: cout<<"Val:";cin>>val;DoublyLinkedList.insertAtBeginning(val);break;
            case 2: cout<<"Val:";cin>>val;DoublyLinkedList.insertAtEnd(val);break;
            case 3: cout<<"Key Val:";cin>>key>>val;DoublyLinkedList.insertAfter(key,val);break;
            case 4: cout<<"Key:";cin>>key;DoublyLinkedList.deleteNode(key);break;
            case 5: cout<<"Key:";cin>>key;DoublyLinkedList.search(key);break;
            case 6: DoublyLinkedList.display();break;
            case 7: cout<<"Val:";cin>>val;CircularLinkedList.insertEnd(val);break;
            case 8: cout<<"Key:";cin>>key;CircularLinkedList.deleteNode(key);break;
            case 9: cout<<"Key:";cin>>key;CircularLinkedList.search(key);break;
            case 10: CircularLinkedList.display();break;
            case 11: return 0;
        }
    } while (true);
}


// 2
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr) {}
};

int main() {
    Node *head = nullptr, *temp = nullptr;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> val;
        Node* newNode = new Node(val);
        if (!head) head = temp = newNode;
        else { temp->next = newNode; temp = newNode; }
    }
    temp->next = head;

    temp = head;
    cout << "Output: ";
    do { cout << temp->data << " "; temp = temp->next; } while (temp != head);
    cout << head->data << endl; 
}

// 3
#include <iostream>
using namespace std;

struct DoublyLinkedListNode { int data; DoublyLinkedListNode* next; DoublyLinkedListNode* prev; DoublyLinkedListNode(int v):data(v),next(nullptr),prev(nullptr){} };
struct CircularLinkedListNode { int data; CircularLinkedListNode* next; CircularLinkedListNode(int v):data(v),next(nullptr){} };

int main() {
    // Doubly Linked List
    DoublyLinkedListNode *head1 = new DoublyLinkedListNode(1), *n2 = new DoublyLinkedListNode(2), *n3 = new DoublyLinkedListNode(3);
    head1->next = n2; n2->prev = head1; n2->next = n3; n3->prev = n2;
    int count1=0; for (DoublyLinkedListNode* t=head1;t;t=t->next) count1++;
    cout << "Size of Doubly Linked List: " << count1 << endl;

    // Circular Linked List
    CircularLinkedListNode *head2=new CircularLinkedListNode(10), *b=new CircularLinkedListNode(20), *c=new CircularLinkedListNode(30);
    head2->next=b; b->next=c; c->next=head2;
    int count2=0; CircularLinkedListNode* t=head2;
    do{count2++;t=t->next;}while(t!=head2);
    cout << "Size of Circular Linked List: " << count2 << endl;
}


// 4
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char c) : data(c), next(nullptr), prev(nullptr) {}
};

void display DoublyLinkedList(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* tail = head;
    cout << "Forward Doubly Linked List: ";
    while (tail) {
        cout << tail->data << " ";
        if (!tail->next) break;
        tail = tail->next;
    }
    cout << endl;
    
    cout << "Backward Doubly Linked List: ";
    while (tail) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* tail = head;
    while (tail->next)
        tail = tail->next;

    while (head && tail && head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter a word: ";
    cin >> s;

    Node *head = nullptr, *tail = nullptr;
    for (char c : s) {
        Node* newNode = new Node(c);
        if (!head)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    display DoublyLinkedList(head);

    if (isPalindrome(head))
        cout << "The given doubly linked list is a palindrome." << endl;
    else
        cout << "The given doubly linked list is not a palindrome." << endl;

    return 0;
}


// 5
#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };

bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp=head->next;
    while (temp && temp!=head)
        temp=temp->next;
    return temp==head;
}

int main() {
    Node *a=new Node(2), *b=new Node(4), *c=new Node(6);
    a->next=b; b->next=c; c->next=a; // circular
    cout<<(isCircular(a)?"Provided List is a Circular Linked List":"Provided List is not a Circular Linked List");
}

// Additional Questions 1
#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };

void splitList(Node* head, Node*& head1, Node*& head2) {
    if (!head) return;
    Node* slow=head; Node* fast=head;
    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next; fast=fast->next->next;
    }
    head1=head;
    if(head->next!=head) head2=slow->next;
    fast->next=slow->next;
    slow->next=head;
}

int main() {
    Node *head=new Node(10), *b=new Node(4), *c=new Node(9);
    head->next=b; b->next=c; c->next=head;
    Node *h1=nullptr,*h2=nullptr;
    splitList(head,h1,h2);
    Node* t=h1;
    cout<<"List 1: "; do{cout<<t->data<<" ";t=t->next;}while(t!=h1);
    cout<<"\nList 2: "; t=h2; do{cout<<t->data<<" ";t=t->next;}while(t!=h2);
}

// Additional Questions 2
#include <iostream>
using namespace std;
int parityCount(int n){int c=0;while(n){if(n&1)c++;n>>=1;}return c;}

struct DNode{int d;DNode*next;DNode*prev;DNode(int v):d(v),next(nullptr),prev(nullptr){}};

int main(){
    DNode* h=new DNode(18);DNode* b=new DNode(15);DNode* c=new DNode(8);
    DNode* d=new DNode(9);DNode* e=new DNode(14);
    h->next=b;b->prev=h;b->next=c;c->prev=b;c->next=d;d->prev=c;d->next=e;e->prev=d;

    DNode* t=h;
    while(t){DNode* nxt=t->next; if(parityCount(t->d)%2==0){
        if(t->prev)t->prev->next=t->next;
        if(t->next)t->next->prev=t->prev;
        if(t==h)h=t->next;
    }t=nxt;}
    cout<<"After remove even-parity: ";
    for(DNode* x=h;x;x=x->next)cout<<x->d<<" ";
}

// Additional Questions 3
#include <iostream>
using namespace std;
struct Node{int d;Node*next;Node*prev;Node(int v):d(v),next(nullptr),prev(nullptr){}};

Node* reverseK(Node* head,int k){
    Node* curr=head,*next=nullptr,*prev=nullptr;int cnt=0;
    while(curr&&cnt<k){next=curr->next;curr->next=prev;curr->prev=next;prev=curr;curr=next;cnt++;}
    if(next) head->next=reverseK(next,k);
    if(head->next) head->next->prev=head;
    return prev;
}
int main(){
    Node *h=new Node(1),*a=new Node(2),*b=new Node(3),*c=new Node(4),*d=new Node(5),*e=new Node(6);
    h->next=a;a->prev=h;a->next=b;b->prev=a;b->next=c;c->prev=b;c->next=d;d->prev=c;d->next=e;e->prev=d;
    int k=2;h=reverseK(h,k);
    Node*t=h;while(t){cout<<t->d<<" ";t=t->next;}
}

// Additional Questions 4
#include<iostream>
using namespace std; 

// Node of a doubly linked list
class Node
{
    public:
    int data;
    // Pointer to next node in DLL
    Node *next;
      
      // Pointer to previous node in DLL
    Node *prev;

    Node():prev(NULL),next(NULL){}
    Node(int data):data(data),prev(NULL),next(NULL){}

};
class doublell
{
    public:
    Node *head;
    // Function to append node in the DLL
    void appendNode(Node *n)
    {
        Node *temp=head;
        if(temp==NULL)
        {
            head=n;
            
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;
            n->prev=temp;
        }
    }
      // Function to print the DLL
    void print()
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
      // Function to print reverse of the DLL
    void printReverse()
    {
        Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ->";
            temp=temp->prev;
        }
        cout<<endl;
    }
    // Function to correct the random pointer
    void correctPointer()
    {
        if(!head)
        {
            return;
        }
        Node *temp=head;
        while(temp->next!=NULL)
        {
            if(temp->next->prev!=temp)
            {
                temp->next->prev=temp;
            }
            temp=temp->next;
        }
    }
};

// Driver Code
int main() 
{ 
  
    // Creating a DLL 
    doublell ll;
    ll.head = new Node(1); 
    ll.head->next = new Node(2); 
    ll.head->next->prev = ll.head; 
    ll.head->next->next = new Node(3); 
    ll.head->next->next->prev =ll.head; 
    ll.head->next->next->next = new Node(4); 
    ll.head->next->next->next->prev = ll.head->next->next; 
  
    cout << "\nIncorrect Linked List: "; 
    ll.print(); 
    ll.printReverse();
  
    ll.correctPointer(); 
  
    cout << "\nCorrected Linked List: "; 
    ll.print(); 
    ll.printReverse();

  
    return 0; 
}

// Additional Questions 5
#include <iostream>
using namespace std;

// define dimension of matrix
#define dim 3

// struct node of doubly linked
// list with four pointer
// next, prev, up, down
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
};

// function to create a new node
Node* createNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    temp->up = NULL;
    temp->down = NULL;
    return temp;
}

// function to construct the
// doubly linked list
Node* constructDoublyListUtil(
    int mtrx[][dim],
    int i, int j,
    Node* curr)
{

    if (i >= dim || j >= dim) {
        return NULL;
    }

    // Create Node with value contain
    // in matrix at index (i, j)
    Node* temp = createNode(mtrx[i][j]);

    // Assign address of curr into
    // the prev pointer of temp
    temp->prev = curr;

    // Assign address of curr into
    // the up pointer of temp
    temp->up = curr;

    // Recursive call for next pointer
    temp->next
        = constructDoublyListUtil(
            mtrx, i, j + 1, temp);

    // Recursive call for down pointer
    temp->down
        = constructDoublyListUtil(
            mtrx, i + 1, j, temp);

    // Return newly constructed node
    // whose all four node connected
    // at it's appropriate position
    return temp;
}

// Function to construct the doubly linked list
Node* constructDoublyList(int mtrx[][dim])
{
    // function call for construct
    // the doubly linked list
    return constructDoublyListUtil(
        mtrx, 0, 0, NULL);
}

// function for displaying
// doubly linked list data
void display(Node* head)
{
    // pointer to move right
    Node* rPtr;

    // pointer to move down
    Node* dPtr = head;

    // loop till node->down is not NULL
    while (dPtr) {

        rPtr = dPtr;

        // loop till node->right is not NULL
        while (rPtr) {
            cout << rPtr->data << " ";
            rPtr = rPtr->next;
        }

        cout << "\n";
        dPtr = dPtr->down;
    }
}

// driver code
int main()
{

    // initialise matrix
    int mtrx[dim][dim] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    Node* list = constructDoublyList(mtrx);

    display(list);

    return 0;
}
