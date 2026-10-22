class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
           int m = grid.size();
    int n = grid[0].size();
        queue<pair<int, int>>q;
        int fresh =0;
        int time =0;

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 2){
               q.push({i, j});
            }
            else if(grid[i][j] == 1){
                fresh++;
            }
        }
       }
       if(fresh ==0)
       {
        return 0;
       }
       int dr[] = {-1, 1, 0, 0};
       int dc[] = {0, 0, -1, 1};
       int count =0;
       while(!q.empty() && count<fresh){ //loop stops as soon as all fresh oranges have been rotten
        int size = q.size();
        time++;
        for(int i=0;i<size;i++){
            auto[r, c] = q.front();
            q.pop();
            for(int j=0;j<4;j++){
                int nr = r+dr[j];
                int nc = c+dc[j];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1){
                    grid[nr][nc] =2;
                    count++;
                    q.push({nr, nc});
                }
            }
        }


       }
     return ( fresh == count)? time:-1;

    }
};