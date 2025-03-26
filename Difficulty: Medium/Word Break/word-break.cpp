//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int solve(int i,string &s,set<string>&st,vector<int>&dp){
        if(i == s.size()){
            return 1;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        string temp = "";
        for(int j=i;j<s.size();j++){
            temp += s[j];
            if(st.find(temp) != st.end()){
                if(solve(j+1,s,st,dp)){
                    return dp[i] = 1;
                }
            }
        }
        
        return dp[i] = 0;
    }
    
    bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.size();
        set<string>st;
        for(auto str:dictionary){
            st.insert(str);
        }
        
        vector<int>dp(n+1,-1);
        return solve(0,s,st,dp);
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends