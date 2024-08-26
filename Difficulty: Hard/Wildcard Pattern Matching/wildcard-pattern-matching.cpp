//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    
     bool solve(int i,int j,string p,string s,vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0){
            for(int k=0;k<=i;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(p[i]==s[j] || p[i]=='?'){
            return dp[i][j]= solve(i-1,j-1,p,s,dp);
        }
        if(p[i]=='*'){
            return dp[i][j]= solve(i,j-1,p,s,dp)|| solve(i-1,j,p,s,dp);
        }
     }
    
    int wildCard(string pattern, string str) {
        int n=pattern.length();
        int m=str.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,pattern,str,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends