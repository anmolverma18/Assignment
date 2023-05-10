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
    int driverfunction(int n, vector<vector<int>>& connections) { //used to check the total no of components
        if(connections.size()<n-1)
        {
            return -1;
        }
        vector<int> adj[n];
        vector<bool>vis(n,false);
        int c=0;
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
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
