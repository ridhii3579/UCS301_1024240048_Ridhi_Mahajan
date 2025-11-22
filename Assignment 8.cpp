// 1
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node *newnode(int element)
{
    struct node*temp=(node*)malloc(sizeof(node));
    temp->data=element;
    temp->left=temp->right=NULL;
    return temp;
}
struct node* insert(struct node* root, int element){
    if (root==NULL)
    return newnode(element);
    if (element < root->data)
    root->left =insert(root->left, element);
    else if (element> root->data)
    root->right=insert(root->right, element);
    return root;
}
void inorder(struct node* root){
    if (root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(struct node* root){
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main() {
    int choice, val;
    struct node* result;

    do {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                break;

            case 2:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}


// 2
#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node *root = NULL;

node* newnode(int element) {
    node* temp = new node;
    temp->data = element;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* root, int element) {
    if (root == NULL)
        return newnode(element);

    if (element < root->data)
        root->left = insert(root->left, element);
    else if (element > root->data)
        root->right = insert(root->right, element);

    return root;
}

void inorder(node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == NULL)
        return;
    postorder(root->left);

    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int choice, val;

    do {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                break;

            case 2:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}


// 3
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        cout << "Duplicate values not allowed!\n";
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL)
        return root;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int maxDepth(Node* root) {
    if (root == NULL) 
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (root == NULL)
        return 0;
    if (!root->left && !root->right)
        return 1;
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = NULL;
    int choice, val;

    do {
        cout << "\nBinary Search Tree Menu\n";
        cout << "1. Insert\n2. Delete\n3. Inorder Traversal\n";
        cout << "4. Maximum Depth\n5. Minimum Depth\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insert(root, val);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
            break;

        case 3:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Maximum Depth: " << maxDepth(root) << endl;
            break;

        case 5:
            cout << "Minimum Depth: " << minDepth(root) << endl;
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}


// 4
#include <climits>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return ( isBSTUtil(root->left, minVal, root->data) &&
             isBSTUtil(root->right, root->data, maxVal) );
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);\
    root->right->right = newNode(14);

    if (isBST(root))
        cout << "The given binary tree is a BST.\n";
    else
        cout << "The given binary tree is NOT a BST.\n";

    return 0;
}


// 5
#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSortIncreasing(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSortDecreasing(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main() {
    int arr1[] = {0, 11, 13, 56, 6, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    heapSortIncreasing(arr1, n);
    cout << "Sorted in Increasing Order: ";
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;
    heapSortDecreasing(arr1, n);
    cout << "Sorted in Decreasing Order: ";
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;
    return 0;
}


// 6
#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int heap[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int value) {
        heap[size] = value;
        int i = size;
        size++;
        while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void deleteMax() {
        if (size == 0) {
            cout << "Priority Queue is Empty!\n";
            return;
        }

        cout << "Deleted Max Element: " << heap[0] << endl;
        heap[0] = heap[size - 1];
        size--;
        int i = 0;

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

    void display() {
        if (size == 0) {
            cout << "Priority Queue is Empty!\n";
            return;
        }
        cout << "Priority Queue (Max Heap): ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, val;

    do {
        cout << "\nPriority Queue Menu\n";
        cout << "1. Insert\n2. Delete Max\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                pq.insert(val);
                break;
            case 2:
                pq.deleteMax();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}

// 7
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int &postIndex) {
    if (inStart > inEnd) return NULL;

    int curr = postorder[postIndex--];
    Node* root = new Node(curr);

    int pos = find(inorder.begin(), inorder.end(), curr) - inorder.begin();

    root->right = buildTree(inorder, postorder, pos + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, pos - 1, postIndex);

    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> inorder = {10, 20, 30, 40, 50};
    vector<int> postorder = {10, 30, 50, 40, 20};

    int postIndex = postorder.size() - 1;
    Node* root = buildTree(inorder, postorder, 0, inorder.size()-1, postIndex);

    cout << "Constructed binary tree: ";
    preorder(root);

    return 0;
}


// 8
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* bstToDLL(Node* root, Node* head) {
    if (!root) return head;

    head = bstToDLL(root->right, head);

    root->right = head;
    if (head) head->left = root;

    head = root;

    head = bstToDLL(root->left, head);
    return head;
}

Node* mergeDLL(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    Node* head = NULL;

    if (h1->data < h2->data) {
        head = h1;
        head->right = mergeDLL(h1->right, h2);
        if (head->right) head->right->left = head;
    } else {
        head = h2;
        head->right = mergeDLL(h1, h2->right);
        if (head->right) head->right->left = head;
    }

    return head;
}

void printDLL(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->right;
    }
    cout << "NULL\n";
}

int main() {
    Node* T1 = new Node(20);
    T1->left = new Node(10);
    T1->right = new Node(30);
    T1->right->left = new Node(25);
    T1->right->right = new Node(100);
    T1->right->left->right = new Node(50);

    Node* T2 = new Node(5);
    T2->right = new Node(70);

    Node* dll1 = bstToDLL(T1, NULL);
    Node* dll2 = bstToDLL(T2, NULL);

    Node* merged = mergeDLL(dll1, dll2);

    cout << "Merged Sorted DLL:\n";
    printDLL(merged);

    return 0;
}
