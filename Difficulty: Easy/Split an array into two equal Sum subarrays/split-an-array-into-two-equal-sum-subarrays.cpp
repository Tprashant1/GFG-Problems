//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int i = 0 ;
        int j = arr.size()-1;
        int sum1 = 0 ;
        int sum2 = 0 ; 
        while(i <= j){
            if(sum1 >= sum2){
                sum2 += arr[j];
                j--;
            }
            else{
                sum1 += arr[i];
                i++;
            }
            
        }
        
        if(sum1 == sum2){
            return true;
        }
        else{
            return false;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends