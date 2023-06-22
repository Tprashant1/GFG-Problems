#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def lemonadeChange(self, N, bills):
        # Code here
        b5=0
        b10=0
        b20=0
        for i in range(N):
            if(bills[i]==5):
                b5 += 1
            elif(bills[i]==10):
                b10 += 1
                if(b5==0):
                    return False
                else:
                    b5 -= 1
            else:
                b20 += 1
                if(b5>=1 and b10>=1):
                    b5 -= 1
                    b10 -= 1
                elif(b5>2):
                    b5 -= 3
                else:
                    return False
        return True
                    
                
            
            
            

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N = int(input())
        bills = list(map(int, input().split()))
        ob = Solution()
        res = ob.lemonadeChange(N, bills)
        print(res)
# } Driver Code Ends