//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        if(str.size() < 26){
            return false;
        }
        
        vector<int>freq(26,0);
        for(int i=0;i<str.size();i++){
            if(isalpha(str[i])){
                freq[str[i]-'a']++;
            }
        }
        
        int ext= 0;
        int ntext =0;
        for(int i:freq){
            if(i>0){
                ext +=i ;
            }
            else{
                ntext++;
            }
        }
        
        if(ext >= 26 && ntext <= k){
            return true;
        }
        return false;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends