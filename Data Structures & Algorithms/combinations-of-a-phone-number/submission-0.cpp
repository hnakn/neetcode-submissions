class Solution {
public:
    vector<string> data = {
        "ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"
    };

    void bt(string digits, string curr, int index,vector<string>& result)
    {
        if(curr.size()==digits.size())
        {
            result.push_back(curr);
            return;
        }
        for(char c : data[(digits[index]-'0')-2])
        {
            curr.push_back(tolower(c));
            bt(digits,curr,index+1,result);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> result;
        bt(digits,"",0,result);
        return result;
        
    }
};
