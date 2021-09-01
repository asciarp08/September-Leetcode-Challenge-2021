/**
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        
        for(int i = 0; i<n;i++){
            if(nums[i]==-1)continue;
            
            int curLen = 0;
            int j = i;
            while(nums[j]!=-1){
                int tmpIdx = j;
                j = nums[j];
                nums[tmpIdx] = -1;
                curLen++;
            }
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};
