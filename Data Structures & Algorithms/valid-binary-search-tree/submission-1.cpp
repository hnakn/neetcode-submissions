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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool left=isValidBST(root->left);
        bool right=isValidBST(root->right);
        if((!root->left || root->left->val<root->val) && (!root->right || root->right->val>root->val) && left && right) return true;
        else return false;
           
    }
};
