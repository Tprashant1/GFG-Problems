//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=n-1;i>1;i--){
            int j = 0 ;
            int k = i-1;
            while(j < k){
                int sum = arr[j] + arr[k] ;
                if(sum == arr[i]){
                    return true;
                }
                else if(sum < arr[i]){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return false;
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends