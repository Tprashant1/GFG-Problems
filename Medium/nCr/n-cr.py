#User function Template for python3

class Solution:
    def nCr(self, n, r):
        # code here
        nth=1
        rth=1
        nrth=1
        for i in range(1,n+1):
            nth *= i
        for i in range(1,r+1):
            rth *= i
        for i in range(1,(n-r)+1):
            nrth *= i
        return ((nth)//(rth*nrth))%(10**9+7)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, r = [int(x) for x in input().split()]
        
        ob = Solution()
        print(ob.nCr(n, r))
# } Driver Code Ends