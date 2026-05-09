class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.size()-1;
        if(s.empty()) return true;
        while(left<=right)
        {
            while(!isalnum(s[left]) && left<right) left++;
            while(!isalnum(s[right]) && left<right) right--;
            if(toupper(s[left])==toupper(s[right]))
            {
                left++;
                right--;
            }
            else return false;
        }    
        return true;    
    }
};
