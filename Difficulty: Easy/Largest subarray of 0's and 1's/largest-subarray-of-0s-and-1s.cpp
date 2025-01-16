//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        if(n == 1){
            return 0;
        }
        
        unordered_map<int, int>prefixSumIndex;
        int prefixSum = 0;
        int maxLength = 0;
    
        prefixSumIndex[0] = -1;
        
        for(int i=0;i<n;i++){
            prefixSum += (arr[i] == 0) ? -1 : 1;
            
            if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end()) {
                maxLength = max(maxLength, i - prefixSumIndex[prefixSum]);
            }
            else {
                prefixSumIndex[prefixSum] = i;
            }
        }
        
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends