/**
Time = O(n^2)
Space = O(1)
**/

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        
        int rowSwap = 0, colSwap = 0, rowCount = 0, colCount = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(board[0][0]^board[i][0]^board[0][j]^board[i][j])
                    return -1;
            }
        }
        
        for(int i = 0; i<n; i++){
            rowSwap+=board[i][0]==i%2;
            colSwap+=board[0][i]==i%2;
            rowCount+=board[0][i];
            colCount+=board[i][0];
        }
        
        if((rowCount!=n/2 && rowCount!=(n+1)/2) || (colCount!=n/2 && colCount!=(n+1)/2))return -1;
        
        if(n%2==0){
            rowSwap = min(rowSwap, n-rowSwap);
            colSwap = min(colSwap, n-colSwap);
        }
        else{
            if(rowSwap%2){
                rowSwap = n-rowSwap;
                
            }
            if(colSwap%2)
                colSwap = n-colSwap;
        }
        
        return (rowSwap+colSwap)/2;
    }
};
