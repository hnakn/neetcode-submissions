class Solution {
public:
    int sol(string text1, string text2, int i, int j)
    {
        if(i==text1.size() || j==text2.size()) return 0;
        int same=INT_MIN;
        if(text1[i]==text2[j]) same = 1 + sol(text1,text2,i+1,j+1);
        return max(same, max(sol(text1,text2,i+1,j),sol(text1,text2,i,j+1)));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return sol(text1,text2,0,0);
    }
};
