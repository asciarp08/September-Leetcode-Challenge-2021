/**
Time = O((2^n) * (26*n)), n = arr.size();
Sapce = O(26)
**/

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        
        int ans = 0;
        
        for(int i = 0; i<(1<<n); i++){
            vector<bool>vis(26,0);
            string s = "";
            bool stop = 0;
            for(int j = 0;j<n; j++){
                if(i&(1<<j)){
                    for(auto c:arr[j]){
                        if(vis[c-'a']){
                            stop = 1;
                            break;
                        }
                        vis[c-'a'] = 1;
                        
                    }
                    if(stop)continue;
                    s+=arr[j];
                    ans = max(ans, (int)s.size());
                }
            }
        }
        return ans;
    }
};
