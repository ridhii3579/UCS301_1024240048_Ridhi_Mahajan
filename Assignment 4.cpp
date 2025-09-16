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
