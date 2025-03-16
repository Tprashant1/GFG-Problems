//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        if(arr[0] == 0){
            return -1;
        }
        
        int n = arr.size();
        int maxjump = 0; 
        int limit = 0;
        int ans = 0;
        for(int i=0;i<n-1;i++){
            maxjump = max(maxjump,i+arr[i]);
            if(i == limit){
                limit = maxjump;
                ans++;
            }
        }
        
        if(limit < n-1){
            return -1;
        }
        return ans;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends