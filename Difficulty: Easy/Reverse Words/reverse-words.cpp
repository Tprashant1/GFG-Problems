//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        vector<string>temp;
        string s ;
        for(int i=0;i<str.size();i++){
            char t = str[i];
            if(t == '.'){
                temp.push_back(s);
                s = "";
            
            }
            else{
                s += t;
            }
        }
        
        temp.push_back(s);
        reverse(temp.begin(),temp.end());
        
        string ans;
        for(int i=0;i<temp.size();i++){
            ans += temp[i];
            if( i != temp.size()-1){
                ans += ".";
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
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends