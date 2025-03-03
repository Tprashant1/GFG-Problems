//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        deque<int>mindq;
        deque<int>maxdq;
        int s = 0;
        int e = 0;
        int start = 0;
        int end = 0;
        while(e < n){
            while(!mindq.empty() && arr[mindq.back()] > arr[e]){
                mindq.pop_back();
            }
            
            while(!maxdq.empty() && arr[maxdq.back()] < arr[e]){
                maxdq.pop_back();
            }
            
            mindq.push_back(e);
            maxdq.push_back(e);
            
            while(arr[maxdq.front()] - arr[mindq.front()] > x){
                if(s == maxdq.front()){
                    maxdq.pop_front();
                }
                if(s == mindq.front()){
                    mindq.pop_front();
                }
                s++;
            }
            
            if(e-s > end-start){
                start = s;
                end = e;
            }
            e++;
        }
        
        vector<int>ans;
        for(int i=start;i<=end;i++){
            ans.push_back(arr[i]);
        }
        
        return ans;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends