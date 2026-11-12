class Solution{
public:
    bool canFinish(int N, vector<vector<int>> arr) {

        int row = arr.size();
        
        vector<vector<int>> adjList(N);
        vector<int> inDegree(N,0);

        for(int i=0;i<row;i++){
            int u = arr[i][0];
            int v = arr[i][1];

            adjList[v].push_back(u);
            inDegree[u]++;
        }

        queue<int> q;

        for(int i=0;i<N;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        vector<int> temp;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            temp.push_back(node);

            for(auto it : adjList[node]){
                inDegree[it]--;

                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(temp.size()<N) return false;

        return true;     
    }
};