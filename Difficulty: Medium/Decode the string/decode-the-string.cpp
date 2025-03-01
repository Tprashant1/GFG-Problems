//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        stack<int>intSt;
        stack<string>strSt;
        string ans = "";
        int n = s.size();
        int digit = 0;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                digit = digit*10 + (s[i]-'0');
            }
            
            else if(s[i] == '['){
                intSt.push(digit);
                digit = 0;
                strSt.push(ans);
                ans = "";
            }
            
            else if(s[i] == ']'){
                int k = intSt.top();
                intSt.pop();
                
                for(int j=1;j<=k;j++){
                    strSt.top() = (strSt.top() + ans);
                }
                
                ans = strSt.top();
                strSt.pop();
            }
            
            else{
                ans += s[i];
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends