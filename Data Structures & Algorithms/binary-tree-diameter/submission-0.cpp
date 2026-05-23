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
    int findD(TreeNode* root,int *maxi)
    {
        if(root==nullptr) return 0;
        int left = findD(root->left,maxi);
        int right = findD(root->right,maxi);
        *maxi = max(*maxi, left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        findD(root, &result);
        return result;
    }
};
