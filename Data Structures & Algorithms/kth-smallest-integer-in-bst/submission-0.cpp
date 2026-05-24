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
    int count = 0, result = 0;
    void kthsmallest(TreeNode* root, int k) {
        if(!root) return;
       kthsmallest(root->left,k);
       count++;
       if(count==k) result = root->val;
       kthsmallest(root->right, k);
       return;
    }
    int kthSmallest(TreeNode* root, int k) {
       kthsmallest(root, k);
       return result;
    }
};
