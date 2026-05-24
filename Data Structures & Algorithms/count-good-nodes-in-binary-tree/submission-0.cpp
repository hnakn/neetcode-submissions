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
    void findgood(TreeNode* root, int *result, int maxi)
    {
        if(!root) return;
        if(root->val>=maxi) (*result)++;
        findgood(root->left, result,max(maxi,root->val));
        findgood(root->right, result,max(maxi,root->val));
    }
    int goodNodes(TreeNode* root) {
        int result = 0;
        findgood(root, &result,root->val);
        return result;
    }
};
