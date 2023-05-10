class Solution {
public:
    void dfs(vector<int> adj[],int i,vector<int>&vis){
        for(auto k : adj[i]){
            if(!vis[k]){
                vis[k]=1;
                dfs(adj,k,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& v) {
        if(v.size()<n-1)
        {
            return -1;
        }
        vector<int> adj[n];
        vector<int>vis(n,0);
        int c=0;
        for(auto i:v){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
              if(!vis[i]){
                  vis[i]=1;
                  c++;
                  dfs(adj,i,vis);
              }
        }
        return c-1;
    }
};
