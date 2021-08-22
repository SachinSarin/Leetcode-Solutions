/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
Accepted
478,638
Submissions
927,519
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void findpathsum(TreeNode* root , int target , vector<vector<int>> &result , vector<int> v)
    {
        if(root==NULL)
        {
            return;
        }
        v.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&target-root->val==0)
        {
            result.push_back(v);
            v.clear();
            return;
        }
        
       
        findpathsum(root->left,target-root->val,result,v);
        findpathsum(root->right,target-root->val,result,v);
        v.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        
        vector<vector<int>> result;
        vector<int> v;
        findpathsum(root,target,result,v);
        
        return result;
        
        
    }
};
