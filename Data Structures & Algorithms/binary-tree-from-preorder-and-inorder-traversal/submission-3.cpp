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
    TreeNode* sol(vector<int>& preorder, vector<int>& inorder,int start, int end, int rootind, unordered_map<int,int>& mp)
    {
        TreeNode* root = new TreeNode(preorder[rootind]);
        int mid = mp[root->val];
        if(start<mid)
        {
            root->left = sol(preorder, inorder, start, mid-1, rootind+1, mp);
        }        
        if(mid<end) 
        {
            root->right = sol(preorder, inorder, mid+1,end, rootind+mid-start+1, mp);
            rootind++;
        }
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }    
        TreeNode* root = new TreeNode(preorder[0]);    
        return sol(preorder, inorder,0,inorder.size()-1,0,mp);
    }
};
