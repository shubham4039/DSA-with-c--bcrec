class Solution {
public:
    bool isvalid(char c){
        if(c>='a' && c<='z') return true;
        if(c>='A' && c<='Z') return true;
        if(c>='0' && c<='9') return true;
        return false;
    }
    bool isPalindrome(string s) {
        int low=0, high=s.size()-1;
        while(low<high){
            while(low<high && !isvalid(s[low])) low++;
            while(low<high && !isvalid(s[high])) high--;
            if( tolower(s[low]) != tolower(s[high])) return false;
            low++, high--;
        }
        return true;
    }
};