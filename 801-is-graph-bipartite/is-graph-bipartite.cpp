class Solution{
public:

    bool bfs(int node , vector<vector<int>> &list, vector<int> &color){
        
        queue<int> q;

        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : list[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> edges)  {

        int V = edges.size();

        vector<int> color(V,-1);

        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!bfs(i,edges,color)){
                    return false;
                }
            }
        }

        return true;
        
    }
};
