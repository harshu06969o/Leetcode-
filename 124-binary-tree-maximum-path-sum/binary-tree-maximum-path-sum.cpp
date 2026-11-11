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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        calcMaxSum( root , ans);
         return ans ;
        
        
    }
     int calcMaxSum( TreeNode* root , int& ans ){
        if( !root) return 0;
        int lSum = calcMaxSum( root->left, ans );
        int rSum = calcMaxSum( root->right, ans);
         int maxSum = max( lSum , max( rSum, lSum+rSum));
         ans = max(  ans , root->val + max( 0, maxSum));
          return  root->val+ max(  0, max( lSum , rSum));
     }
};