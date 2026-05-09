class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(string s : strs) 
        {
            int n = s.size();
            result += to_string(n)+'#'+s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0;
        while(i<s.size())
        {
            string num="";
            while(s[i]>='0' && s[i]<='9')
            {
                num+=s[i];
                i++;
            }
            int n = stoi(num);
            i++;
            string curr = "";
            for(int j=0;j<n;j++)
            {
                curr += s[i];
                i++;
            }
            result.push_back(curr);
        }    
        return result;
    }
};
