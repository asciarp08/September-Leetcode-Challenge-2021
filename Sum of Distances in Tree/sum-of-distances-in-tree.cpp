/**
Time = O(n)
Spacce = O(n)
**/

class Solution {
private: 
    vector<int> ans, count;
    
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        ans.resize(n, 0);
        count.resize(n,1);
        
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        dfs(adj, 0, -1);
        dfsFinal(adj, 0, -1);
        return ans;
    }
    
    void dfs(vector<vector<int>>& adj, int root, int prev){
        for(auto child:adj[root]){
            if(child==prev)continue;
            dfs(adj, child, root);
            count[root]+=count[child];
            ans[root]+=ans[child]+count[child];
        }
    }
    
    void dfsFinal(vector<vector<int>>& adj, int root, int prev){
        for(auto child:adj[root]){
            if(child==prev)continue;
            ans[child] = ans[root]-count[child]+(count.size()-count[child]);
            dfsFinal(adj, child, root);
        }
    }
};
