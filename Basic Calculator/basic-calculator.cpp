/**
Time = O(n)
Space = O(n)
**/

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int total = 0;
        stack<int> signs;
        signs.push(1);
        signs.push(1);
        
        for(int i = 0; i<n; i++){
            if(s[i]>='0' && s[i]<='9'){
                int num = 0;
                
                while(i<n && s[i]>='0' && s[i]<='9'){
                    num*=10;
                    num+=(s[i]-'0');
                    i++;
                }
                total+=signs.top()*num;
                signs.pop();
                i--;
            }
            else if(s[i]=='(' || s[i]=='+' || s[i]=='-'){
                signs.push(signs.top()*(s[i]=='-'?-1:1));
            }
            else if(s[i]==')'){
                signs.pop();
            }
        }
        return total;
    }
};
