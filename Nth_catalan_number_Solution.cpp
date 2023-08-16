******************************************************* Question ***********************************************************
Given a number N. The task is to find the Nth catalan number.
The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

Catalan Number for N is equal to the number of expressions containing N pairs of paranthesis that are correct matched, i.e., for each of the N '(' there exist N ')' on there right and vice versa.

Since answer can be huge return answer modulo 1e9+7.

Note: Positions start from 0 as shown above.

Example 1:

Input:
N = 5
Output: 42
Example 2:

Input:
N = 4
Output: 14
Your Task:
Complete findCatalan() function that takes n as an argument and returns the Nth Catalan number. The output is printed by the driver code.

Expected Time Complexity: O(N^2).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 103

******************************************************* Solution ***********************************************************
  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
   long ans=1l;
        long mod=(long)1e9+7;
        for(int i=n+1;i<=2*n;i++){
            ans*=i;
            ans%=mod;
        }
        for(int i=1;i<=n+1;i++){
            ans = (ans*modInverse(i))%mod;
        }
        return (int)ans;
    }
    
    
    // Extended Euclidean Algorithm
    static int modInverse(int num2){
        int num1=(int)1e9+7;
        
        int a=num1,b=num2; 
        int t1=0,t2=1;
        while(b!=0){
            int q=a/b;
            int r=a%b;
            
            int t=t1-t2*q;
            
            a=b;
            b=r;
            t1=t2;
            t2=t;
        }
        
        return (t1+num1)%num1;
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends


    
