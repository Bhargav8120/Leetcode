class Solution {
   public:
    void bfs(int node , vector<vector<int>> &adj , vector<int> &vis){
        vis[node]=1;

        queue<int> q;

        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int adjNode=0 ; adjNode<adj.size();adjNode++){
                if(adj[node][adjNode]==1 && !vis[adjNode]){
                    vis[adjNode]=1;
                    q.push(adjNode);
                }
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>> adj) {

        int rows = adj.size();

        vector<int> vis(rows,0);

        int count=0;

        for (int i = 0; i < rows; i++) {
            if(!vis[i]){
                count++;
                bfs(i,adj,vis);
            }
        }

        return count;

    }
};
