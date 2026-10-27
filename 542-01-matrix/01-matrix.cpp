class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> grid){

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> vis(rows,vector<int>(cols,0));

        vector<vector<int>> dist(rows,vector<int>(cols,0));

         queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){

                    vis[i][j]=1;

                    dist[i][j]=0;

                    q.push({{i,j},0});
                }
            }
        }


        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};


        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int r = node.first.first;
            int c = node.first.second;
            int d = node.second;

            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<rows && ncol>=0 && ncol<cols && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    dist[nrow][ncol]=d+1;
                    q.push({{nrow,ncol},d+1});
                }
            }
        }
        return dist;
   
    }
};