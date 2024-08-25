//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int srch(int value,vector<int>&brr){
        int l = 0 ;
        int r = brr.size()-1;
        int index = -1;
        
        while(l <= r){
            int mid = l+(r-l)/2;
            if(brr[mid] <= value){
                index = mid;;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return index;
    }
  
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        long long ans = 0;
        long long one = 0;
        long long two = 0;
        long long threefour = 0;
        sort(brr.begin(),brr.end());
        int n = brr.size();
        
        for(auto i:brr){
            if(i == 1) one++;
            else if(i == 2) two++;
            else if(i == 3 || i == 4) threefour++;
        }
        
        for(auto i:arr){
            if(i != 1){
                ans += one;
                if(i == 2) ans -= threefour;
                if(i == 3) ans += two;
                int index = srch(i,brr);
                ans += n-index-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends