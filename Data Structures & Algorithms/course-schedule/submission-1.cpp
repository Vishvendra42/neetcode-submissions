class Solution {
public:
    bool dfs( int node , unordered_map<int,vector<int>>&mp , vector<int>&vis){
        vis[node]=1;//currently visiting

        for( auto  &it: mp[node]){
            if( vis[it]==0){
               if(dfs( it,mp,vis) ==false) return false;
                
            }else if( vis[it]==1){
                return false;
            }
        }

        vis[node]=2; //visited

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;

        for( auto &it : prerequisites){
            int u =it[0];
            int v= it[1];

            // adding v->u edge
            mp[v].push_back(u);
        }
         
         vector<int>vis(numCourses , 0);
        for( auto & it: mp){
            int node= it.first;

            if( vis[node]==0){
                if( dfs( node,mp,vis)==false)return false;
            }
        }
        return true;


    }
};
