
/**
Approach 1:

Time = O(n)
Space = O(n)
**/

class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        if(n==1 || n==2)return 1;
        vector<int>t(n+1);
        t[0] = 0;
        t[1] = 1;
        t[2] = 1;
        
        for(int i = 3; i<=n;i++){
            t[i] = t[i-1]+t[i-2]+t[i-3];
        }
        return t[n];
    }
};

/**
Approach 2:
Time = O(n)
Space = O(1)
**/

class Solution {
public:
    int tribonacci(int n) {
        if(n==0 || n==1)return n;
        int first = 0; //T[0], T[i-3]
        int second = 1;//T[1], T[i-2]
        int third = 1; //T[2], T[i-1]
        // 1,2,3,4,5
        for(int i = 3; i<=n; i++){
            int cur = first+second+third;
            first = second;
            second = third;
            third = cur;
        }
        return third;
    }
};
