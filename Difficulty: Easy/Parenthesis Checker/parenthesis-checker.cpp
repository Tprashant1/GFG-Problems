//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        int n = s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            char ch = s[i] ;
            if(ch == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            
            else if(ch == '}'){
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            
            else if(ch == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            
            else{
                st.push(ch);
            }
        }
        
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends