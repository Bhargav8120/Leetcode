class Solution {
   public:
    void bfs(int node ,vector<int> &vis,vector<vector<int>> &list){
        vis[node]=1;

        queue<int> q;

        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : list[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }

        return;
    }
    int findCircleNum(vector<vector<int>> adj) {
        int n = adj.size();

        vector<int> vis(n,0);

        vector<vector<int>> list(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == 1 && i != j) {
                    list[i].push_back(j);
                }
            }
        }

        int count = 0;

        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                count++;
                vis[i]=1;
                bfs(i,vis,list);
            }
        }

        return count;
    }
};
