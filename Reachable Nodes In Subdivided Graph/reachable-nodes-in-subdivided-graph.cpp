/**
Time = O(e*loge), e = edges.size()
Space = O(e)
**/


class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int,unordered_map<int,int>> graph;
        
        for(auto v:edges){
            graph[v[0]][v[1]] = v[2];
            graph[v[1]][v[0]] = v[2];
        }
        
        int total = 0;
        
        priority_queue<pair<int,int>> movesLeftFromNode; //movesLeft, node
        movesLeftFromNode.push({maxMoves, 0});
        
        unordered_map<int,int> vis;
        
        while(!movesLeftFromNode.empty()){
            
            auto [movesLeft, node] = movesLeftFromNode.top(); movesLeftFromNode.pop();
            
            if(vis.count(node))continue;
            
            vis[node] = movesLeft;
            
            for(auto [neighbor, dist]: graph[node]){
                
                if(vis.count(neighbor))continue;
                
                int movesLeftFromNeighbor = movesLeft-dist-1;
                if(movesLeftFromNeighbor>=0){
                    movesLeftFromNode.push({movesLeftFromNeighbor, neighbor});
                }
            }
        }
        
        total = vis.size();
        
        for(auto v:edges){
            int x = v[0];
            int y = v[1];
            int cnt = v[2];
            int movesLeftX = 0, movesLeftY = 0;
            
            if(vis.count(x)){
                movesLeftX = vis[x];
            }
            if(vis.count(y)){
                movesLeftY = vis[y];
            }
            total+=min(movesLeftX+movesLeftY, cnt);
            
            
        }
        return total;
        
    }
};
