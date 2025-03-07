//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    
    int solve(string &s, string &str, int i, int j, vector<vector<int>> &dp){
        if(i == 0 || j == 0){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = 0;
        if(s[i-1] == str[j-1]){
            ans =  1 + solve(s,str,i-1,j-1,dp);
        }
        else{
            ans =  max(solve(s,str,i-1,j,dp),solve(s,str,i,j-1,dp));
        }
        
        dp[i][j] = ans;
        return dp[i][j];
    }
  
    int longestPalinSubseq(string &s) {
        string str = s;
        reverse(str.begin(),str.end());
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(s,str,n,n,dp);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends