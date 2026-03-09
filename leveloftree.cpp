#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(const vector<int>& preorder, int& idx) {
    if (idx >= (int)preorder.size())
        return NULL;

    if (preorder[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* root = new Node(preorder[idx++]);

    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

// Top view of binary tree
void topview(Node* root) {
    if (!root) return;

    queue<pair<Node*, int>> q; // (node, horizontal distance)
    map<int, int> m; // <hd, node val>
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        
        Node* curr = front.first;
        int currhd = front.second;

        if (m.find(currhd) == m.end()) {
            m[currhd] = curr->data;
        }

        if (curr->left != NULL) {
            q.push(make_pair(curr->left, currhd - 1));
        }

        if (curr->right != NULL) {
            q.push(make_pair(curr->right, currhd + 1));
        }
    }

    for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = 0;
    Node* root = buildTree(preorder, idx);
    topview(root);

    return 0;
}
