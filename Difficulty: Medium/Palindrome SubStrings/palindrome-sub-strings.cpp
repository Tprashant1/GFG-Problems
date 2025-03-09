//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    
    int PalinCnt(int i,int j,string &s){
        int count = 0 ;
        while(i >= 0 && j < s.size()){
            if(s[i] == s[j]){
                count++;
                i--;
                j++;
            }
            else{
                break;
            }
        }
        
        return count;
    }
  
    int countPS(string &s) {
        int n = s.size();
        int oddcnt = 0;
        int evencnt = 0;
        
        for(int i=0;i<n;i++){
            oddcnt += PalinCnt(i-1,i+1,s);
        }
        
        for(int i=1;i<n;i++){
            evencnt += PalinCnt(i-1,i,s);
        }
        
        return oddcnt + evencnt;
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
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends