/**
Time = O(n*2^n)
Space = O(2^n)
**/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = 0;
        for(auto num:nums){
            sum+=num;
        }
        if(sum%k)
            return false;
        int target = sum/k;
        
        vector<int> dp((1<<n), -1);
        dp[0] = 0;
        
        for(int itr = 0; itr<(1<<n); itr++){
            if(dp[itr]==-1)continue;
            for(int i = 0; i<n; i++){
                if(!(itr&(1<<i)) && dp[itr]+nums[i]<=target){
                    dp[itr|(1<<i)] = (dp[itr]+nums[i])%target;
                }
            }
        }
        return dp[(1<<n)-1]==0?1:0;
    }
};
