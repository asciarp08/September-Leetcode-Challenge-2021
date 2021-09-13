/**
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<int,int> req;
        string b = "balloon";
        
        for(auto c:b){
            req[c]++;
        }
        
        unordered_map<int,int> cnt;
        
        for(auto c:text){
            if(req.count(c)){
                cnt[c]++;
            }
        }
        
        int numBalloons = INT_MAX;
        for(auto [c, freq]: req){
            numBalloons = min(numBalloons, cnt[c]/freq);
        }
        return numBalloons;
    }
};
