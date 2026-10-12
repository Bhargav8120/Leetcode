class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        int n = image.size();
        int m = image[0].size();

        int originalColor = image[sr][sc];

        if(originalColor==newColor) return image;

        queue<pair<int, int>> q;

        q.push({sr, sc});

        image[sr][sc] = newColor;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto cell = q.front();
            q.pop();

            int row = cell.first;
            int col = cell.second;

            for(int i=0;i<4;i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==originalColor){

                    image[nr][nc]=newColor;

                    q.push({nr,nc});
                }
            }
        }

        return image;
    }

};
