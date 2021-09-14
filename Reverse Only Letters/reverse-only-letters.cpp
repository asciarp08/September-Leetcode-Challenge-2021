/**
Time = O(n)
Space = O(1)
**/ 
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        
        while(l<r){
            while(l<r && !isChar(s[l]))l++;
            while(l<r && !isChar(s[r]))r--;
            swap(s[l++], s[r--]);
        }
        return s;
    }
    
    bool isChar(char c){
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))
            return true;
        return false;
    }
};
