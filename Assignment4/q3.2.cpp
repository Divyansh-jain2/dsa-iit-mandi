#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* firstChild;
    TreeNode* nextSibling;

    TreeNode(int val) : value(val), firstChild(nullptr), nextSibling(nullptr) {}
};

class UnboundedBranchTreeLinkedList {
private:
    TreeNode* root;

    void deleteTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        deleteTree(node->firstChild);
        deleteTree(node->nextSibling);
        delete node;
    }

public:
    UnboundedBranchTreeLinkedList(int value) {
        root = new TreeNode(value);
    }

    TreeNode* insertNode(int parentValue, int value) {
        TreeNode* newNode = new TreeNode(value);
        TreeNode* parent = nullptr;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->value == parentValue) {
                parent = current;
                break;
            }
            if (current->firstChild != nullptr) {
                q.push(current->firstChild);
            }
            if (current->nextSibling != nullptr) {
                q.push(current->nextSibling);
            }
        }

        if (parent != nullptr) {
            if (parent->firstChild == nullptr) {
                parent->firstChild = newNode;
            } else {
                TreeNode* temp = parent->firstChild;
                while (temp->nextSibling != nullptr) {
                    temp = temp->nextSibling;
                }
                temp->nextSibling = newNode;
            }
        } else {
            cout << "Parent not found!" << endl;
        }

        return newNode;
    }

    void display() {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->value << ": ";
            TreeNode* child = current->firstChild;
            while (child != nullptr) {
                cout << child->value << " ";
                q.push(child);
                child = child->nextSibling;
            }
            cout << endl;
        }
    }

    ~UnboundedBranchTreeLinkedList() {
        deleteTree(root);
    }
};

int main() {
    UnboundedBranchTreeLinkedList tree(1);
    tree.insertNode(1, 2);
    tree.insertNode(1, 3);
    tree.insertNode(2, 4);
    tree.insertNode(2, 5);
    tree.insertNode(3, 6);
    tree.insertNode(4, 7);
    tree.insertNode(5, 8);

    tree.display();

    return 0;
}