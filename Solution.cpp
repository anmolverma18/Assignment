class Solution {
public:
    void dfs(vector<int> adj[],int i,vector<bool>&vis){   //dfs
        for(auto k : adj[i]){
            if(!vis[k]){
                vis[k]=true;
                dfs(adj,k,vis);
            }
        }
    }
    int driverfunction(int n, vector<vector<int>>& v) { //used to check the total no of components
        if(v.size()<n-1)
        {
            return -1;
        }
        vector<int> adj[n];
        vector<bool>vis(n,false);
        int c=0;
        for(int i=0;i<v.size();i++){
            adj[v[i][0]].push_back(v[i][1]);
            adj[v[i][1]].push_back(v[i][0]);
        }
        for(int i=0;i<n;i++){
              if(!vis[i]){
                  vis[i]=true;
                  c++;
                  dfs(adj,i,vis);
              }
        }
        return c-1;
    }
};
