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


// Additional questions 1
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* buildTree(vector<int>&a){
    if(a.empty() || a[0]==-1) return NULL;
    queue<TreeNode*> q;
    TreeNode* root=new TreeNode(a[0]);
    q.push(root);
    int i=1;
    while(!q.empty() && i<a.size()){
        TreeNode* cur=q.front(); 
        q.pop();
        if(i<a.size() && a[i]!=-1){
            cur->left=new TreeNode(a[i]);
            q.push(cur->left);
        }
        i++;
        if(i<a.size() && a[i]!=-1){
            cur->right=new TreeNode(a[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

int sumLeft(TreeNode* root,bool isLeft){
    if(!root) return 0;
    if(!root->left && !root->right){
        if(isLeft) return root->val;
        return 0;
    }
    return sumLeft(root->left,true)+sumLeft(root->right,false);
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    TreeNode* root=buildTree(a);
    cout<<sumLeft(root,false);
}


// Additional questions 2
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<TreeNode*> build(int l,int r){
    if(l>r) return {NULL};
    vector<TreeNode*> res;
    for(int i=l;i<=r;i++){
        vector<TreeNode*> L=build(l,i-1);
        vector<TreeNode*> R=build(i+1,r);
        for(auto a:L) for(auto b:R){
            TreeNode* root=new TreeNode(i);
            root->left=a;
            root->right=b;
            res.push_back(root);
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n){
    if(n==0) return {};
    return build(1,n);
}

void printPre(TreeNode* root){
    if(!root){
        cout<<"null ";
        return;
    }
    cout<<root->val<<" ";
    printPre(root->left);
    printPre(root->right);
}

int main(){
    int n;
    cin>>n;
    vector<TreeNode*> trees=generateTrees(n);
    for(auto t:trees){
        printPre(t);
        cout<<endl;
    }
}


// Additional questions 3
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* buildTree(vector<int>&a){
    if(a.empty() || a[0]==-1) return NULL;
    queue<TreeNode*> q;
    TreeNode* root=new TreeNode(a[0]);
    q.push(root);
    int i=1;
    while(!q.empty() && i<a.size()){
        TreeNode* cur=q.front(); 
        q.pop();
        if(i<a.size() && a[i]!=-1){
            cur->left=new TreeNode(a[i]);
            q.push(cur->left);
        }
        i++;
        if(i<a.size() && a[i]!=-1){
            cur->right=new TreeNode(a[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

int maxDepth(TreeNode* root){
    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        TreeNode* root = buildTree(a);
        cout << maxDepth(root) << endl;
    }
}


// Additional questions 4
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* buildTree(vector<int>&a){
    if(a.empty() || a[0]==-1) return NULL;
    queue<TreeNode*> q;
    TreeNode* root=new TreeNode(a[0]);
    q.push(root);
    int i=1;
    while(!q.empty() && i<a.size()){
        TreeNode* cur=q.front(); q.pop();
        if(i<a.size() && a[i]!=-1){
            cur->left=new TreeNode(a[i]);
            q.push(cur->left);
        }
        i++;
        if(i<a.size() && a[i]!=-1){
            cur->right=new TreeNode(a[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

vector<int> rightView(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            TreeNode* cur=q.front(); q.pop();
            if(i==s-1) ans.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    return ans;
}

int main(){
    int T; 
    cin>>T;
    while(T--){
        int n; 
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        TreeNode* root=buildTree(a);
        vector<int> r=rightView(root);
        for(int x:r) cout<<x<<" ";
        cout<<endl;
    }
}


// Additional questions 5
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* build(vector<int>&pre,int ps,int pe,vector<int>&in,int is,int ie,unordered_map<int,int>&mp){
    if(ps>pe || is>ie) return NULL;
    TreeNode* root=new TreeNode(pre[ps]);
    int k=mp[pre[ps]];
    int left=k-is;
    root->left=build(pre,ps+1,ps+left,in,is,k-1,mp);
    root->right=build(pre,ps+left+1,pe,in,k+1,ie,mp);
    return root;
}

TreeNode* buildTree(vector<int>&pre,vector<int>&in){
    unordered_map<int,int> mp;
    for(int i=0;i<in.size();i++) mp[in[i]]=i;
    return build(pre,0,pre.size()-1,in,0,in.size()-1,mp);
}

void levelOrder(TreeNode* root){
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* cur=q.front(); q.pop();
        cout<<cur->val<<" ";
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}

int main(){
    vector<int> pre={1,2,4,5,3};
    vector<int> in={4,2,5,1,3};
    TreeNode* root=buildTree(pre,in);
    levelOrder(root);
}


// Additional questions 6
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

// Additional questions 7
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
