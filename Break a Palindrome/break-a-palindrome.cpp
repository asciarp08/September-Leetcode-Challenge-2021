/**
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1)
            return "";
        
        for(int i = 0; i<n; i++){
            if(n%2 && i==n/2)continue;
            if(palindrome[i]!='a'){
                palindrome[i] = 'a';
                break;
            }
            else if(i==n-1){
                palindrome[i] = 'b';
            }
        }
        return palindrome;
    }
};
