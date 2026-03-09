#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(const vector<int>& preorder, int& idx) {

    // 🔹 Boundary check added
    if (idx >= preorder.size())
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

// Preorder traversal
void preorderPrint(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

//inorder traversal
void inorderprint(Node* root){
    if(root == NULL){
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}

//postorder traversal
void postorderprint(Node* root){
    if(root == NULL){
        return;
    }
    postorderprint(root->left);
    postorderprint(root->right);
    cout<<root->data<<" ";
}

//level order traversal 
void levelOrderPrint(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);  // Level separator

    while (!q.empty()) {

        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << endl;

            if (!q.empty())
                q.push(NULL);
        }
        else {
            cout << curr->data << " ";

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}


int main() {

    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    int idx = 0;

    Node* root = buildTree(preorder, idx);

    cout << "Preorder Traversal: ";
    preorderPrint(root);
    cout << endl;

    cout<<"Inorder Traversal: ";
    inorderprint(root);
    cout<<endl;

    cout<<"Postorder Traversal: ";
    postorderprint(root);
    cout<<endl;

    cout<<"Level Order Traversal: ";
    levelOrderPrint(root);
    cout<<endl;

    if (root)
        cout << "Tree built successfully. Root = " << root->data << endl;
    else
        cout << "Tree is empty." << endl;

    return 0;
}
