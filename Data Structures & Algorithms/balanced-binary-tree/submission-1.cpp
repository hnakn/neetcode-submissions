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
    int isb(TreeNode* root, int *flag)
    {
        if(root==nullptr) return 0;
        int left = isb(root->left,flag);
        int right = isb(root->right,flag);
        if(abs(left-right)>1) *flag=1;
        return 1+max(left,right); 
    }
    bool isBalanced(TreeNode* root) {
        int result = 0;
        isb(root, &result);
        if(result==0) return true;
        else return false;                
    }
};
