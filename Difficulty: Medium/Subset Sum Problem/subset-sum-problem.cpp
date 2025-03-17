//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    bool solve(vector<int>& arr, int sum, int i) {
        if(sum == 0){
            return true;
        }
        
        if(i >= arr.size()){
            return false;
        }
        
        if(arr[i] <= sum){
            if(solve(arr,sum-arr[i],i+1)){
                return true;
            }
        }
        
        if(solve(arr,sum,i+1)){
            return true;
        }
        
        return false;
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        return solve(arr,sum,0);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends