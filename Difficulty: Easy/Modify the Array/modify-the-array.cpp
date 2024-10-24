//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(arr[i] == arr[i+1]){
                ans.push_back(2*arr[i]);
                i++;
            }
            else if(arr[i] == 0){
                continue;
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        
        int m = ans.size();
        int i = 0;
        int j = n-m;
        while(i < j){
            ans.push_back(0);
            i++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends