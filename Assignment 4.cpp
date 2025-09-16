// 1
#include<stdio.h>
#include<iostream>
using namespace std;
const int MAX_SIZE=5;
class Queue{
    private:
    int arr[MAX_SIZE];
    int front;
    int rear;


public:
Queue(){
    front=-1;
    rear=-1;
}

bool isEmpty(){
    return (front==-1 && rear==1);
}
bool isFull(){
    return (rear+1) % MAX_SIZE==front;
}
void enqueue(int value){
    if (isFull()){
        std::cout<<"Queue if full"<<std::endl;
        return;
    }
    else if(isEmpty()){
        front=0;
        rear=0;
    }else{
        rear=(rear+1)%MAX_SIZE;
    }
    arr[rear]=value;
    std::cout<<"Enqueue completed"<<std::endl;
}
void dequeue(){
    if (isEmpty()){
        std::cout<<"Queue if empty"<<std::endl;
        return;
    }
    else if(front==rear){
        std::cout<<"Dequeued element"<<arr[front]<<std::endl;
        front=-1;
        rear=-1;
    }else{
        std::cout<<"Dequeued element"<<arr[front]<<std::endl;
        front=(front+1)%MAX_SIZE;
    }
}
void peek(){
    if (isEmpty()){
        std::cout<<"Queue is empty"<<std::endl;
    }else{
        std::cout<<"Front element: "<<arr[front]<<std::endl;
    }
}
void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue elements: ";
        int i = front;
        while (i != rear) {
            std::cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        std::cout << arr[rear] << std::endl;
    }
};

void showMenu() {
    std::cout << "\n--- Queue Operations Menu ---" << std::endl;
    std::cout << "1. Enqueue" << std::endl;
    std::cout << "2. Dequeue" << std::endl;
    std::cout << "3. Peek" << std::endl;
    std::cout << "4. Check if Empty" << std::endl;
    std::cout << "5. Check if Full" << std::endl;
    std::cout << "6. Display" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    Queue myQueue;
    int choice, value;

    while (true) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to enqueue: ";
                std::cin >> value;
                myQueue.enqueue(value);
                break;
            case 2:
                myQueue.dequeue();
                break;
            case 3:
                myQueue.peek();
                break;
            case 4:
                if (myQueue.isEmpty()) {
                    std::cout << "Queue is empty." << std::endl;
                } else {
                    std::cout << "Queue is not empty." << std::endl;
                }
                break;
            case 5:
                if (myQueue.isFull()) {
                    std::cout << "Queue is full." << std::endl;
                } else {
                    std::cout << "Queue is not full." << std::endl;
                }
                break;
            case 6:
                myQueue.display();
                break;
            case 7:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

// 2
#include <iostream>
using namespace std;
#define SIZE 5   

class CircularQueue {
    int arr[SIZE];
    int front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front == -1);
    }
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
        cout << value << " Enqueued successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! " << endl;
            return;
        }
        cout << arr[front] << " Dequeued successfully." << endl;

        if (front == rear) {  // only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "0. Enqueue\n";
        cout << "1. Dequeue\n";
        cout << "2. Peek\n";
        cout << "3. Display\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 1:
            q.dequeue();
            break;

        case 2:
            q.peek();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << (q.isEmpty() ? "Queue is EMPTY." : "Queue is NOT EMPTY.") << endl;
            break;

        case 5:
            cout << (q.isFull() ? "Queue is FULL." : "Queue is NOT FULL.") << endl;
            break;

        case 6:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

// 3
#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even\n";
        return;
    }

    queue<int> firstHalf;
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front()); firstHalf.pop();
        q.push(q.front()); q.pop();
    }
}

int main() {
    queue<int> q;
    int n, x;
    cout << "Enter even number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x; q.push(x);
    }

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}

// 4
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    unordered_map<char, int> freq;
    queue<char> q;

    for (char c : str) {
        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    firstNonRepeating(s);
    return 0;
}

// 5(a)
#include <iostream>
#include <queue>
using namespace std;

// Using 2 Queues
class Stack2Q {
    queue<int> q1, q2;
public:
    void push(int x) { q1.push(x); }
    void pop() {
        if (q1.empty()) return;
        while (q1.size() > 1) { q2.push(q1.front()); q1.pop(); }
        q1.pop();
        swap(q1, q2);
    }
    int top() {
        while (q1.size() > 1) { q2.push(q1.front()); q1.pop(); }
        int t = q1.front();
        q2.push(t); q1.pop();
        swap(q1, q2);
        return t;
    }
};

// Using 1 Queue
class Stack1Q {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i=0; i<q.size()-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() { if (!q.empty()) q.pop(); }
    int top() { return q.front(); }
};

int main() {
    Stack2Q s1; s1.push(10); s1.push(20); s1.pop(); cout << s1.top() << endl;
    Stack1Q s2; s2.push(30); s2.push(40); cout << s2.top() << endl;
}

// Additional Questions 1
#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {
    queue<string> q;
    q.push("1");
    for (int i=0; i<n; i++) {
        string s = q.front(); q.pop();
        cout << s << " ";
        q.push(s+"0");
        q.push(s+"1");
    }
}

int main() { generateBinary(5); }

// Additional Questions 2
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int minIndex(queue<int>& q, int sortedIndex) {
    int minIdx = -1, minVal = INT_MAX, n = q.size();
    for (int i=0; i<n; i++) {
        int curr = q.front(); q.pop();
        if (curr < minVal && i <= sortedIndex) {
            minVal = curr; minIdx = i;
        }
        q.push(curr);
    }
    return minIdx;
}

void insertMinToRear(queue<int>& q, int minIdx) {
    int n = q.size();
    int minVal;
    for (int i=0; i<n; i++) {
        int curr = q.front(); q.pop();
        if (i == minIdx) minVal = curr;
        else q.push(curr);
    }
    q.push(minVal);
}

void sortQueue(queue<int>& q) {
    for (int i=1; i<=q.size(); i++) {
        int minIdx = minIndex(q, q.size()-i);
        insertMinToRear(q, minIdx);
    }
}

int main() {
    queue<int> q; q.push(11); q.push(5); q.push(4); q.push(21);
    sortQueue(q);
    while(!q.empty()){ cout<<q.front()<<" "; q.pop(); }
}

// Additional Questions 3
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(queue<int> q) {
    stack<int> st;
    int expected = 1;
    int n = q.size();
    while (!q.empty()) {
        if (q.front() == expected) {
            expected++; q.pop();
        } else if (!st.empty() && st.top() == expected) {
            expected++; st.pop();
        } else {
            st.push(q.front()); q.pop();
        }
    }
    while (!st.empty() && st.top() == expected) {
        st.pop(); expected++;
    }
    return (expected-1 == n);
}

int main() {
    queue<int> q; q.push(5); q.push(1); q.push(2); q.push(3); q.push(4);
    cout << (checkSorted(q) ? "Yes" : "No");
}

// Additional Questions 4
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students) q.push(s);
    int i=0, rotations=0;
    while (!q.empty() && rotations < q.size()) {
        if (q.front() == sandwiches[i]) {
            q.pop(); i++; rotations=0;
        } else {
            q.push(q.front()); q.pop();
            rotations++;
        }
    }
    return q.size();
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};
    cout << countStudents(students, sandwiches);
}


