//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int>temp;
	    temp = nums;
	    sort(temp.begin(),temp.end());
	    unordered_map<int,int>mp;
	    int ans = 0;
	    for(int i=0;i<nums.size();i++){
	        mp[nums[i]] = i;
	    }
	    
	    for(int i=0;i<nums.size();i++){
	        if(nums[i] != temp[i]){
	            int index = mp[temp[i]];
	            mp[nums[i]] = index;
	            mp[nums[index]] = i ;
	            swap(nums[i],nums[index]);
	            ans++;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends