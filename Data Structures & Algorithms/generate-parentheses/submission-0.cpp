class Solution {
public:
    void bt(int a, int b,string curr, vector<string>& result)
    {
        if(a==0 && b==0) 
        {
            result.push_back(curr);
            return;
        }
        if(a<0 || b<0) return;
        if(a>b) return;
        bt(a-1,b,curr+"(",result);
        bt(a,b-1,curr+")", result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        bt(n,n,"",result);
        return result;
    }
};
