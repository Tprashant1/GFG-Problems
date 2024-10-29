//{ Driver Code Starts
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* a node of the singly linked list */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node*& head_ref, int new_data) {
    /* allocate node */
    struct Node* new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

/* A utility function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends

/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution {
  public:
  
    int partition(vector<int>&temp,int low,int high){
        int pivot = temp[high];
        int i = low-1;
        for(int j=low;j<=high-1;j++){
            if(temp[j] <= pivot){
                i++;
                swap(temp[i],temp[j]);
            }
        }
        
        swap(temp[i+1],temp[high]);
        return i+1;
    }
  
    
    void quickSort(vector<int>&temp,int low,int high){
        if(low < high){
            int position = partition(temp,low,high);
            quickSort(temp,low,position-1);
            quickSort(temp,position+1,high);
        }
    }
  
    struct Node* quickSort(struct Node* head) {
        vector<int>temp;
        Node* curr = head;
        while(curr){
            temp.push_back(curr->data);
            curr = curr->next;
        }
        
        int n = temp.size();
        quickSort(temp,0,n-1);
        
        
        curr = head;
        int i = 0;
        while(curr){
            curr->data = temp[i];
            curr = curr->next;
            i++;
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends