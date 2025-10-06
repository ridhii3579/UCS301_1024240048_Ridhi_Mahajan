// 1
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertSpecific(int val, int key, bool after) {
        Node* newNode = new Node(val);
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;

        if (!after && head->data == key) { // insert before head
            newNode->next = head;
            head = newNode;
            return;
        }

        while (temp) {
            if (after && temp->data == key) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            } else if (!after && temp->next && temp->next->data == key) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Key not found!\n";
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecific(int key) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;
        if (temp->next) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        } else
            cout << "Node not found!\n";
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Element " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found!\n";
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next)
                cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    void countAndDelete(int key) {
        int count = 0;
        Node* temp = head;
        Node* prev = nullptr;

        while (temp) {
            if (temp->data == key) {
                count++;
                if (temp == head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                    continue;
                } else {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                    continue;
                }
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Count: " << count << endl;
        cout << "Updated List: ";
        display();
    }

    void findMiddle() {
        if (!head) return;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle Element: " << slow->data << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, key;
    bool after;

    do {
        cout << "\n--- Singly Linked List Operations ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before/After a Node\n";
        cout << "4. Delete from Beginning\n5. Delete from End\n6. Delete Specific Node\n";
        cout << "7. Search Node\n8. Display List\n9. Count & Delete Occurrences\n";
        cout << "10. Find Middle\n11. Reverse List\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter value and key: ";
            cin >> val >> key;
            cout << "Insert after (1) or before (0)? ";
            cin >> after;
            list.insertSpecific(val, key, after);
            break;
        case 4:
            list.deleteFromBeginning();
            break;
        case 5:
            list.deleteFromEnd();
            break;
        case 6:
            cout << "Enter key to delete: ";
            cin >> key;
            list.deleteSpecific(key);
            break;
        case 7:
            cout << "Enter key to search: ";
            cin >> key;
            list.search(key);
            break;
        case 8:
            list.display();
            break;
        case 9:
            cout << "Enter key to count and delete: ";
            cin >> key;
            list.countAndDelete(key);
            break;
        case 10:
            list.findMiddle();
            break;
        case 11:
            list.reverse();
            cout << "List reversed.\n";
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

// 2
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next)
                cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    void countAndDelete(int key) {
        int count = 0;
        Node* temp = head;
        Node* prev = nullptr;

        while (temp) {
            if (temp->data == key) {
                count++;
                if (temp == head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                    continue;
                } else {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                    continue;
                }
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Count: " << count << endl;
        cout << "Updated Linked List: ";
        display();
    }
};

int main() {
    LinkedList list;
    int n, val, key;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter list elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "Enter key to delete: ";
    cin >> key;

    cout << "Original Linked List: ";
    list.display();

    list.countAndDelete(key);

    return 0;
}

// 3
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next)
                cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    void findMiddle() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle element: " << slow->data << endl;
    }
};

int main() {
    LinkedList list;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter list elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "Linked List: ";
    list.display();

    list.findMiddle();

    return 0;
}

// 4
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next)
                cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

int main() {
    LinkedList list;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter list elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "Original Linked List: ";
    list.display();

    list.reverse();

    cout << "Reversed Linked List: ";
    list.display();

    return 0;
}

// Additional Questions 1
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* getIntersectionNode(Node* headA, Node* headB) {
    Node* a = headA;
    Node* b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL\n";
}

int main() {
    Node* newNode;

    Node* head1 = new Node(4);
    head1->next = new Node(1);
    newNode = new Node(8);
    head1->next->next = newNode;
    newNode->next = new Node(5);

    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(1);
    head2->next->next->next = newNode;

    cout << "List A: ";
    display(head1);
    cout << "List B: ";
    display(head2);

    Node* intersection = getIntersectionNode(head1, head2);
    if (intersection)
        cout << "Intersected at node with value " << intersection->data << endl;
    else
        cout << "No intersection\n";

    return 0;
}

// Additional Questions 2
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse linked list in groups of k
Node* reverseInGroups(Node* head, int k) {
    if (!head) return NULL;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    // Reverse first k nodes
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Recursively reverse the remaining list
    if (next != NULL)
        head->next = reverseInGroups(next, k);

    return prev; // new head after reversal
}

