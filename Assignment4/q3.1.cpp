#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode {
public:
    int value;
    vector<TreeNode*> children;

    TreeNode(int val) : value(val) {}
};

class UnboundedBranchTreeArray {
private:
    TreeNode* root;

    void deleteTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        for (TreeNode* child : node->children) {
            deleteTree(child);
        }
        delete node;
    }

public:
    UnboundedBranchTreeArray(int value) {
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
            for (TreeNode* child : current->children) {
                q.push(child);
            }
        }

        if (parent != nullptr) {
            parent->children.push_back(newNode);
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
            for (TreeNode* child : current->children) {
                cout << child->value << " ";
                q.push(child);
            }
            cout << endl;
        }
    }

    ~UnboundedBranchTreeArray() {
        deleteTree(root);
    }
};

int main() {
    UnboundedBranchTreeArray tree(1);
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