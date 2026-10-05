class Solution {
public:
   class Disjoint{
    public:

    vector<int>parent,rank;

    Disjoint(int n ){
        parent.resize(n+1);
        rank.resize(n+1,0);

        for( int i =0;i<=n;i++ ){
            parent[i]=i;
        }

    }

    int  findParent( int u){
        if( parent[u]==u)return u;

        return parent[u]=findParent(parent[u]);
    }

    void unionByRank( int u, int v){
        int ult_u  = findParent(u);
        int ult_v =  findParent(v);

        if( ult_u==ult_v)return ;

        if( rank[ult_u] > rank[ult_v]){
            parent[ult_v] =ult_u;
        }else if( rank[ult_u] < rank[ult_v]){
            parent[ult_u] =ult_v;
        }else{
            parent[ult_u] =ult_v;
            rank[ult_v]++;
        }

        return;
    }
   };
    bool validTree(int n, vector<vector<int>>& edges) {
         Disjoint* d =new Disjoint(n) ;

         for( auto &edge :edges){
            int u = edge[0];
            int v =edge[1];
            
            int ult_u= d->findParent(u);
            int ult_v =d->findParent(v);

            if( ult_u == ult_v) return false;
            
            d->unionByRank(u,v);

         }
          int count=0;
         for( int i =0;i<n;i++){
           if( d->findParent(i) == i) count++;
         }

         return count==1;

    }
};
