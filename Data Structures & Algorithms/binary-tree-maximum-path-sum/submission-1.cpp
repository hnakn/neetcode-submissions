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
    int result = INT_MIN;

    int maxpathsum(TreeNode* root)
    {
        if(!root) return 0;
        int left = maxpathsum(root->left);
        int right = maxpathsum(root->right);
        result = max(result, left+right+root->val);
        return root->val + max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        maxpathsum(root);
        return result;
    }


};
