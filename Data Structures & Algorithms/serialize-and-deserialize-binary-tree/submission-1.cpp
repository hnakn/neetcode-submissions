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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string result = "";
        if(root) q.push(root);
        while(!q.empty())
        {
            TreeNode* v = q.front();
            if(!v) 
            {
                result += "1001";
                result += "#";
                q.pop();
                continue;
            }
            else
            {
                result += to_string(v->val);
                result += "#";
            }
            q.push(v->left);
            q.push(v->right);
            q.pop();
        }
        return result;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        queue<TreeNode*> q;
        int count = 0;
        for(int i=0;i<data.size();i++)
        {
            if(data[i]=='#') continue;
            string curr = "";
            while(data[i]!='#')
            {
                curr += data[i];
                i++;
            }
            int x = stoi(curr);
            TreeNode* temp = new TreeNode(x);
            if(x==1001) temp=nullptr; 
            if(!root) 
            {
                root = temp;
                if(temp) q.push(temp);
            }
            else
            {
                TreeNode* a = q.front();
                if(count==0)
                {
                    a->left = temp;
                    if(temp) q.push(temp);
                    count++;
                }
                else if(count==1)
                {
                    a->right = temp;
                    if(temp) q.push(temp);
                    q.pop();
                    count=0;
                }
            }
        }
        return root;
    }
};