// Driver code
int main() {
    Node* head = NULL;

    int n, k, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter linked list elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }

    cout << "Enter value of K: ";
    cin >> k;

    cout << "\nOriginal Linked List: ";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}

// Additional Questions 3
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void removeLoop(Node* head) {
    Node *slow = head, *fast = head;

    // Step 1: Detect loop
    bool loopExists = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            loopExists = true;
            break;
        }
    }

    if (!loopExists) {
        cout << "No loop detected.\n";
        return;
    }

    // Step 2: Find start of loop
    slow = head;
    Node* prev = nullptr;  // To keep track of the node before meeting point
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Remove loop
    prev->next = nullptr;

    cout << "Loop removed successfully.\n";
}

// Function to display linked list
void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver Code
int main() {
    Node* head = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }

    // Create a loop manually for testing
    cout << "Creating a loop for testing (last node pointing to second node)...\n";
    if (head && head->next) {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = head->next; // Creating a loop
    }

    // Remove loop if it exists
    removeLoop(head);

    cout << "Linked List after loop removal: ";
    display(head);

    return 0;
}

// Additional Questions 4
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert node at end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Display list
void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Rotate list left by k positions
Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Count nodes
    Node* temp = head;
    int len = 1;
    while (temp->next) {
        len++;
        temp = temp->next;
    }

    // Make list circular
    temp->next = head;

    // Adjust k if larger than length
    k = k % len;
    if (k == 0) {
        temp->next = nullptr;
        return head;
    }

    // Find new head after k rotations
    Node* newTail = head;
    for (int i = 1; i < k; i++)
        newTail = newTail->next;

    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

// Driver code
int main() {
    Node* head = nullptr;
    int n, k, val;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }

    cout << "Enter value of k: ";
    cin >> k;

    cout << "\nOriginal List: ";
    display(head);

    head = rotateLeft(head, k);

    cout << "List after rotating left by " << k << " positions:\n";
    display(head);

    return 0;
}

// Additional Questions 5
#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) : coeff(c), pow(p), next(nullptr) {}
};

// Function to insert term at end
void insertTerm(Node*& head, int coeff, int pow) {
    Node* newNode = new Node(coeff, pow);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Function to display polynomial
void displayPoly(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->coeff << "x^" << temp->pow;
        if (temp->next) cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (poly1 && poly2) {
        Node* newNode = nullptr;

        if (poly1->pow == poly2->pow) {
            newNode = new Node(poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } 
        else if (poly1->pow > poly2->pow) {
            newNode = new Node(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } 
        else {
            newNode = new Node(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }

        if (!result)
            result = tail = newNode;
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    // Append remaining terms
    while (poly1) {
        Node* newNode = new Node(poly1->coeff, poly1->pow);
        tail->next = newNode;
        tail = tail->next;
        poly1 = poly1->next;
    }
    while (poly2) {
        Node* newNode = new Node(poly2->coeff, poly2->pow);
        tail->next = newNode;
        tail = tail->next;
        poly2 = poly2->next;
    }

    return result;
}

// Driver Code
int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    int n1, n2, coeff, pow;

    cout << "Enter number of terms in 1st polynomial: ";
    cin >> n1;
    cout << "Enter coefficient and power for 1st polynomial (in descending order):\n";
    for (int i = 0; i < n1; i++) {
        cin >> coeff >> pow;
        insertTerm(poly1, coeff, pow);
    }

    cout << "\nEnter number of terms in 2nd polynomial: ";
    cin >> n2;
    cout << "Enter coefficient and power for 2nd polynomial (in descending order):\n";
    for (int i = 0; i < n2; i++) {
        cin >> coeff >> pow;
        insertTerm(poly2, coeff, pow);
    }

    cout << "\nFirst Polynomial: ";
    displayPoly(poly1);
    cout << "Second Polynomial: ";
    displayPoly(poly2);

    Node* result = addPolynomials(poly1, poly2);

    cout << "\nResultant Polynomial: ";
    displayPoly(result);

    return 0;
}

