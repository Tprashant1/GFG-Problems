//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* forward = curr->next;
        Node* prev= NULL;
        while(forward != head){
            curr->next = prev;
            prev = curr;
            curr = forward;
            forward = forward->next;
        }
        forward->next = curr;
        curr->next = prev;
        return curr;
        
    }
     

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        Node* temp = head->next;
        Node* curr = head;
        if(head->data == key){
            while(curr->next != head){
                curr = curr->next;
            }
            curr->next = temp;
            delete head;
            return temp;
        }
        else{
            while(temp->data != key && temp != head){
                curr = temp;
                temp = temp->next;
            }
            if(temp->data == key){
                curr->next = temp->next;
                delete temp;
            }
        }
        return head;
    }
};

//{ Driver Code Starts.

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

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends