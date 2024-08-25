//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    
    int solveTab(int W,vector<int>& wt, vector<int>& val,int n){
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        
        for(int i=wt[0];i<=W;i++){
            if(wt[0] <= W){
                dp[0][i] = val[0];
            }
            else{
                return 0;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
                int incl = 0 ;
                if(wt[i] <= j){
                    incl = val[i] + dp[i-1][j-wt[i]];
                }
        
        
                int excl= 0 + dp[i-1][j];
        
                dp[i][j] = max(incl,excl);
            }
        }
        
        return dp[n-1][W];
        
    }
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        return solveTab(W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends