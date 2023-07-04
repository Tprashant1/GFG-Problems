#User function Template for python3

class Solution:
    def countSubArrayProductLessThanK(self, a, n, k):
        #Code here
        c = 0
        p = 1
        r = 0
        for i in range(n):
            p *= a[i]
            while p >= k and r <= i:
                p /= a[r]
                r += 1
            c += (i - r + 1)
        return c
            
        
    
    
    


#{ 
 # Driver Code Starts

#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n, k = [int(x) for x in input().strip().split()]
        arr = [int(x) for x in input().strip().split()]
        
        print(Solution().countSubArrayProductLessThanK(arr, n, k))

        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends