//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool isPossible(vector<int> &stalls, int k,int mid){
        int cowCount = 1;
        int lastval = stalls[0];
        
        for(int i=0;i<stalls.size();i++){
            if(stalls[i] - lastval >= mid){
                cowCount++;
                if(cowCount == k){
                    return true;
                }
                lastval = stalls[i];
            }
            
        }
        return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        int s = 0;
        int maxi = *max_element(stalls.begin(),stalls.end());
        int e = maxi;
        int ans = -1;
        
        sort(stalls.begin(),stalls.end());
        
        while(s <= e){
            int mid = s + (e-s)/2;
            if(isPossible(stalls,k,mid)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends