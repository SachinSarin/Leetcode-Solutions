/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690
Accepted
219,663
Submissions
503,336
*/
class Solution {
public:
    int nthUglyNumber(int n) {
       
        int dp[n+1];
        
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        dp[1] = 1;
        for(int i = 2; i <=n; i++)
        {
            int f1 = 2*dp[p2];
            int f2 = 3*dp[p3];
            int f3 = 5*dp[p5];
            
            int mini = min(f1,min(f2,f3));
            dp[i] = mini;
            if(mini==f1)
            {
                p2++;
            }
            if(mini==f2)
            {
                p3++;    
            }
            if(mini==f3)
            {
                p5++;
            }
        }
        return dp[n];
    }
};
