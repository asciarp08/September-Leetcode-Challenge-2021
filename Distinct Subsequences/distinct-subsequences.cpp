/**
Time = O(m*n), m = s.size(), n = t.size()
Space = O(n)
**/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        vector<long> dp(n+1, 0);
        //i=0, j = 0 to m
        dp[0] = 1;
        
        //i,j-1  i-1,j-1
        
        for(int j = 1; j<=m; j++){
            //j = 2
            int prev = 1; //i-1,j-1
            for(int i = 1; i<=n; i++){
                int tmp = dp[i];
                
                if(s[j-1]==t[i-1]){
                    dp[i] = dp[i]+prev;
                }
                else{
                    dp[i] = dp[i]; // i,j-1
                }
                prev = tmp;
            }
            
        }
        return dp[n];
    }
};
