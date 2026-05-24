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
    bool validbst(TreeNode* root, int mini, int maxi)
    {
        if(!root) return true;
        bool flag = false;
        if(root->val>mini && root->val<maxi) flag=true;
        bool left = validbst(root->left, mini, root->val);
        bool right = validbst(root->right, root->val, maxi);
        return flag && left && right;
    }
    bool isValidBST(TreeNode* root) {
        return validbst(root,INT_MIN, INT_MAX);       
           
    }
};
