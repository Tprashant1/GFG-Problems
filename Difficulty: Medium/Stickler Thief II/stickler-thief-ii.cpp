//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
     int helper(int idx, int end, vector<int>& arr, vector<int> &dp){
        if(idx > end){
            return 0;
        }
            
        if(dp[idx] != -1){
            return dp[idx];
        }
            
        int Pick = arr[idx] + helper(idx+2,end,arr,dp);
        int notPick = helper(idx+1,end,arr,dp);
        return dp[idx] = max(Pick,notPick);
    }
    
    int maxValue(vector<int>& arr) {
        vector<int> dp1(arr.size() + 1, -1);
        vector<int> dp2(arr.size() + 1, -1);
       
        return max(helper(0,arr.size()-2,arr,dp1), helper(1,arr.size()-1,arr,dp2));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends