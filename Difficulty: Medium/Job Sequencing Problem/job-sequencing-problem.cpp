//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int,int>>temp;
        int n = profit.size();
        for(int i=0;i<n;i++){
            temp.push_back({deadline[i],profit[i]});
        }
        
        sort(temp.begin(),temp.end());
        
        int count = 0 ;
        int maxProfit = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<temp.size();i++){
            if(temp[i].first > count){
                count++;
                maxProfit += temp[i].second;
                pq.push(temp[i].second);
            }        
            
            else if(temp[i].second > pq.top()){
                maxProfit -= pq.top() ;
                pq.pop();
                maxProfit += temp[i].second;
                pq.push(temp[i].second);
            }
        }
        
        return {count,maxProfit};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends