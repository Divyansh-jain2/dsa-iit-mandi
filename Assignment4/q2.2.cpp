#include <iostream>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTreeLinked {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insertNode(node->left, value);
        } else if (value > node->value) {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    bool searchNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        } else if (value < node->value) {
            return searchNode(node->left, value);
        } else {
            return searchNode(node->right, value);
        }
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->value) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            } else {
                TreeNode* temp = findMin(node->right);
                node->value = temp->value;
                node->right = deleteNode(node->right, temp->value);
            }
        }
        return node;
    }

    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->value << " ";
        inorderTraversal(node->right);
    }

public:
    BinaryTreeLinked() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    bool search(int value) {
        return searchNode(root, value);
    }

    bool deleteNode(int value) {
        if (!search(value)) {
            return false;
        }
        root = deleteNode(root, value);
        return true;
    }

    void display() {
        cout << "Binary Tree (Linked): ";
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTreeLinked binaryTree;
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