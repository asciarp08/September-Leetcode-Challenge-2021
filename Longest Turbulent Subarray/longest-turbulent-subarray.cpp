/**
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int curLen = 1;
        int maxLen = 1;
        int lastSign = -1;
        
        for(int i = 1; i<n; i++){
            if(arr[i-1]<arr[i]){
                if(lastSign==0){
                    curLen = 2;
                }
                else{
                    curLen++;
                }
                lastSign = 0;
            }
            else if(arr[i-1]>arr[i]){
                if(lastSign==1){
                    curLen = 2;
                    
                }
                else{
                    curLen++;
                }
                lastSign = 1;
            }
            else{
                curLen = 1;
                lastSign = -1;
            }
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};
