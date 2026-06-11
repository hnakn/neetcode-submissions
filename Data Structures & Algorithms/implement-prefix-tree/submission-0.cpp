struct TrieNode {
    unordered_map<char,TrieNode*> mp;
    bool end;
    TrieNode() {
        this->end = false;
    }
};
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        TrieNode* x = new TrieNode();
        this->root = x;
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(char c : word)
        {
            if(temp->mp.count(c)==0) temp->mp[c] = new TrieNode();
            temp = temp->mp[c];
        }
        temp->end = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(char c : word)
        {
            if(!temp->mp.count(c)) return true;
            temp = temp->mp[c];
        }
        if(temp->end) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(char c : prefix)
        {
            if(!temp->mp.count(c)) return true;
            temp = temp->mp[c];
        }
        return true;
    }
};
