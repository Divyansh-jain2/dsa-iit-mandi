#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int key) {
        this -> data = key;
        this -> left = NULL;
        this -> right = NULL;
        this -> height = 1;
    }
};

int getHeight(Node *root) {
    if (root == NULL)
        return 0;
    else 
        return root -> height;
}

int getBalanceFactor(Node *root) {
    if (root == NULL)
        return 0;
    else 
        return getHeight(root -> left) - getHeight(root -> right);
}

Node* rightRotate(Node *root) {
    Node *newRoot = root -> left;
    Node *T2 = newRoot -> right;

    newRoot -> right = root;
    root -> left = T2;

    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
    newRoot -> height = max(getHeight(newRoot -> left), getHeight(newRoot -> right)) + 1;

    return newRoot;
}

Node* leftRotate(Node *root) {
    Node *newRoot = root -> right;
    Node *T2 = newRoot -> left;

    newRoot -> left = root;
    root -> right = T2;

    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
    newRoot -> height = max(getHeight(newRoot -> left), getHeight(newRoot -> right)) + 1;

    return newRoot; 
}

Node * insert(Node *root, int val) {
    if (root == NULL)
        return new Node(val);
    
    if (val < root -> data)
        root -> left = insert(root -> left, val);
    else if (val > root -> data)
        root -> right =  insert(root -> right, val);
    
    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
    int bf = getBalanceFactor(root);

    if (bf > 1 && val < root -> left -> data)
        return rightRotate(root);

    if (bf < -1 && val > root -> right -> data)
        return leftRotate(root);

    if (bf > 1 && val > root -> left -> data) {
        root -> left = leftRotate(root -> left);
        return rightRotate(root);
    }

    if (bf < - 1 && val < root -> right -> data) {
        root -> right = rightRotate(root -> right);
        return leftRotate(root);
    }

    return root;
}

void preorderTraversal(Node *root) {
    if (root == NULL)
        return ;
    
    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

void inorderTraversal(Node *root) {
    if (root == NULL)
        return ;
    
    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

void postorderTraversal(Node *root) {
    if (root == NULL)
        return ;
    
    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout << root -> data << " ";
}

Node* search(Node *root, int key) {
    if (root == NULL) 
        return NULL;

    if (root -> data > key)
        return search(root -> left, key);
    else if (root -> data < key)
        return search(root -> right, key);
    else   
        return root;
}

int succesor(Node *root, int val) {
    Node *successor = NULL;
    while (root != NULL) {
        if (root -> data > val) {
            successor = root;
            root = root -> left;
        }
        else 
            root = root -> right;
    }

    if (successor) 
        return successor -> data;
    else
        return -1;
}

Node* deleteNode(Node *root, int val) {
    if (root == NULL)
        return NULL;

    if (root -> data > val)
        root -> left =  deleteNode(root -> left, val);
    else if (root -> data < val)
        root -> right =  deleteNode(root -> right, val);
    else {
        if (root -> left == NULL || root -> right == NULL) {
            Node *temp = root -> left ? root -> left : root -> right;
            if (temp == NULL) {
                delete root;
                return NULL;
            }
            else {
                delete root;
                return temp;
            }
        }

        else {
            int nextMin = succesor(root -> right, root -> data);
            root -> data = nextMin;
            root -> right = deleteNode(root -> right, nextMin);
        }
    }

    if (root == NULL) 
        return NULL;

    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
    int bf = getBalanceFactor(root);

    if (bf > 1 && getBalanceFactor(root -> left) >= 0)
        return rightRotate(root);
    if (bf < -1 && getBalanceFactor(root -> right) <= 0)
        return leftRotate(root);
    if (bf > 1 && getBalanceFactor(root -> left) < 0) {
        root -> left = leftRotate(root -> left);
        return rightRotate(root);
    }
    if (bf < -1 && getBalanceFactor(root -> right) > 0) {
        root -> right = rightRotate(root -> right);
        return leftRotate(root);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    int val;
    cout << "Enter -1 to stop . . ." << endl;
    cout << "Enter a number : ";
    cin >> val;
    while (val != -1) {
        root = insert(root, val);
        cout << "Enter a number : ";
        cin >> val;
    }

    cout << "\nPre Order Traversal of the AVL Tree . . ." << endl;
    preorderTraversal(root);
    cout << endl;

    int n;
    cout << "Enter the number to be searched : ";
    cin >> n;
    Node *searchResult = search(root, n);
    if (searchResult)
        cout << n << " is present in the tree " << endl;
    else
        cout << "Not found . . ." << endl;

    int toDel;
    cout << "Enter the number to be deleted : ";
    cin >> toDel;
    searchResult = search(root, toDel);
    if (searchResult) {
        root = deleteNode(root, toDel);
        cout << toDel << " deleted from the tree" << endl;
        cout << "Updated pre order traversal . . ." << endl;
        preorderTraversal(root);
        cout << endl;
    }
    else
        cout << n << " is not present in the tree" << endl;
    return 0;
}