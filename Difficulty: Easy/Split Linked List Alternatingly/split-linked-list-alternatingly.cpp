//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        int count = 1;
        Node* head1 = new Node(-1);
        Node* temp1 = head1;
        Node* head2 = new Node(-1);
        Node* temp2 = head2;
        
        Node* curr = head;
        while(curr){
            if(count %2 != 0){
                Node* newNode = new Node(curr->data);
                temp1->next = newNode;
                temp1 = newNode;
                count++;
                curr = curr->next;
            }
            else{
                Node* newNode1 = new Node(curr->data);
                temp2->next = newNode1;
                temp2 = newNode1;
                count++;
                curr = curr->next;
            }
        }
        
        head1 = head1->next;
        head2 = head2->next;
        
        vector<Node*>ans;
        ans.push_back(head1);
        ans.push_back(head2);
        
        return ans;
        
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends