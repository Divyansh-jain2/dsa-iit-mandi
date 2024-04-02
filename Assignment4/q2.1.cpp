#include <iostream>
#include <vector>

using namespace std;

class BinaryTreeArray {
private:
    vector<int> tree;
    int size;

public:
    BinaryTreeArray(int capacity) : size(0) {
        tree.resize(capacity);
        for (int i = 0; i < capacity; ++i) {
            tree[i] = -1; // Initialize tree with -1 indicating empty nodes
        }
    }

    void insert(int value) {
        if (size < tree.size()) {
            tree[size++] = value;
        } else {
            cout << "Binary tree is full. Cannot insert value: " << value << endl;
        }
    }

    bool search(int value) {
        for (int i = 0; i < size; ++i) {
            if (tree[i] == value) {
                return true;
            }
        }
        return false;
    }

    bool deleteNode(int value) {
        int i = 0;
        for (; i < size; ++i) {
            if (tree[i] == value) {
                break;
            }
        }
        if (i == size) {
            return false; // Value not found
        }
        tree[i] = tree[--size]; // Replace deleted node with the last node
        return true;
    }

    void display() {
        cout << "Binary Tree (Array): ";
        for (int i = 0; i < size; ++i) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTreeArray binaryTree(10);
    binaryTree.insert(5);
    binaryTree.insert(3);
    binaryTree.insert(7);
    binaryTree.insert(2);
    binaryTree.insert(4);
    binaryTree.insert(6);
    binaryTree.insert(8);

    binaryTree.display();

    int deleteValue = 3;
    if (binaryTree.deleteNode(deleteValue)) {
        cout << "Value " << deleteValue << " deleted from the binary tree." << endl;
    } else {
        cout << "Value " << deleteValue << " not found in the binary tree. Deletion failed." << endl;
    }

    binaryTree.display();

    return 0;
}