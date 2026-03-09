#include<iostream>
#include<vector>

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

void kthlevel(Node* root,int k){
    if(root == NULL) return ;

    if(k == 1){
        cout<<root->data<<" ";
        return;
    }

    kthlevel(root->left,k-1);
    kthlevel(root->right,k-1);
}

int main() {
    vector<int> preorder = {1, 2, 7, -1,-1,-1, 3, 4, -1, -1, 5, -1, -1};
    int idx = 0;
    Node* root = buildTree(preorder, idx);
    kthlevel(root,2);

    return 0;
}
