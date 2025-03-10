//{ Driver Code Starts
// Initial Template for C++
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
    
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(s1,s2,m,n,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends