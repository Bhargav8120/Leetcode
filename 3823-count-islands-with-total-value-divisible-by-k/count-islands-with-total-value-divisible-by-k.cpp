class Solution {
public:
    long long bfs(int n , int m , vector<vector<int>> &grid , vector<vector<int>> &vis ,long long &sum){

        int rows = grid.size();
        int cols = grid[0].size();

        vis[n][m]=1;
        sum+=grid[n][m];

        queue<pair<int,int>> q;

        q.push({n,m});

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<rows && ncol>=0 && ncol<cols && grid[nrow][ncol]!=0 && !vis[nrow][ncol]){
                    sum+=grid[nrow][ncol];
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        cout<<sum<<" ";
        return sum;
    }


    int countIslands(vector<vector<int>>& grid, int k) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> vis(rows,vector<int>(cols,0));

        long long count=0;


        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]!=0 && !vis[i][j]){
                    long long sum=0;
                    if(bfs(i,j,grid,vis,sum)%k==0){
                        count++;
                    }
                }
            }
        }  

        return count;        
    }
};