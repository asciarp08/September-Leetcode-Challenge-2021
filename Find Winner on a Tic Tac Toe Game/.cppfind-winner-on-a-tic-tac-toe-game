/**
Time = O(m), m = moves.size()
Space = O(n), n = size of the board, this case n = 3 
**/
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int m = moves.size();
        int n = 3;
        
        vector<int> row(n,0);
        vector<int> col(n,0);
        vector<int> diag(2,0);
        
        int score = 1;
        
        for(auto v:moves){
            int r = v[0];
            int c = v[1];
            
            row[r]+=score;
            col[c]+=score;
            if(r==c)diag[0]+=score;
            if(r==n-c-1)diag[1]+=score;
            
            if(abs(row[r])==n || abs(col[c])==n || abs(diag[0])==n || abs(diag[1])==n)
                return score==1?"A":"B";
            
            score = score==1?-1:1;
            
        }
        
        return m==9?"Draw":"Pending";
    }
};
