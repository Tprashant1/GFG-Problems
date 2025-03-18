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
    
    bool equalPartition(vector<int>& arr) {
        int total = 0;
        for(auto i:arr){
            total += i;
        }
        
        if(total % 2 != 0){
            return false;
        }
        
        
        return solve(arr,total/2,0);
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends