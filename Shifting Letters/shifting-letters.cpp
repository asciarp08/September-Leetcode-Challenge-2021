/**
Time = O(n)
Space = O(1)
**/
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        int curShifts = 0;
        
        for(int i = n-1; i>=0; i--){
            curShifts+=shifts[i]%26;
            s[i] = (s[i]-'a'+curShifts)%26+'a';
        }
        return s;
    }
};
