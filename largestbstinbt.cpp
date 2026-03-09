#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class NodeInfo{
public:
    int size;
    int minVal;
    int maxVal;
    bool isBST;

    NodeInfo(int s,int mn,int mx,bool bst){
        size=s;
        minVal=mn;
        maxVal=mx;
        isBST=bst;
    }
};

class Solution{
public:

    int maxSize = 0;

    NodeInfo solve(Node* root){

        if(root==NULL)
            return NodeInfo(0,INT_MAX,INT_MIN,true);

        NodeInfo left = solve(root->left);
        NodeInfo right = solve(root->right);

        if(left.isBST && right.isBST &&
           root->data > left.maxVal &&
           root->data < right.minVal){

            int currSize = left.size + right.size + 1;

            maxSize = max(maxSize,currSize);

            return NodeInfo(currSize,
                            min(root->data,left.minVal),
                            max(root->data,right.maxVal),
                            true);
        }

        return NodeInfo(0,INT_MIN,INT_MAX,false);
    }

    int largestBST(Node *root)
    {
        solve(root);
        return maxSize;
    }
};

int main(){

    /*
            10
           /  \
          5    15
         / \     \
        1   8     7
    */

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    Solution obj;

    cout << "Largest BST size: " << obj.largestBST(root);

    return 0;
}