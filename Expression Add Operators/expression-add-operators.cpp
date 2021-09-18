/**
Time = O(4^n) , n= num.size()
Space = O(n)
**/
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        recursion(ans, num, target, "", 0, 0, 0 );
        return ans;
    }
    
    void recursion(vector<string>& ans, const string& num, const int& target, string expression, int idx, int prevNum, long long curTotal){
        int n = num.size();
        if(idx==n){
            if(curTotal==target){
                ans.push_back(expression);
            }
            return;
        }
        string curNumStr = "";
        long long curNum = 0;
        for(int i = idx; i<n; i++){
            if(i>idx && num[idx]=='0')break;
            curNumStr+=num[i];
            curNum = curNum*10+(num[i]-'0');
            // 2345
            if(idx==0){
                recursion(ans, num, target, expression+curNumStr, i+1, curNum, curTotal+curNum);
            }
            else{
                recursion(ans, num, target, expression+"+"+curNumStr, i+1, curNum, curTotal+curNum);
                recursion(ans, num, target, expression+"-"+curNumStr, i+1, -curNum, curTotal-curNum);
                recursion(ans, num, target, expression+"*"+curNumStr, i+1, prevNum*curNum, curTotal-prevNum+prevNum*curNum);
            }
        }
    }
    
};
