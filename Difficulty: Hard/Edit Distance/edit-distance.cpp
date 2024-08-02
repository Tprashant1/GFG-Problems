//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(string word1, string word2,int m,int n,vector<vector<int>> &dp){
        if(m==0){
            return n;
        }
        if(n==0){
            return m;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }

        if(word1[m-1] == word2[n-1]){
            dp[m][n] = solve(word1,word2,m-1,n-1,dp);
            return dp[m][n];
        }
        else{
            dp[m][n] =1 + min({solve(word1,word2,m-1,n-1,dp),solve(word1,word2,m-1,n,dp),solve(word1,word2,m,n-1,dp)});
            return dp[m][n] ;
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(word1,word2,m,n,dp);
    }
  
    int editDistance(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(str1,str2,m,n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends