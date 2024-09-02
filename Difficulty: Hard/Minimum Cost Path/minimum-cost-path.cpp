//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0] = grid[0][0];
        
        int nrow[] = {0,0,-1,1};
        int ncol[] = {-1,1,0,0};
        
        while(!pq.empty()){
            int dis = pq.top().first ;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            for(int i=0;i<4;i++){
                int newrow = row + nrow[i];
                int newcol = col + ncol[i];
                
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < n){
                    if(dis + grid[newrow][newcol] < dist[newrow][newcol]){
                        dist[newrow][newcol] = dis + grid[newrow][newcol] ;
                        pq.push({dist[newrow][newcol],{newrow,newcol}});
                    }
                }
            }
        }
        return dist[n-1][n-1];
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends