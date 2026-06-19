class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size()<num2.size()) swap(num1,num2);
        vector<int> result(num1.size()+num2.size(),0);

        for(int i=num2.size()-1;i>=0;i--)
        {
            for(int j=num1.size()-1;j>=0;j--)
            {
                int pos = i+j+1;
                int posnext = i+j;
                int sum =  result[pos] + ((num2[i]-'0')*(num1[j]-'0'));
                
                result[pos] = sum%10;
                result[posnext] += sum/10;
            }            
        }
        string s = "";
        int i=0;
        while(i<result.size() && result[i]==0) i++;
        for(;i<result.size();i++)
        {
            s += to_string(result[i]);
        }
        if(s.empty()) return {0};
        return s;
    }
};
