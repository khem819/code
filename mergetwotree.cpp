#include<iostream>
#include<vector>

using namespace std;

class Node{
public: 
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

//insert element in bst
Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildbst(vector<int> arr){
    Node* root = NULL;

    for(int val : arr){
        root = insert(root, val);
    }
    return root;
}

void inorder(Node* root, vector<int>& seq){
    if(root == NULL){
        return;
    }

    inorder(root->left, seq);
    seq.push_back(root->data);
    inorder(root->right, seq);
}

Node* buildbst(vector<int> arr, int start, int end){
    if(start > end){
        return NULL;
    }

    int mid = start + (end - start) / 2;
    Node* root = new Node(arr[mid]);
    root->left = buildbst(arr, start, mid - 1);
    root->right = buildbst(arr, mid + 1, end);
    return root;
}

Node* merge(Node* root1, Node* root2){
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);
    vector<int> temp;

    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            temp.push_back(arr1[i]);
            i++;
        }else{
            temp.push_back(arr2[j]);
            j++;
        }
    }

    // Push any remaining elements from either array
    while(i < arr1.size()){
        temp.push_back(arr1[i]);
        i++;
    }
    while(j < arr2.size()){
        temp.push_back(arr2[j]);
        j++;
    }

    return buildbst(temp);
}



int main(){
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {4, 5, 6};

    Node* root1 = buildbst(arr1);
    Node* root2 = buildbst(arr2);


    Node* root = merge(root1, root2);
    vector<int> seq;
    inorder(root, seq);
    for(int val : seq){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
