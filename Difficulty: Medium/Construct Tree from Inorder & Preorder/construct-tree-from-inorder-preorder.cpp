//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
  
    int findPosition(vector<int> &inorder,int start,int element,int n){
        for(int i=start;i<n;i++){
            if(inorder[i] == element){
                return i;
            } 
        }
        return -1;
    }
    
    Node* solve(vector<int> &inorder, vector<int> &preorder,int &index,int i_start,int i_end,int n){
        if(index >= n || i_start > i_end){
            return NULL;
        }
        
        int val = preorder[index++];
        Node* root = new Node(val);
        
        int pos = findPosition(inorder,i_start,val,n);
        
        root->left = solve(inorder,preorder,index,i_start,pos-1,n);
        root->right = solve(inorder,preorder,index,pos+1,i_end,n);
        
        return root;
    }
  
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preOrderIndex = 0;
        int n = inorder.size();
        Node* node = solve(inorder,preorder,preOrderIndex,0,n-1,n);
        return node;
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends