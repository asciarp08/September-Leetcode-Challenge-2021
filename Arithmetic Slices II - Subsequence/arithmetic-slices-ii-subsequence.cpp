/**
Time = O(n^2)
Space = O(n^2)
**/


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        vector<unordered_map<int,int>>diffCountMap(n);
        int res = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if((long)nums[j]-(long)nums[i]>INT_MAX||(long)nums[j]-(long)nums[i]<INT_MIN)continue;
                int diff = nums[j]-nums[i];
                
                if(diffCountMap[j].count(diff)){
                    diffCountMap[i][diff]+=diffCountMap[j][diff];
                    res+=diffCountMap[j][diff];
                }
                
                diffCountMap[i][diff]++;
            }
        }
        return res;
    }
};
