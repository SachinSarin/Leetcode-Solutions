/*
APPLICATION OF CATALAN NUMBER
THIS IS THE METHOD 1 THAT IS NOT A EFFCIENT METHOD AND GIVE TLE FOR LARGE OUTPUTS
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 19
Accepted
389,390
Submissions
698,810
*/
class Solution {
public:
    int numTrees(int n) {
        //apply the catalan number
        if(n<=1)
        {
            return 1;
            
        }
        
        int res = 0;
        for(int i =  0; i < n; i++)
        {
            res += numTrees(i)*numTrees(n-i-1);
        }
        
        return res;
        
        
    }
};
