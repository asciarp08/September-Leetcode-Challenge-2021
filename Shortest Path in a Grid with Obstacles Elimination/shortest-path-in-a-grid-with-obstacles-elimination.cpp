/**
Time = O(m*n*k)
Space = O(m*n)
**/
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> obs(m,vector<int>(n,INT_MAX));
        using ti = tuple<int,int,int>;
        
        queue<ti>q ; //x,y,curObs
        q.push({0,0,0});
        int dis = 0;
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y, curObs] = q.front(); q.pop();
                if(x==m-1 && y==n-1)
                    return dis;
                
                for(int i = 0; i<4; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n){
                        
                        if(curObs+grid[nx][ny]>k || obs[nx][ny]<=curObs+grid[nx][ny])continue;
                        q.push({nx,ny, curObs+grid[nx][ny]});
                        obs[nx][ny] = curObs+grid[nx][ny];
                        
                    }
                }
                
            }
            dis++;
        }
        
        return -1;
    }
};
