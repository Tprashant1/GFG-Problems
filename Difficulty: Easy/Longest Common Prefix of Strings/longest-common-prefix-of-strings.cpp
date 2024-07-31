//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        string ans = "" ;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        string start = arr[0];
        string end = arr[n-1];
        int m = min(start.size(),end.size());
        for(int i=0;i<m;i++){
            if(start[i] != end[i]){
                break;
            }
            ans += start[i];
        }
        
        if(ans.size()==0){
            return "-1";
        }
        else{
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends