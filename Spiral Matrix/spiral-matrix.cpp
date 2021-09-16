/**
Time = O(m*n)
Space = O(1)
**/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;
        
        int startRow = 0, startCol = 0, endRow = m, endCol = n;
        
        vector<int> spiralOrder;
        
        while(startRow<=endRow && startCol <= endCol){
            //go right
            for(int j = startCol; j<=endCol; j++){
                spiralOrder.push_back(matrix[startRow][j]);
            }
            startRow++;
            
            //go down
            for(int i = startRow; i<=endRow; i++){
                spiralOrder.push_back(matrix[i][endCol]);
            }
            endCol--;
            
            //go left
            if(startRow<=endRow){
                for(int j = endCol; j>=startCol; j--){
                    spiralOrder.push_back(matrix[endRow][j]);
                }
            }
            endRow--;
            
            //go up
            if(startCol<=endCol){
                for(int i = endRow; i>=startRow; i--){
                    spiralOrder.push_back(matrix[i][startCol]);
                }
            }
            startCol++;
        }
        return spiralOrder;
    }
};
