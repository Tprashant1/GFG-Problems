//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        int n = str.size();
        int cnt = 0 ;
        for(int i=0;i<n;i++){
            string num = "";
            while(i < n && str[i] != '.'){
                if(!isdigit(str[i])){
                    return false;
                }
                num += str[i];
                i++;
            }
            if(num.empty() || (num[0] == '0' && num.size() > 1 || stoi(num) < 0 || stoi(num) > 255)){
                return false;
            }
            cnt++;
        }
        return cnt == 4;
        
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends