#include<iostream>
#include<vector>  
using namespace std;

struct Node{ 
    int data; 
    Node* left; 
    Node* right; 

    Node(int val){ 
        data = val; 
        left = right = NULL;
    }
};

Node* buildTree(const vector<int>& preorder, int& idx) { 
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

// height of tree
int height(Node* root){
    if(root == NULL) return 0;

    int leftht = height(root->left);
    int rightht = height(root->right);

    return max(leftht, rightht) + 1;
}

// count of nodes
int count(Node* root){
    if(root == NULL) return 0;

    return count(root->left) + count(root->right) + 1;
}

// sum of nodes
int sum(Node* root){
    if(root == NULL) return 0;

    return sum(root->left) + sum(root->right) + root->data;
}

void preorderPrint(Node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

// transform to sum tree
int sumtree(Node* root){
    if(root == NULL) return 0;

    int oldValue = root->data;

    int leftsum = sumtree(root->left);
    int rightsum = sumtree(root->right);

    root->data = leftsum + rightsum;

    return root->data + oldValue;
}

int main() {

    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int idx = 0;

    Node* root = buildTree(preorder, idx);

    cout<<"Height: "<<height(root)<<endl;
    cout<<"Count of nodes: "<<count(root)<<endl;
    cout<<"Sum of nodes: "<<sum(root)<<endl;

    sumtree(root);

    cout<<"Preorder after SumTree transformation: ";
    preorderPrint(root);

    return 0;
}
