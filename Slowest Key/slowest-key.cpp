/**
Time = O(n)
Space = O(1)
**/
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        
        char key = keysPressed[0];
        int maxTime = releaseTimes[0];
        
        for(int i = 1; i<n; i++){
            int curTime = releaseTimes[i]-releaseTimes[i-1];
            if(curTime>maxTime){
                key = keysPressed[i];
                maxTime = curTime;
            }
            else if(maxTime==curTime){
                key = max(key, keysPressed[i]);
            }
        }
        return key;
    }
};
