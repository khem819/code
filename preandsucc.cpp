// inorder predecessor and successor
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if (root == NULL) return;

    if (root->key == key) {

        if (root->left != NULL) {
            Node* temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }

        if (root->right != NULL) {
            Node* temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
    }

    else if (key < root->key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }

    else {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    Node* pre = NULL;
    Node* suc = NULL;

    int key = 20;

    findPreSuc(root, pre, suc, key);

    if (pre)
        cout << "Predecessor: " << pre->key << endl;
    else
        cout << "No Predecessor\n";

    if (suc)
        cout << "Successor: " << suc->key << endl;
    else
        cout << "No Successor\n";

    return 0;
}