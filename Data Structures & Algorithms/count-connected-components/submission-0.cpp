class Solution {
public:
     void dfs( int node , vector<vector<int>>&adj ,vector<int>&vis){
        vis[node]=1;

        for( auto &it:adj[node]){
            if( !vis[it]){
                dfs( it ,adj,vis);
            }
        }
     }
    int countComponents(int n, vector<vector<int>>& edges) {
      vector<vector<int>> adj(n);
      for( auto &edge:edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
      }
      int count =0;
      vector<int>vis(n,0);
      for( int i =0;i<n;i++){

        if( !vis[i]){
            dfs(i,adj,vis);
            count++;
        }
      }
      return count;
    }
};
