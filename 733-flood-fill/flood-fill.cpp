class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {

        vector<vector<int>> newImage(image.begin(), image.end());

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        int rows = image.size();
        int cols = image[0].size();

        int originalColor = image[sr][sc];

        newImage[sr][sc]=newColor;

        queue<pair<int,int>> q;

        q.push({sr,sc});

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<rows && ncol>=0 && ncol<cols && newImage[nrow][ncol]==originalColor && newImage[nrow][ncol]!=newColor){
                    newImage[nrow][ncol]=newColor;
                    q.push({nrow,ncol});
                }
            }
        }

        return newImage;
        
    }
};
