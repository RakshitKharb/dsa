class Solution {
public:
    bool dfs(vector<vector<int>>&graph, int vis[],int node,int clr){
        vis[node]=clr;
        for(auto it:graph[node]){
            if(vis[it]==-1){
                if(dfs(graph,vis,it,!clr)==false)return false;
            }
           else if(vis[it]==clr) return false;
        }
        return true;
    } 
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int vis[n];
        for(int i=0;i<n;i++){
            vis[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(dfs(graph,vis,i,0)==false)return false;
            }
        }
        
        return true;
    }
};