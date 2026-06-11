struct TrieNode {
    unordered_map<char,TrieNode*> mp;
    bool end;
    TrieNode()
    {
        this->end = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        TrieNode* x = new TrieNode();
        root = x;
    }
    
    void addWord(string word) {
        TrieNode* temp = root;
        for(char c : word)
        {
            if(temp->mp.count(c)==0) temp->mp[c]=new TrieNode();
            temp = temp->mp[c];
        }
        temp->end=true;
    }
    bool recursive_search(string word, TrieNode* root, int index)
    {
            if(index==word.size()) return root->end;
            if(word[index]=='.')
            {
                if(root->mp.empty()) return false;
                for(auto& it : root->mp)
                {
                    if(recursive_search(word, it.second,index+1))
                    {
                        return true;
                    }
                }
            }
            else if(root->mp.count(word[index])) return recursive_search(word,root->mp[word[index]],index+1);
            else return false;
        return root->end;
    }
    bool search(string word) {
        return recursive_search(word,root,0);
    }
};
