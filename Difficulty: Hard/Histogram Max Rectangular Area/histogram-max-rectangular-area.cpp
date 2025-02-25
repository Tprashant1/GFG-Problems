//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int>nextSmallestElement(vector<int>&arr,int n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        
        for(int i=n-1;i>=0;i--){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
        }
        
        return ans;
    }
  
    vector<int>prevSmallestElement(vector<int>&arr,int n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        
        for(int i=0;i<n;i++){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
        }
        
        return ans;
    }
  
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        
        vector<int>next(n);
        next = nextSmallestElement(arr,n);
        
        vector<int>prev(n);
        prev = prevSmallestElement(arr,n);
        
        int area = INT_MIN;
        for(int i=0;i<n;i++){
            int length = arr[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            
            int breadth = next[i] - prev[i] - 1;
            int newArea = length * breadth;
            area = max(area,newArea);
        }
        
        return area;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends