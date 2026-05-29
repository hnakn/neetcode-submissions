/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node* node, unordered_map<int,Node*>& mp)
    {   
        if(node==nullptr) return nullptr;
        Node* x = nullptr;
        if(mp.count(node->val)==0)
        {
            x = new Node(node->val);
            mp[node->val] = x;
        }
        else
        {
            return mp[node->val];
        }
        for(Node* temp : node->neighbors)
        {            
            Node* res = clone(temp,mp);
            if(res) x->neighbors.push_back(res);
        }
        return x;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> mp;
        
        return clone(node, mp);
    }
};
