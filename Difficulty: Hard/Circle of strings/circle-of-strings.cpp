//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void DFS(int startNode,unordered_map<char,list<char>>&adj,vector<bool>&vis){
        vis[startNode] = true;
        
        for(auto neigh:adj[startNode]){
            if(!vis[neigh]){
                DFS(neigh,adj,vis);
            }
        }
    }
    
    int isCircle(vector<string> &arr) {
        unordered_map<char,list<char>>adj;
        vector<int>indegree(26,0);
        vector<int>outdegree(26,0);
        
        for(string s:arr){
            int start = s[0] - 'a' ;
            int end = s.back() - 'a';
            
            outdegree[start]++;
            indegree[end]++;
            
            adj[start].push_back(end);
        }
        
        for(int i=0;i<26;i++){
            if(indegree[i] != outdegree[i]){
                return 0;
            }
        }
        
        int startNode = -1;
        for(int i=0;i<26;i++){
            if(outdegree[i] > 0){
                startNode = i;
                break;
            }
        }
        
        vector<bool>vis(26,false);
        DFS(startNode,adj,vis);
        
        for(int i=0;i<26;i++){
            if(vis[i] == false && outdegree[i] > 0){
                return 0;
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends