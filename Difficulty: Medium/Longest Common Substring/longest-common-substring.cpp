//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        int maxSize = 0 ;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(str1[i] == str2[j]){
                    dp[i+1][j+1] = 1 + dp[i][j];
                    maxSize = max(maxSize,dp[i+1][j+1]);
                }
            }
        }
        return maxSize;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends