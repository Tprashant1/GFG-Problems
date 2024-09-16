//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        stack<int>s;
        s.push(-1);
        int ans = 0;
        for(int i=0;i<str.size();i++){
            if(str[i] == '('){
                s.push(i);
            }
            
            else{
                s.pop();
                if(s.empty()){
                    s.push(i);
                }
                else{
                    int len = i-s.top();
                    ans = max(ans,len);
                }
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
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends