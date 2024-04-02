#include <iostream>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;
    int comparisonCount;

    TreeNode* insertNode(TreeNode* node, int value) {
        comparisonCount++;
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
        comparisonCount++;
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

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    BinarySearchTree() : root(nullptr), comparisonCount(0) {}

    void insert(int value) {
        root = insertNode(root, value);
        cout << "Insertion complete. Comparisons made: " << comparisonCount << endl;
        comparisonCount = 0; // Reset comparison count for next operation
    }

    bool search(int value) {
        bool found = searchNode(root, value);
        cout << "Search for value " << value << ": " << (found ? "Found" : "Not found") << ". Comparisons made: " << comparisonCount << endl;
        comparisonCount = 0; // Reset comparison count for next operation
        return found;
    }

    bool deleteValue(int value) {
        root = deleteNode(root, value);
        cout << "Deletion complete. Comparisons made: " << comparisonCount << endl;
        comparisonCount = 0; // Reset comparison count for next operation
        return root != nullptr;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    bst.search(6);
    bst.search(9);

    bst.deleteValue(3);
    bst.deleteValue(10);

    return 0;
}