//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        int j = 0;
        unordered_map<char,int>mp;
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= j){
                j = mp[s[i]] + 1;                
            }
            
            mp[s[i]] = i;
            maxi = max(maxi,i-j+1);
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends